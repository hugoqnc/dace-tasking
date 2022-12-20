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


# Define the program
def multi_map(A: dace.float64[N], T: dace.int64):
    # Define transient (temporary) array
    tmp1 = np.zeros_like(A)
    tmp2 = np.zeros_like(A)
    tmp3 = np.zeros_like(A)
    tmp4 = np.zeros_like(A)

    # This loop will remain a loop
    for _ in range(T):
        # This loop will become a parallel map
        for i in dace.map[1:N - 4]:
            tmp1[i] = A[i - 1] - 1 * A[i] + A[i + 1]

        # This loop will become a parallel map
        for i in dace.map[1:N - 3]:
            tmp2[i] = A[i - 1] - 2 * A[i] + A[i + 1]

        # This loop will become a parallel map
        for i in dace.map[1:N - 2]:
            tmp3[i] = A[i - 1] - 3 * A[i] + A[i + 1]

        # This loop will become a parallel map
        for i in dace.map[1:N - 1]:
            tmp4[i] = A[i - 1] - 4 * A[i] + A[i + 1]


        for i in dace.map[1:N - 1]:
            A[i] = tmp1[i] + tmp2[i] + tmp3[i] + tmp4[i]

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
    parser.add_argument("iterations", type=int, nargs="?", default=100)
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
