/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"

struct cholesky_t {
    double __0___tmp0;
    double __0___tmp1;
    double __0___tmp2;
    double __0___tmp3;
    double __0___tmp4;
    double __0___tmp5;
    double __0___tmp6;
};

inline void _Dot__sdfg_1_0_1_9(cholesky_t *__state, double*  _x, double*  _y, double&  _result, long long j) {

    {

        {
            for (auto _unused_var = 0; _unused_var < 1; _unused_var += 1) {
                {
                    double _out;

                    ///////////////////
                    // Tasklet code (_i_dotnit)
                    _out = 0;
                    ///////////////////

                    _result = _out;
                }
            }   
        }

    }
    {

        {
            for (auto __i = 0; __i < j; __i += 1) {
                {
                    double __x = _x[__i];
                    double __y = _y[__i];
                    double __out;

                    ///////////////////
                    // Tasklet code (dot)
                    __out = (__x * __y);
                    ///////////////////

                    dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce_atomic(&_result, __out);
                }
            }  
        }

    }
    
}

inline void _Dot__sdfg_0_3_11(cholesky_t *__state, double*  _x, double*  _y, double&  _result, long long i) {

    {

        {
            for (auto _unused_var = 0; _unused_var < 1; _unused_var += 1) {
                {
                    double _out;

                    ///////////////////
                    // Tasklet code (_i_dotnit)
                    _out = 0;
                    ///////////////////

                    _result = _out;
                }
            }
        }

    }
    {

        {
            for (auto __i = 0; __i < i; __i += 1) {
                {
                    double __x = _x[__i];
                    double __y = _y[__i];
                    double __out;

                    ///////////////////
                    // Tasklet code (dot)
                    __out = (__x * __y);
                    ///////////////////

                    dace::wcr_fixed<dace::ReductionType::Sum, double>::reduce_atomic(&_result, __out);
                }
            }
        }

    }
    
}

void __program_cholesky_internal(cholesky_t *__state, double * __restrict__ A, long long N)
{
    long long i;
    long long j;

    {

        dace::CopyND<double, 1, false, 1>::template ConstDst<1>::Copy(
        A, &__state->__0___tmp0, 1);
        {
            double __in1 = __state->__0___tmp0;
            double __out;

            ///////////////////
            // Tasklet code (_numpy_sqrt_)
            __out = sqrt(__in1);
            ///////////////////

            __state->__0___tmp1 = __out;
        }
    
        {
            double __inp = __state->__0___tmp1;
            double __out;

            ///////////////////
            // Tasklet code (assign_24_4)
            __out = __inp;
            ///////////////////

            A[0] = __out;
        }

    }


    for (i = 1; (i < N); i = i + 1) {
        for (j = 0; (j < i); j = j + 1) {
            {
                #pragma omp task depend(inout: A[(N * i)], A[(N * j)], A[((N * i) + j)], __state)
                {
                    double* A_0;
                    A_0 = &A[(N * i)];
                    double* A_1;
                    A_1 = &A[(N * j)];

                    _Dot__sdfg_1_0_1_9(__state, &A_0[0], &A_1[0], __state->__0___tmp2, j);
                    {
                        double __in2 = __state->__0___tmp2;
                        double __in1 = A[((N * i) + j)];
                        double __out;

                        ///////////////////
                        // Tasklet code (augassign_27_12)
                        __out = (__in1 - __in2);
                        ///////////////////

                        A[((N * i) + j)] = __out;
                    }

                    dace::CopyND<double, 1, false, 1>::template ConstDst<1>::Copy(
                    A + ((N * j) + j), &__state->__0___tmp3, 1);
                    {
                        double __in2 = __state->__0___tmp3;
                        double __in1 = A[((N * i) + j)];
                        double __out;

                        ///////////////////
                        // Tasklet code (augassign_28_12)
                        __out = (__in1 / __in2);
                        ///////////////////

                        A[((N * i) + j)] = __out;
                    }

                }

            }
        }
        {
            {
                #pragma omp task depend(inout: A[(N * i)], A[((N * i) + i)], __state)
                {
                    double* A_2;
                    A_2 = &A[(N * i)];
                    double* A_3;
                    A_3 = &A[(N * i)];

                    _Dot__sdfg_0_3_11(__state, &A_2[0], &A_3[0], __state->__0___tmp4, i);
                    {
                        double __in2 = __state->__0___tmp4;
                        double __in1 = A[((N * i) + i)];
                        double __out;

                        ///////////////////
                        // Tasklet code (augassign_29_8)
                        __out = (__in1 - __in2);
                        ///////////////////

                        A[((N * i) + i)] = __out;
                    }

                    dace::CopyND<double, 1, false, 1>::template ConstDst<1>::Copy(
                    A + ((N * i) + i), &__state->__0___tmp5, 1);
                    {
                        double __in1 = __state->__0___tmp5;
                        double __out;

                        ///////////////////
                        // Tasklet code (_numpy_sqrt_)
                        __out = sqrt(__in1);
                        ///////////////////

                        __state->__0___tmp6 = __out;
                    }
                    {
                        double __inp = __state->__0___tmp6;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_30_8)
                        __out = __inp;
                        ///////////////////

                        A[((N * i) + i)] = __out;
                    }
                }

            }
        }
    }

}

DACE_EXPORTED void __program_cholesky(cholesky_t *__state, double * __restrict__ A, long long N)
{
    #pragma omp parallel 
    {
        #pragma omp single nowait
        {
            
            __program_cholesky_internal(__state, A, N);
        }
        #pragma omp taskwait
    }
}

DACE_EXPORTED cholesky_t *__dace_init_cholesky(long long N)
{
    int __result = 0;
    cholesky_t *__state = new cholesky_t;



    if (__result) {
        delete __state;
        return nullptr;
    }
    return __state;
}

DACE_EXPORTED void __dace_exit_cholesky(cholesky_t *__state)
{
    delete __state;
}

