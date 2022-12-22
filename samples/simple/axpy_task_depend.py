# Copyright 2019-2022 ETH Zurich and the DaCe authors. All rights reserved.
""" Simple program showing the DaCe Python interface via scalar multiplication and vector addition. """

import argparse
import dace
import numpy as np
from dace.sdfg import infer_types
from dace.dtypes import ScheduleType
# Define a symbol so that the vectors could have arbitrary sizes and compile the code once
# (this step is not necessary for arrays with known sizes)
N = dace.symbol('N')


# Define the data-centric program with type hints
# (without this step, Just-In-Time compilation is triggered every call)
@dace.program()
def axpy(a: dace.float64, x: dace.float64[N], y: dace.float64[N]):
    return a * x + y

def validate(g, a, x, y):
    for _ in range(50):
        z = g(a=a, x=x, y=y, N=x.shape[0])

        # Check result
        expected = a * x + y
        diff = np.linalg.norm(z - expected) / np.linalg.norm(z)
        assert diff < 1e-6
    
    print("Valid!")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("N", type=int, nargs="?", default=1024)
    args = parser.parse_args()

    # Initialize arrays
    a = np.random.rand()
    x = np.random.rand(args.N)
    y = np.random.rand(args.N)

    g = axpy.to_sdfg(simplify=True)
    infer_types.set_default_schedule_and_storage_types(g, ScheduleType.CPU_Multicore_Tasking_Default)
    # Call the program (the value of N is inferred by dace automatically)
    z = g(a=a, x=x, y=y, N=x.shape[0])
    # z = axpy_tasking(a, x, y)

    # Check result
    # expected = a * x + y
    # print("Difference:", np.linalg.norm(z - expected))
    # validate(g, a, x, y)

    with dace.config.set_temporary('profiling', value=True):  # Enable profiling
        with dace.config.set_temporary('treps', value=1000):   # Run 1000 times
            z = g(a=a, x=x, y=y, N=x.shape[0])
