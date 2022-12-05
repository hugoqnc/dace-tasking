#include <dace/dace.h>
typedef void * testHandle_t;
extern "C" testHandle_t __dace_init_test(int N);
extern "C" void __dace_exit_test(testHandle_t handle);
extern "C" void __program_test(testHandle_t handle, double * __restrict__ A, int N, long long T);
