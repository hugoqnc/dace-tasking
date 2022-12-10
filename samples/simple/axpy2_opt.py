# Copyright 2019-2022 ETH Zurich and the DaCe authors. All rights reserved.
""" Simple program showing the DaCe Python interface via scalar multiplication and vector addition. """

import argparse
from typing import List
import dace
import numpy as np
from dace.sdfg.sdfg import SDFG
from dace.sdfg.nodes import MapEntry, MapExit, AccessNode
from dace.dtypes import ScheduleType, OMPTaskingBlockType, OMPTaskingScopeType
# Define a symbol so that the vectors could have arbitrary sizes and compile the code once
# (this step is not necessary for arrays with known sizes)
N = dace.symbol('N')


# Define the data-centric program with type hints
# (without this step, Just-In-Time compilation is triggered every call)
@dace.program
def axpy2(a: dace.float64, x: dace.float64[N], y: dace.float64[N], ap: dace.float64, xp: dace.float64[N], yp: dace.float64[N]):
    p1 = a * x + y

    p2 = ap * yp + xp

    return p1 + p2

def optimize_tasking(sdfg: SDFG) -> SDFG:
    edges = list(sdfg.all_edges_recursive())

    task_start: List[MapEntry] = []
    task_end: List[MapExit] = []
    for edge, state in edges:
        dst = edge.dst
        src = edge.src

        # Identify the start of a*x and ap * yp
        if isinstance(src, AccessNode) and src.label == 'a' or src.label == "ap":
            if isinstance(dst, MapEntry):
                dst.map.schedule = ScheduleType.CPU_Multicore_Tasking_Block
                task_start.append(dst)
        
        # Identify p1, p2
        if isinstance(dst, AccessNode) and dst.label in ("p1", "p2"):
            if isinstance(src, MapExit):
                src.map.schedule = ScheduleType.CPU_Multicore_Tasking_Block
                task_end.append(src)

    task_start[0].map.omp_tasking_scope = OMPTaskingScopeType.Start # a * x
    task_start[0].map.omp_tasking_block = OMPTaskingBlockType.Start
    task_end[0].map.omp_tasking_scope = OMPTaskingScopeType.EndNoWait # + y
    task_end[0].map.omp_tasking_block = OMPTaskingBlockType.End

    task_start[1].map.omp_tasking_scope = OMPTaskingScopeType.Scope # ap * yp
    task_start[1].map.omp_tasking_block = OMPTaskingBlockType.Start
    task_end[1].map.omp_tasking_scope = OMPTaskingScopeType.End # + xp
    task_end[1].map.omp_tasking_block = OMPTaskingBlockType.End

    
    # p1 + p2 is kept as default schedule, either tasking or parallel for, depending on the config
    return sdfg

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("N", type=int, nargs="?", default=1024)
    parser.add_argument("--opt", default=False, action="store_true")
    args = parser.parse_args()

    # Initialize arrays
    a = np.random.rand()
    N = args.N
    x = np.random.rand(N)
    y = np.random.rand(N)
    

    g = axpy2.to_sdfg()

    if args.opt:
        g = optimize_tasking(g)


    # Call the program (the value of N is inferred by dace automatically)
    z = g(a=a, x=x, y=y, ap=a, xp=x, yp=y, N=N)

    # Check result
    expected = (a * x + y) + (a * y + x)
    print("Difference:", np.linalg.norm(z - expected))
