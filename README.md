# DPHPC HS2022
## Code Explanation
+ `dace/codegen/targets/cpu.py`
  - register supported ScheduleType with dispatcher
  - generate task/for depending on MapEntry/MapExit ScheduleType
+ `dace/codegen/codegen.py`
  - set default schedule and storage: the default default is `None`
+ `dace/dtypes.py`
  - define ScheduleTypes: `CPU_Multicore` = for, `CPU_Multicore_Tasking_Default` = tasking, `CPU_Multicore_Tasking` = parallel part of tasking 
  - `None` = `CPU_Multicore`

## Configuration

Use `DACE_CONFIG` to specify the configuration files.

```bash
export DACE_CONFIG=/path/to/dace/repo/tests/tasking.conf
# or: `cp tests/tasking.conf ~/.dace.conf` so that it is persistent
cd samples/simple && python axpy.py # Use tasking backend now.
```

Sample DACE_CONFIG to use `dyanamic` schedule with `parallel for` loops:
```bash
export DACE_CONFIG=tests/dynamic_schedule.conf
```

## Experiments
### pytests
1. run `test_results/test_mkdir.sh`.
2. run `test_results/test_run.sh [-t: if tasking] -d [empty OR subdir in tests/npbench_cpu OR file in tests/npbench_cpu]`. Doesn't require a .dace.conf file. DO NOT use it to run the original unmodified DaCe.
3. Save terminal outputs to folder "`date-time-commitHash`".

### utils
> **Warning** The utils use `sed -i '' -e` for macOS, modify them to work on Linux or Windows

> **Note** You can also run things manually following the steps given in the utils

+ jz_test branch: `runFromCache.py`: compile and run cpp files in `.dacecache`, measure with `time`, not accurate.
+ `tests/npbench_cpu/replace.sh`: add cpu marker to `test_cpu()` if not added.
+ `tests_results/test_mkdir.sh`: create a folder "`date-time-commitHash`" with files to save test results.
+ `test_results/test_run.sh`: 
  - export env var DACE_compiler_cpu_openmp_tasking
  - `pytest -m "cpu" tests/npbench_cpu/(subdir or file)`

### NPBench performance measurement
TODO


## Installing for Development
If you have previously installed DaCe, remove it with `pip uninstall dace`. Also remove your local dace folder if you have previously cloned it.

