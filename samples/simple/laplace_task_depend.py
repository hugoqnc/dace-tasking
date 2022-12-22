# Copyright 2019-2022 ETH Zurich and the DaCe authors. All rights reserved.
""" Simple program showing the `dace.map` syntax and profiling. """

import argparse
import dace
import numpy as np
from dace.transformation.auto.auto_optimize import auto_optimize

# Define a symbol so that the vectors could have arbitrary sizes and compile the code once
# (this step is not necessary for arrays with known sizes)
N = dace.symbol('N')


# Define the program
def laplace(A: dace.float64[N], T: dace.int64):
    # Define transient (temporary) array
    tmp = np.zeros_like(A)

    # This loop will remain a loop
    for _ in range(T):
        # This loop will become a parallel map
        for i in dace.map[1:N - 1]:
            tmp[i] = A[i - 1] - 2 * A[i] + A[i + 1]
            # Alternatively, a "NumPy way" to write the kernel also works
            # tmp[i] = np.sum(A[i - 1:i + 2] * np.array([1, -2, 1]))

        for i in dace.map[1:N - 1]:
            A[i] = tmp[i - 1] - 2 * tmp[i] + tmp[i + 1]
    
# Define the program
def laplace_test(A, T, N):
    # Define transient (temporary) array
    tmp = np.zeros_like(A)

    # This loop will remain a loop
    for _ in range(T):
        # This loop will become a parallel map
        for i in range(1,N - 1):
            tmp[i] = A[i - 1] - 2 * A[i] + A[i + 1]
            # Alternatively, a "NumPy way" to write the kernel also works
            # tmp[i] = np.sum(A[i - 1:i + 2] * np.array([1, -2, 1]))

        for i in range(1,N - 1):
            A[i] = tmp[i - 1] - 2 * tmp[i] + tmp[i + 1]

def validate(g, T, N):
    for _ in range(50):
        A = np.random.rand(N)
        gt_A = np.copy(A)

        g(A=A, T=T, N=N)
        laplace_test(gt_A, T, N)

        # print(A, gt_A)
        diff = np.linalg.norm(gt_A - A) / np.linalg.norm(gt_A)
        assert diff < 1e-6
    
    print("Valid!")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("N", type=int, nargs="?", default=1024)
    parser.add_argument("iterations", type=int, nargs="?", default=100)
    args = parser.parse_args()

    # Create a data-centric version of the program
    dace_laplace = dace.program(laplace)
    g = dace_laplace.to_sdfg()
    g = auto_optimize(g, dace.dtypes.DeviceType.CPU)

    validate(dace_laplace, args.iterations, args.N)
    
    # Set initial values
    A = np.random.rand(args.N)    

    # Time the result by enabling profiling
    with dace.config.set_temporary('profiling', value=True):
        # dace_laplace(A, args.iterations)
        g(A=A, T=args.iterations, N=args.N)
