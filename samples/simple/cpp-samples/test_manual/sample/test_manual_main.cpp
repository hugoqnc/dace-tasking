#include <cstdlib>
#include "../include/test.h"

int main(int argc, char **argv) {
    testHandle_t handle;
    int N = 42;
    long long T = 42;
    double * __restrict__ A = (double*) calloc(N, sizeof(double));


    handle = __dace_init_test(N);
    __program_test(handle, A, N, T);
    __dace_exit_test(handle);

    free(A);


    return 0;
}