Then, run the following in the folder of your choice:
```bash
git clone --recursive https://github.com/hugoqnc/dace-tasking.git
cd dace-tasking
pip install --editable .
```
---
[![General Tests](https://github.com/spcl/dace/actions/workflows/general-ci.yml/badge.svg)](https://github.com/spcl/dace/actions/workflows/general-ci.yml)
[![GPU Tests](https://github.com/spcl/dace/actions/workflows/gpu-ci.yml/badge.svg)](https://github.com/spcl/dace/actions/workflows/gpu-ci.yml)
[![FPGA Tests](https://github.com/spcl/dace/actions/workflows/fpga-ci.yml/badge.svg)](https://github.com/spcl/dace/actions/workflows/fpga-ci.yml)
[![Documentation Status](https://readthedocs.org/projects/spcldace/badge/?version=latest)](https://spcldace.readthedocs.io/en/latest/?badge=latest)
[![PyPI version](https://badge.fury.io/py/dace.svg)](https://badge.fury.io/py/dace)
[![codecov](https://codecov.io/gh/spcl/dace/branch/master/graph/badge.svg)](https://codecov.io/gh/spcl/dace)


![D](dace.svg)aCe - Data-Centric Parallel Programming
=====================================================

_Decoupling domain science from performance optimization._

DaCe is a [fast](https://nbviewer.org/github/spcl/dace/blob/master/tutorials/benchmarking.ipynb) parallel programming
framework that takes code in Python/NumPy and other programming languages, and maps it to high-performance 
**CPU, GPU, and FPGA** programs, which can be optimized to achieve state-of-the-art. Internally, DaCe 
uses the Stateful DataFlow multiGraph (SDFG) *data-centric intermediate 
representation*: A transformable, interactive representation of code based on 
data movement.
Since the input code and the SDFG are separate, it is possible to optimize a 
program without changing its source, so that it stays readable. On the other 
hand, transformations are customizable and user-extensible, so they can be written 
once and reused in many applications.
With data-centric parallel programming, we enable **direct knowledge transfer** 
of performance optimization, regardless of the application or the target processor.

DaCe generates high-performance programs for:
 * Multi-core CPUs (tested on Intel, IBM POWER9, and ARM with SVE)
 * NVIDIA GPUs and AMD GPUs (with HIP)
 * Xilinx and Intel FPGAs

DaCe can be written inline in Python and transformed in the command-line/Jupyter 
Notebooks or SDFGs can be interactively modified using our [Visual Studio Code extension](https://marketplace.visualstudio.com/items?itemName=phschaad.sdfv).

## [For more information, see the documentation](https://spcldace.readthedocs.io/en/latest/)

Quick Start
-----------

Install DaCe with pip: `pip install dace`

Having issues? See our full [Installation and Troubleshooting Guide](https://spcldace.readthedocs.io/en/latest/setup/installation.html).

Using DaCe in Python is as simple as adding a `@dace` decorator:
```python
import dace
import numpy as np

@dace
def myprogram(a):
    for i in range(a.shape[0]):
        a[i] += i
    return np.sum(a)
```

Calling `myprogram` with any NumPy array or GPU array (e.g., PyTorch, Numba, CuPy) will 
generate data-centric code, compile, and run it. From here on out, you can 
_optimize_ (interactively or automatically), _instrument_, and _distribute_ 
your code. The code creates a shared library (DLL/SO file) that can readily 
be used in any C ABI compatible language (C/C++, FORTRAN, etc.).

For more information on how to use DaCe, see the [samples](samples) or tutorials below:

* [Getting Started](https://nbviewer.jupyter.org/github/spcl/dace/blob/master/tutorials/getting_started.ipynb)
* [Benchmarks, Instrumentation, and Performance Comparison with Other Python Compilers](https://nbviewer.jupyter.org/github/spcl/dace/blob/master/tutorials/benchmarking.ipynb)
* [Explicit Dataflow in Python](https://nbviewer.jupyter.org/github/spcl/dace/blob/master/tutorials/explicit.ipynb)
* [NumPy API Reference](https://nbviewer.jupyter.org/github/spcl/dace/blob/master/tutorials/numpy_frontend.ipynb)
* [SDFG API](https://nbviewer.jupyter.org/github/spcl/dace/blob/master/tutorials/sdfg_api.ipynb)
* [Using and Creating Transformations](https://nbviewer.jupyter.org/github/spcl/dace/blob/master/tutorials/transformations.ipynb)
* [Extending the Code Generator](https://nbviewer.jupyter.org/github/spcl/dace/blob/master/tutorials/codegen.ipynb)

Publication
-----------

The paper for the SDFG IR can be found [here](http://www.arxiv.org/abs/1902.10345).
Other DaCe-related publications are available on our [website](http://spcl.inf.ethz.ch/dace).

If you use DaCe, cite us:
```bibtex
@inproceedings{dace,
  author    = {Ben-Nun, Tal and de~Fine~Licht, Johannes and Ziogas, Alexandros Nikolaos and Schneider, Timo and Hoefler, Torsten},
  title     = {Stateful Dataflow Multigraphs: A Data-Centric Model for Performance Portability on Heterogeneous Architectures},
  year      = {2019},
  booktitle = {Proceedings of the International Conference for High Performance Computing, Networking, Storage and Analysis},
  series = {SC '19}
}
```

Contributing
------------
DaCe is an open-source project. We are happy to accept Pull Requests with your contributions! Please follow the [contribution guidelines](CONTRIBUTING.md) before submitting a pull request.

License
-------
DaCe is published under the New BSD license, see [LICENSE](LICENSE).

