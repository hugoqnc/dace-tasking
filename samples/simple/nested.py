# Copyright 2019-2022 ETH Zurich and the DaCe authors. All rights reserved.
""" Simple program showing the `dace.map` syntax and profiling. """

import argparse
import dace
import numpy as np
try:
    import scipy.sparse as sp
except (ImportError, ModuleNotFoundError):
    print('This sample requires scipy to validate. Validation will be disabled')
    sp = None

# Define sparse array sizes
W = dace.symbol('W')


# Define dace program with type hints to enable Ahead-Of-Time compilation
@dace.program
def nested(x: dace.float32[W]):
    b = np.zeros([W], dtype=np.float32)

    for i in dace.map[0:1]:
        for j in dace.map[0:W]:
            for k in dace.map[0:W]:
                b[i] += x[i] + x[j] + x[k]

    return b

def nested_check(x, W):
    b = np.zeros([W], dtype=np.float32)

    for i in range(1):
        for j in range(W):
            for k in range(W):
                b[i] += x[i] + x[j] + x[k]

    return b


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("-W", type=int, nargs="?", default=256)
    args = parser.parse_args()

    # print(f'Sparse Matrix-Vector Multiplication {args.H}x{args.W} ({args.nnz} non-zero elements)')

    # Setup inputs
    x = np.random.rand(args.W).astype(np.float32)
    #########################

    # Run program
    b = nested(x)
    b_check = nested_check(x, args.W)

    diff = np.array_equal(b_check, b)
    print(diff)
