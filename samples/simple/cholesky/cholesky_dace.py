# Copyright 2019-2021 ETH Zurich and the DaCe authors. All rights reserved.
# Original application code: NPBench - https://github.com/spcl/npbench

import dace.dtypes
import numpy as np
import dace as dc
import pytest
import argparse
from dace.fpga_testing import fpga_test
from dace.transformation.interstate import FPGATransformSDFG, InlineSDFG
from dace.transformation.dataflow import StreamingMemory, StreamingComposition
from dace.transformation.auto.auto_optimize import auto_optimize
import timeit
import random

# Data set sizes
# N
sizes = {"tiny": 4, "mini": 40, "small": 120, "medium": 400, "large": 2000, "extra-large": 4000}

M, N = (dc.symbol(s, dtype=dc.int64) for s in ('M', 'N'))


@dc.program(regenerate_code=False)
def cholesky(A: dc.float64[N, N]):
    A[0, 0] = np.sqrt(A[0, 0])
    for i in range(1, N):
        for j in range(i):
            A[i, j] -= np.dot(A[i, :j], A[j, :j])
            A[i, j] /= A[j, j]
        A[i, i] -= np.dot(A[i, :i], A[i, :i])
        A[i, i] = np.sqrt(A[i, i])



def init_data(N):
    A = np.empty((N, N), dtype=np.float64)
    for i in range(N):
        for j in range(i + 1):
            A[i, j] = (-j % N) / N + 1
        for j in range(i + 1, N):
            # A[i,j] = np.random.uniform()*100
            A[i, j] = 0.0
        A[i, i] = 1.0

    A[:] = A @ np.transpose(A)
    return A


def ground_truth(N, A):
    A[0, 0] = np.sqrt(A[0, 0])
    for i in range(1, N):
        for j in range(i):
            A[i, j] -= np.dot(A[i, :j], A[j, :j])
            A[i, j] /= A[j, j]
        A[i, i] -= np.dot(A[i, :i], A[i, :i])
        A[i, i] = np.sqrt(A[i, i])


def run_cholesky(device_type: dace.dtypes.DeviceType):
    """
    Runs Cholesky for the given device

    :return: the SDFG
    """

    # Initialize data (polybench mini size)
    for i in range(1):
        N = sizes["medium"]
        A = init_data(N)
        gt_A = np.copy(A)
        # print(A)

        if device_type in {dace.dtypes.DeviceType.CPU}:
            # Parse the SDFG and apply auto-opt
            sdfg = cholesky.to_sdfg()
            sdfg = auto_optimize(sdfg, device_type)
            print(f">>>>> {i} Regenerate code:", sdfg._regenerate_code)
            sdfg(A=A, N=N)

        # Compute ground truth and validate result
        ground_truth(N, gt_A)

        # print(A)
        # print(gt_A)
        
        diff = np.linalg.norm(gt_A - A) / np.linalg.norm(gt_A)
        assert diff < 1e-6
        # t = timeit.Timer(lambda: sdfg(A=A, N=N))
        # print(t.timeit(5))
        
        with dace.config.set_temporary('profiling', value=True):
            with dace.config.set_temporary('treps', value=30):
                sdfg(A=A, N=N)
    return sdfg


def test_cpu():
    run_cholesky(dace.dtypes.DeviceType.CPU)


if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument("-t", "--target", default='cpu', choices=['cpu'], help='Target platform')

    args = vars(parser.parse_args())
    target = args["target"]

    run_cholesky(dace.dtypes.DeviceType.CPU)
