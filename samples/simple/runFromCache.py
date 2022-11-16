# Script to directly run a C++ program from .dacecache
# Useful if you want to run manually modified C++ code from .dacecache, that would be erased by running it with DaCe

import os;
import sys;
import timeit

if len(sys.argv) != 2:
    print("Usage: runFromCache.py <dace_function_name>")
    sys.exit(1)

# Arguments to provide
compiler = "g++-12"
dace_path = "/Users/hugoqueinnec/Documents/ETH/Design\ of\ Parallel\ and\ High-Performance\ Computing\ 263-2800-00L/dace-tasking/dace"

# Compiles from .dacecache C++ code
func = sys.argv[1]
command = compiler + " -o " + func + ".out -fopenmp .dacecache/" + func + "/sample/" + func + "_main.cpp .dacecache/" + func + "/src/cpu/" + func + ".cpp -I" + dace_path + "/runtime/include/"
print("\u001b[34m" + command + "\u001b[30m")
os.system(command)

# Run and time
# Warning: use this timing as a relative measure between two program.
# It is not an absolute measure of the execution time because it includes the time of python's os.system instruction.
numberOfTimes = 100
print("\u001b[32mExecution time for", numberOfTimes, "executions:\033[1m" ,timeit.timeit(lambda: os.system("./" + func + ".out"), number=numberOfTimes), "\u001b[30m\033[0m")