import os
import csv
import sys
import matplotlib.pyplot as plt
import numpy as np

threads = [1, 2, 4, 8, 12, 16]
optimizations = ["", "--opt", "--autoopt", "--opt --autoopt"]
array_size = 100000000
iterations = 1

def run():
    with open('results/multi_map.csv', 'w') as csvfile:
        writer = csv.writer(csvfile, delimiter=',')
        writer.writerow(['optimizations', 'threads', 'array_size', 'exec_time'])

        i = 1
        for t in threads:
            for opt in optimizations:
                res = os.popen(f'python ../multi_map.py {array_size} {iterations} {t} {opt}')
                time = res.read().split('\n')[-2].split(' ')[1]
                writer.writerow([opt, t, array_size, time])
                print(f'{i}/{len(threads)*len(optimizations)} — optimizations: {opt}, threads: {t}, exec_time: {time}')
                i += 1

def plot():
    with open('results/multi_map.csv', 'r') as csvfile:
        reader = csv.reader(csvfile, delimiter=',')
        next(reader)
        data = np.array(list(reader))
        # print(data)

    fig, ax = plt.subplots()
    for opt in optimizations:
        opt_data = data[data[:, 0] == opt]
        threads = opt_data[:, 1].astype(np.int)
        time = opt_data[:, 3].astype(np.float)
        ax.plot(threads, time, label = opt if opt!='' else 'none')

    ax.set(xlabel='Number of threads', ylabel='Execution Time (ms)',
        title=f'Execution time of "multi_map" for an array size of {data[0][2]} depending on the number of threads and optimizations')
    ax.grid()
    ax.legend()

    fig.savefig("results/multi_map.png")
    plt.show()

# Main
if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: python run_multi_map.py [run|plot]')
        exit(1)
    if sys.argv[1] == 'run':
        run()
    elif sys.argv[1] == 'plot':
        plot()
    else:
        print('Usage: python run_multi_map.py [run|plot]')
        exit(1)