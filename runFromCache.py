import os;
import sys;
import timeit

if len(sys.argv) != 2:
    print("Usage: runFromCache.py <dace_function_name>")
    sys.exit(1)

# Arguments to provide
compiler = "g++-11"
BASE = "/Users/jenny/Desktop/dace-tasking"
dace_path = f"{BASE}/dace"
simple_path = f"{BASE}/samples/simple"
# simple_path = "."

# Compiles from .dacecache C++ code
func = sys.argv[1]
out_path = f"{func}.out"
main_path = f"{simple_path}/.dacecache/{func}/sample/{func}_main.cpp"
core_path = f"{simple_path}/.dacecache/{func}/src/cpu/{func}_save.cpp"
# "-fdump-tree-optimized"
compiler_flags = " " + " ".join(["-std=c++14 -O3 -march=native -ffast-math", "-fopenmp"]) + " "
command = compiler + " -o " + out_path + compiler_flags + main_path + " " + core_path + " -I" + dace_path + "/runtime/include/"
print("\u001b[34m" + command + "\u001b[30m")
os.system(command)

# Run and time
# Warning: use this timing as a relative measure between two program.
# It is not an absolute measure of the execution time because it includes the time of python's os.system instruction.
numberOfTime = 100
print("\u001b[32mExecution time for", numberOfTime, "executions:\033[1m" ,timeit.timeit(lambda: os.system("./" + func + ".out"), number=numberOfTime), "\u001b[30m\033[0m")