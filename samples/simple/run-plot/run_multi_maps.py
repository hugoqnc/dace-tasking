import os
import csv
import sys
import matplotlib.pyplot as plt
from matplotlib.transforms import Affine2D
from matplotlib.ticker import MultipleLocator, AutoMinorLocator
import numpy as np

# RUN PARAMETERS TO CHANGE __________________________________________________
threads = [1, 2, 3, 4, 5, 8, 12]
array_size = 100000
iterations = 10
heterogeneous = True
suffix = "_16maps_100k"
# ____________________________________________________________________________

# PLOT PARAMETERS TO CHANGE __________________________________________________
plot_markers = ['o', '^', 'd', 's']
optimizationNames = ["Original DaCe", "Tasking-Optimized", "Auto-Optimized", "Tasking + Auto-Optimized"]
# ____________________________________________________________________________

optimizations = ["", "--opt", "--autoopt", "--opt --autoopt"]
script = "multi_maps.py"
if heterogeneous:
    suffix += "_heterogeneous"
    script = "multi_maps_heterogeneous.py"

def optimizationName(opt):
    return optimizationNames[optimizations.index(opt)]

def run():
    with open('results/multi_maps'+suffix+'.csv', 'w') as csvfile:
        writer = csv.writer(csvfile, delimiter=',')
        writer.writerow(['optimizations', 'threads', 'array_size', 'exec_time', 'std_dev'])

        i = 1
        for t in threads:
            for opt in optimizations:
                res = os.popen(f'python ../{script} {array_size} {iterations} {t} {opt}')
                
                lines = res.read().split('\n')
                time = lines[-3].split(' ')[1]
                sd = lines[-2].split(' ')[1]
                writer.writerow([opt, t, array_size, time, sd])
                print(f'{i}/{len(threads)*len(optimizations)} — optimizations: {opt}, threads: {t}, exec_time: {time}, std_dev: {sd}')
                i += 1

def plot():
    with open('results/multi_maps'+suffix+'.csv', 'r') as csvfile:
        reader = csv.reader(csvfile, delimiter=',')
        next(reader)
        data = np.array(list(reader))
        # print(data)

    fig, ax = plt.subplots(figsize=(8, 6))
    all_threads = []
    for i in range(len(optimizations)):
        opt = optimizations[i]

        opt_data = data[data[:, 0] == opt]
        threads = opt_data[:, 1].astype(int)
        all_threads = threads
        time = opt_data[:, 3].astype(float)
        std_dev = opt_data[:, 4].astype(float)
        #ax.plot(threads, time, label = opt if opt!='' else 'none')

        trans = Affine2D().translate(0.08*i, 0.0) + ax.transData
        ax.errorbar(
            x=threads,
            y=time,
            linestyle='dotted',
            linewidth=0.8,
            fmt=plot_markers[i],
            markersize=5,
            yerr=std_dev,
            capsize=3,
            elinewidth=0.4,
            transform=trans,
            label = optimizationName(opt)
        )

    ax.set(xlabel='Number of threads', ylabel='Execution Time (ms)')
    ax.legend()

    ax.yaxis.set_minor_locator(AutoMinorLocator())
    ax.grid(which='major', axis='both', linestyle='-', linewidth=0.5)
    ax.grid(which='minor', linestyle=':', linewidth=0.2, color='gray')

    fig.suptitle(f'Execution time of "multi_maps" ({ "heterogeneous" if heterogeneous else "homogeneous" }) for an array size of {data[0][2]},\ndepending on the number of threads and optimizations\n[averaged on {iterations} executions on a 4-cores CPU, error bars for standard deviation]', x=0.08, horizontalalignment='left', fontsize=12)

    ax.set_xticks(all_threads)
    fig.tight_layout()
    fig.savefig('results/multi_maps'+suffix+'.png', dpi=400)
    # plt.show()

# Main
if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: python run_multi_maps.py [run|plot]')
        exit(1)
    if sys.argv[1] == 'run':
        run()
    elif sys.argv[1] == 'plot':
        plot()
    else:
        print('Usage: python run_multi_maps.py [run|plot]')
        exit(1)