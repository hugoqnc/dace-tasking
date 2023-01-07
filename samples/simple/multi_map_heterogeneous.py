# Copyright 2019-2022 ETH Zurich and the DaCe authors. All rights reserved.
""" Simple program showing the `dace.map` syntax and profiling. """

import argparse
import dace
import numpy as np

from typing import List
from dace.sdfg.sdfg import SDFG
from dace.sdfg.nodes import MapEntry, MapExit, AccessNode
from dace.dtypes import ScheduleType, OMPTaskingBlockType, OMPTaskingScopeType
from dace.transformation.auto.auto_optimize import auto_optimize

# Define a symbol so that the vectors could have arbitrary sizes and compile the code once
# (this step is not necessary for arrays with known sizes)
N = dace.symbol('N')
divideArrayBy = 4 # Divides array and makes the first chunck longer than the others


# Define the program
def multi_map(A: dace.float64[N], T: dace.int64):
    # Define transient (temporary) array
    tmp1 = np.zeros_like(A)
    tmp2 = np.zeros_like(A)
    tmp3 = np.zeros_like(A)
    tmp4 = np.zeros_like(A)
    tmp5 = np.zeros_like(A)
    tmp6 = np.zeros_like(A)
    tmp7 = np.zeros_like(A)
    tmp8 = np.zeros_like(A)
    tmp9 = np.zeros_like(A)
    tmp10 = np.zeros_like(A)
    tmp11 = np.zeros_like(A)
    tmp12 = np.zeros_like(A)
    tmp13 = np.zeros_like(A)
    tmp14 = np.zeros_like(A)
    tmp15 = np.zeros_like(A)
    tmp16 = np.zeros_like(A)

    # This loop will remain a loop
    for _ in range(T):
        # This loop will become a parallel map
        for i in dace.map[1:N - 16]:
            if i<N/divideArrayBy:
                tmp1[i] = np.exp(np.sqrt(np.log((A[i - 1] - 1 * A[i] + A[i + 1])**3)))
            else:
                tmp1[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 15]:
            if i<N/divideArrayBy:
                tmp2[i] = np.exp(np.sqrt(np.log((A[i - 1] - 2 * A[i] + A[i + 1])**3)))
            else:  
                tmp2[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 14]:
            if i<N/divideArrayBy:
                tmp3[i] = np.exp(np.sqrt(np.log((A[i - 1] - 3 * A[i] + A[i + 1])**3)))
            else:
                tmp3[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 13]:
            if i<N/divideArrayBy:
                tmp4[i] = np.exp(np.sqrt(np.log((A[i - 1] - 4 * A[i] + A[i + 1])**3)))
            else:
                tmp4[i] = 0

        for i in dace.map[1:N - 12]:
            if i<N/divideArrayBy:
                tmp5[i] = np.exp(np.sqrt(np.log((A[i - 1] - 1 * A[i] + A[i + 1])**3)))
            else:
                tmp5[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 11]:
            if i<N/divideArrayBy:
                tmp6[i] = np.exp(np.sqrt(np.log((A[i - 1] - 2 * A[i] + A[i + 1])**3)))
            else:
                tmp6[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 10]:
            if i<N/divideArrayBy:
                tmp7[i] = np.exp(np.sqrt(np.log((A[i - 1] - 3 * A[i] + A[i + 1])**3)))
            else:
                tmp7[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 9]:
            if i<N/divideArrayBy:
                tmp8[i] = np.exp(np.sqrt(np.log((A[i - 1] - 4 * A[i] + A[i + 1])**3)))
            else:
                tmp8[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 8]:
            if i<N/divideArrayBy:
                tmp9[i] = np.exp(np.sqrt(np.log((A[i - 1] - 1 * A[i] + A[i + 1])**3)))
            else:
                tmp9[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 7]:
            if i<N/divideArrayBy:
                tmp10[i] = np.exp(np.sqrt(np.log((A[i - 1] - 2 * A[i] + A[i + 1])**3)))
            else:
                tmp10[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 6]:
            if i<N/divideArrayBy:
                tmp11[i] = np.exp(np.sqrt(np.log((A[i - 1] - 3 * A[i] + A[i + 1])**3)))
            else:
                tmp11[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 5]:
            if i<N/divideArrayBy:
                tmp12[i] = np.exp(np.sqrt(np.log((A[i - 1] - 4 * A[i] + A[i + 1])**3)))
            else:
                tmp12[i] = 0

        for i in dace.map[1:N - 4]:
            if i<N/divideArrayBy:
                tmp13[i] = np.exp(np.sqrt(np.log((A[i - 1] - 1 * A[i] + A[i + 1])**3)))
            else:
                tmp13[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 3]:
            if i<N/divideArrayBy:
                tmp14[i] = np.exp(np.sqrt(np.log((A[i - 1] - 2 * A[i] + A[i + 1])**3)))
            else:
                tmp14[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 2]:
            if i<N/divideArrayBy:
                tmp15[i] = np.exp(np.sqrt(np.log((A[i - 1] - 3 * A[i] + A[i + 1])**3)))
            else:
                tmp15[i] = 0

        # This loop will become a parallel map
        for i in dace.map[1:N - 1]:
            if i<N/divideArrayBy:
                tmp16[i] = np.exp(np.sqrt(np.log((A[i - 1] - 4 * A[i] + A[i + 1])**3)))
            else:
                tmp16[i] = 0

        for i in dace.map[1:N - 1]:
            A[i] = tmp1[i] + tmp2[i] + tmp3[i] + tmp4[i] + tmp5[i] + tmp6[i] + tmp7[i] + tmp8[i] + tmp9[i] + tmp10[i] + tmp11[i] + tmp12[i] + tmp13[i] + tmp14[i] + tmp15[i] + tmp16[i]

