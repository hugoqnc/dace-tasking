/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct multi_map_t {

};

void __program_multi_map_internal(multi_map_t *__state, double * __restrict__ A, int N, long long T)
{
    double *tmp1;
    tmp1 = new double DACE_ALIGN(64)[N];
    double *tmp2;
    tmp2 = new double DACE_ALIGN(64)[N];
    double *tmp3;
    tmp3 = new double DACE_ALIGN(64)[N];
    double *tmp4;
    tmp4 = new double DACE_ALIGN(64)[N];
    long long _;

    {

        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp1[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp2[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp3[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp4[__i0] = __out;
                }
            }
        }

    }


    for (_ = 0; (_ < T); _ = (_ + 1)) {
        {

            {
                #pragma omp parallel for
                for (auto i = 1; i < (N - 1); i += 1) {
                    double multi_map_29_8___tmp5;
                    double multi_map_29_8___tmp6;
                    double multi_map_29_8___tmp7;
                    {
                        double __in2 = A[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (dace::float64(1) * __in2);
                        ///////////////////

                        multi_map_29_8___tmp5 = __out;
                    }
                    {
                        double __in2 = multi_map_29_8___tmp5;
                        double __in1 = A[(i - 1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Sub_)
                        __out = (__in1 - __in2);
                        ///////////////////

                        multi_map_29_8___tmp6 = __out;
                    }
                    {
                        double __in1 = multi_map_29_8___tmp6;
                        double __in2 = A[(i + 1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        multi_map_29_8___tmp7 = __out;
                    }
                    {
                        double __inp = multi_map_29_8___tmp7;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_30_12)
                        __out = __inp;
                        ///////////////////

                        tmp1[i] = __out;
                    }
                }
            }
            {
                #pragma omp parallel for
                for (auto i = 1; i < (N - 1); i += 1) {
                    double multi_map_33_8___tmp5;
                    double multi_map_33_8___tmp6;
                    double multi_map_33_8___tmp7;
                    {
                        double __in2 = A[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (dace::float64(2) * __in2);
                        ///////////////////

                        multi_map_33_8___tmp5 = __out;
                    }
                    {
                        double __in2 = multi_map_33_8___tmp5;
                        double __in1 = A[(i - 1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Sub_)
                        __out = (__in1 - __in2);
                        ///////////////////

                        multi_map_33_8___tmp6 = __out;
                    }
                    {
                        double __in1 = multi_map_33_8___tmp6;
                        double __in2 = A[(i + 1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        multi_map_33_8___tmp7 = __out;
                    }
                    {
                        double __inp = multi_map_33_8___tmp7;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_34_12)
                        __out = __inp;
                        ///////////////////

                        tmp2[i] = __out;
                    }
                }
            }
            {
                #pragma omp parallel for
                for (auto i = 1; i < (N - 1); i += 1) {
                    double multi_map_37_8___tmp5;
                    double multi_map_37_8___tmp6;
                    double multi_map_37_8___tmp7;
                    {
                        double __in2 = A[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (dace::float64(3) * __in2);
                        ///////////////////

                        multi_map_37_8___tmp5 = __out;
                    }
                    {
                        double __in2 = multi_map_37_8___tmp5;
                        double __in1 = A[(i - 1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Sub_)
                        __out = (__in1 - __in2);
                        ///////////////////

                        multi_map_37_8___tmp6 = __out;
                    }
                    {
                        double __in1 = multi_map_37_8___tmp6;
                        double __in2 = A[(i + 1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        multi_map_37_8___tmp7 = __out;
                    }
                    {
                        double __inp = multi_map_37_8___tmp7;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_38_12)
                        __out = __inp;
                        ///////////////////

                        tmp3[i] = __out;
                    }
                }
            }
            {
                #pragma omp parallel for
                for (auto i = 1; i < (N - 1); i += 1) {
                    double multi_map_41_8___tmp5;
                    double multi_map_41_8___tmp6;
                    double multi_map_41_8___tmp7;
                    {
                        double __in2 = A[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Mult_)
                        __out = (dace::float64(4) * __in2);
                        ///////////////////

                        multi_map_41_8___tmp5 = __out;
                    }
                    {
                        double __in2 = multi_map_41_8___tmp5;
                        double __in1 = A[(i - 1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Sub_)
                        __out = (__in1 - __in2);
                        ///////////////////

                        multi_map_41_8___tmp6 = __out;
                    }
                    {
                        double __in1 = multi_map_41_8___tmp6;
                        double __in2 = A[(i + 1)];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        multi_map_41_8___tmp7 = __out;
                    }
                    {
                        double __inp = multi_map_41_8___tmp7;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_42_12)
                        __out = __inp;
                        ///////////////////

                        tmp4[i] = __out;
                    }
                }
            }
            {
                #pragma omp parallel for
                for (auto i = 1; i < (N - 1); i += 1) {
                    double __tmp5;
                    double __tmp6;
                    double __tmp7;
                    {
                        double __in1 = tmp1[i];
                        double __in2 = tmp2[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp5 = __out;
                    }
                    {
                        double __in1 = __tmp5;
                        double __in2 = tmp3[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp6 = __out;
                    }
                    {
                        double __in1 = __tmp6;
                        double __in2 = tmp4[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp7 = __out;
                    }
                    {
                        double __inp = __tmp7;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_46_12)
                        __out = __inp;
                        ///////////////////

                        A[i] = __out;
                    }
                }
            }

        }

    }

    delete[] tmp1;
    delete[] tmp2;
    delete[] tmp3;
    delete[] tmp4;
}

DACE_EXPORTED void __program_multi_map(multi_map_t *__state, double * __restrict__ A, int N, long long T)
{
    __program_multi_map_internal(__state, A, N, T);
}

DACE_EXPORTED multi_map_t *__dace_init_multi_map(int N)
{
    int __result = 0;
    multi_map_t *__state = new multi_map_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED void __dace_exit_multi_map(multi_map_t *__state)
{
    delete __state;
}