def optimize_tasking(sdfg: SDFG) -> SDFG:
    edges = list(sdfg.all_edges_recursive())

    maps: List[MapEntry] = []

    for edge, state in edges:
        dst = edge.dst
        src = edge.src

        if isinstance(src, AccessNode) and src.label == 'A':
            if isinstance(dst, MapEntry):
                dst.map.schedule = ScheduleType.CPU_Multicore_Tasking_Block
                maps.append(dst)

    for i in range(len(maps)):
        maps[i].map.omp_tasking_block = OMPTaskingBlockType.StartAndEnd
        if i == 0:
            maps[i].map.omp_tasking_scope = OMPTaskingScopeType.Start
        if i == len(maps) - 1:
            maps[i].map.omp_tasking_scope = OMPTaskingScopeType.End

    return sdfg

def change_threads_number(sdfg: SDFG, nb_threads) -> SDFG:
    edges = list(sdfg.all_edges_recursive())

    for edge, state in edges:
        src = edge.src

        if isinstance(src, MapEntry):
            src.map.omp_num_threads = nb_threads

    return sdfg


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("N", type=int, nargs="?", default=1024)
    parser.add_argument("iterations", type=int, nargs="?", default=1)
    parser.add_argument("threads", type=int, nargs="?", default=8)
    parser.add_argument("--opt", default=False, action="store_true")
    parser.add_argument("--autoopt", default=False, action="store_true")
    parser.add_argument("--noregen", default=False, action="store_true")
    args = parser.parse_args()
    
    # Create a data-centric version of the program
    g = dace.program(multi_map).to_sdfg()
    g._regenerate_code = not args.noregen

    if args.opt:
        g = optimize_tasking(g)

    if args.autoopt:
        g = auto_optimize(g, dace.config.Config.get('optimizer'))

    g = change_threads_number(g,args.threads)

    # Set initial values
    A = np.random.rand(args.N)

    # Time the result by enabling profiling
    with dace.config.set_temporary('profiling', value=True):
        with dace.config.set_temporary('treps', value=10):
            g(A=A, T=args.iterations, N=args.N)
