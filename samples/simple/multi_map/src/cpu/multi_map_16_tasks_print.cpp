/* DaCe AUTO-GENERATED FILE. DO NOT MODIFY */
#include <dace/dace.h>
#include "../../include/hash.h"
#include "omp.h"
#include <stdio.h>

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
    double *tmp5;
    tmp5 = new double DACE_ALIGN(64)[N];
    double *tmp6;
    tmp6 = new double DACE_ALIGN(64)[N];
    double *tmp7;
    tmp7 = new double DACE_ALIGN(64)[N];
    double *tmp8;
    tmp8 = new double DACE_ALIGN(64)[N];
    double *tmp9;
    tmp9 = new double DACE_ALIGN(64)[N];
    double *tmp10;
    tmp10 = new double DACE_ALIGN(64)[N];
    double *tmp11;
    tmp11 = new double DACE_ALIGN(64)[N];
    double *tmp12;
    tmp12 = new double DACE_ALIGN(64)[N];
    double *tmp13;
    tmp13 = new double DACE_ALIGN(64)[N];
    double *tmp14;
    tmp14 = new double DACE_ALIGN(64)[N];
    double *tmp15;
    tmp15 = new double DACE_ALIGN(64)[N];
    double *tmp16;
    tmp16 = new double DACE_ALIGN(64)[N];
    long long _;

    {

        {
            #pragma omp parallel for num_threads(4)
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
            #pragma omp parallel for num_threads(4)
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
            #pragma omp parallel for num_threads(4)
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
            #pragma omp parallel for num_threads(4)
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
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp5[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp6[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp7[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp8[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp9[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp10[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp11[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp12[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp13[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp14[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp15[__i0] = __out;
                }
            }
        }
        {
            #pragma omp parallel for num_threads(4)
            for (auto __i0 = 0; __i0 < N; __i0 += 1) {
                {
                    double __out;

                    ///////////////////
                    // Tasklet code (_numpy_full_)
                    __out = 0.0;
                    ///////////////////

                    tmp16[__i0] = __out;
                }
            }
        }

    }


    for (_ = 0; (_ < T); _ = (_ + 1)) {
        {

            #pragma omp parallel
            { // Tasking scope starts!
                #pragma omp single nowait
                {
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 01 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 16); i += 1) {
                                double multi_map_42_8___tmp17;
                                double multi_map_42_8___tmp18;
                                double multi_map_42_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(1) * __in2);
                                    ///////////////////

                                    multi_map_42_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_42_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_42_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_42_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_42_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_42_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_43_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp1[i] = __out;
                                }
                            }
                            printf("End   task 01 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 02 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 15); i += 1) {
                                double multi_map_46_8___tmp17;
                                double multi_map_46_8___tmp18;
                                double multi_map_46_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(2) * __in2);
                                    ///////////////////

                                    multi_map_46_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_46_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_46_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_46_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_46_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_46_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_47_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp2[i] = __out;
                                }
                            }
                            printf("End   task 02 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 03 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 14); i += 1) {
                                double multi_map_50_8___tmp17;
                                double multi_map_50_8___tmp18;
                                double multi_map_50_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(3) * __in2);
                                    ///////////////////

                                    multi_map_50_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_50_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_50_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_50_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_50_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_50_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_51_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp3[i] = __out;
                                }
                            }
                            printf("End   task 03 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 04 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 13); i += 1) {
                                double multi_map_54_8___tmp17;
                                double multi_map_54_8___tmp18;
                                double multi_map_54_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(4) * __in2);
                                    ///////////////////

                                    multi_map_54_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_54_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_54_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_54_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_54_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_54_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_55_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp4[i] = __out;
                                }
                            }
                            printf("End   task 04 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 05 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 12); i += 1) {
                                double multi_map_57_8___tmp17;
                                double multi_map_57_8___tmp18;
                                double multi_map_57_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(1) * __in2);
                                    ///////////////////

                                    multi_map_57_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_57_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_57_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_57_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_57_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_57_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_58_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp5[i] = __out;
                                }
                            }
                            printf("End   task 05 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 06 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 11); i += 1) {
                                double multi_map_61_8___tmp17;
                                double multi_map_61_8___tmp18;
                                double multi_map_61_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(2) * __in2);
                                    ///////////////////

                                    multi_map_61_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_61_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_61_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_61_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_61_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_61_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_62_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp6[i] = __out;
                                }
                            }
                            printf("End   task 06 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 07 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 10); i += 1) {
                                double multi_map_65_8___tmp17;
                                double multi_map_65_8___tmp18;
                                double multi_map_65_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(3) * __in2);
                                    ///////////////////

                                    multi_map_65_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_65_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_65_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_65_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_65_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_65_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_66_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp7[i] = __out;
                                }
                            }
                            printf("End   task 07 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 08 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 9); i += 1) {
                                double multi_map_69_8___tmp17;
                                double multi_map_69_8___tmp18;
                                double multi_map_69_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(4) * __in2);
                                    ///////////////////

                                    multi_map_69_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_69_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_69_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_69_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_69_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_69_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_70_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp8[i] = __out;
                                }
                            }
                            printf("End   task 08 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 09 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 8); i += 1) {
                                double multi_map_73_8___tmp17;
                                double multi_map_73_8___tmp18;
                                double multi_map_73_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(1) * __in2);
                                    ///////////////////

                                    multi_map_73_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_73_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_73_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_73_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_73_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_73_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_74_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp9[i] = __out;
                                }
                            }
                            printf("End   task 09 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 10 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 7); i += 1) {
                                double multi_map_77_8___tmp17;
                                double multi_map_77_8___tmp18;
                                double multi_map_77_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(2) * __in2);
                                    ///////////////////

                                    multi_map_77_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_77_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_77_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_77_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_77_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_77_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_78_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp10[i] = __out;
                                }
                            }
                            printf("End   task 10 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 11 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 6); i += 1) {
                                double multi_map_81_8___tmp17;
                                double multi_map_81_8___tmp18;
                                double multi_map_81_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(3) * __in2);
                                    ///////////////////

                                    multi_map_81_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_81_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_81_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_81_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_81_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_81_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_82_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp11[i] = __out;
                                }
                            }
                            printf("End   task 11 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 12 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 5); i += 1) {
                                double multi_map_85_8___tmp17;
                                double multi_map_85_8___tmp18;
                                double multi_map_85_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(4) * __in2);
                                    ///////////////////

                                    multi_map_85_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_85_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_85_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_85_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_85_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_85_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_86_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp12[i] = __out;
                                }
                            }
                            printf("End   task 12 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 13 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 4); i += 1) {
                                double multi_map_88_8___tmp17;
                                double multi_map_88_8___tmp18;
                                double multi_map_88_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(1) * __in2);
                                    ///////////////////

                                    multi_map_88_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_88_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_88_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_88_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_88_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_88_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_89_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp13[i] = __out;
                                }
                            }
                            printf("End   task 13 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 14 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 3); i += 1) {
                                double multi_map_92_8___tmp17;
                                double multi_map_92_8___tmp18;
                                double multi_map_92_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(2) * __in2);
                                    ///////////////////

                                    multi_map_92_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_92_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_92_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_92_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_92_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_92_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_93_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp14[i] = __out;
                                }
                            }
                            printf("End   task 14 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 15 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 2); i += 1) {
                                double multi_map_96_8___tmp17;
                                double multi_map_96_8___tmp18;
                                double multi_map_96_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(3) * __in2);
                                    ///////////////////

                                    multi_map_96_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_96_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_96_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_96_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_96_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_96_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_97_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp15[i] = __out;
                                }
                            }
                            printf("End   task 15 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                    #pragma omp task
                    { // Task block starts!
                        {
                            printf("Start task 16 with thread %d\n",omp_get_thread_num());
                            for (auto i = 1; i < (N - 1); i += 1) {
                                double multi_map_100_8___tmp17;
                                double multi_map_100_8___tmp18;
                                double multi_map_100_8___tmp19;
                                {
                                    double __in2 = A[i];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Mult_)
                                    __out = (dace::float64(4) * __in2);
                                    ///////////////////

                                    multi_map_100_8___tmp17 = __out;
                                }
                                {
                                    double __in2 = multi_map_100_8___tmp17;
                                    double __in1 = A[(i - 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Sub_)
                                    __out = (__in1 - __in2);
                                    ///////////////////

                                    multi_map_100_8___tmp18 = __out;
                                }
                                {
                                    double __in1 = multi_map_100_8___tmp18;
                                    double __in2 = A[(i + 1)];
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (_Add_)
                                    __out = (__in1 + __in2);
                                    ///////////////////

                                    multi_map_100_8___tmp19 = __out;
                                }
                                {
                                    double __inp = multi_map_100_8___tmp19;
                                    double __out;

                                    ///////////////////
                                    // Tasklet code (assign_101_12)
                                    __out = __inp;
                                    ///////////////////

                                    tmp16[i] = __out;
                                }
                            }
                            printf("End   task 16 with thread %d\n",omp_get_thread_num());
                        } // Tasking block ends
                    } // Tasking block ends
                }
                #pragma omp taskwait
            } // Task scope ends
            {
                #pragma omp parallel for num_threads(4)
                for (auto i = 1; i < (N - 1); i += 1) {
                    double __tmp17;
                    double __tmp18;
                    double __tmp19;
                    double __tmp20;
                    double __tmp21;
                    double __tmp22;
                    double __tmp23;
                    double __tmp24;
                    double __tmp25;
                    double __tmp26;
                    double __tmp27;
                    double __tmp28;
                    double __tmp29;
                    double __tmp30;
                    double __tmp31;
                    {
                        double __in1 = tmp1[i];
                        double __in2 = tmp2[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp17 = __out;
                    }
                    {
                        double __in1 = __tmp17;
                        double __in2 = tmp3[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp18 = __out;
                    }
                    {
                        double __in1 = __tmp18;
                        double __in2 = tmp4[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp19 = __out;
                    }
                    {
                        double __in1 = __tmp19;
                        double __in2 = tmp5[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp20 = __out;
                    }
                    {
                        double __in1 = __tmp20;
                        double __in2 = tmp6[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp21 = __out;
                    }
                    {
                        double __in1 = __tmp21;
                        double __in2 = tmp7[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp22 = __out;
                    }
                    {
                        double __in1 = __tmp22;
                        double __in2 = tmp8[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp23 = __out;
                    }
                    {
                        double __in1 = __tmp23;
                        double __in2 = tmp9[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp24 = __out;
                    }
                    {
                        double __in1 = __tmp24;
                        double __in2 = tmp10[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp25 = __out;
                    }
                    {
                        double __in1 = __tmp25;
                        double __in2 = tmp11[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp26 = __out;
                    }
                    {
                        double __in1 = __tmp26;
                        double __in2 = tmp12[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp27 = __out;
                    }
                    {
                        double __in1 = __tmp27;
                        double __in2 = tmp13[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp28 = __out;
                    }
                    {
                        double __in1 = __tmp28;
                        double __in2 = tmp14[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp29 = __out;
                    }
                    {
                        double __in1 = __tmp29;
                        double __in2 = tmp15[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp30 = __out;
                    }
                    {
                        double __in1 = __tmp30;
                        double __in2 = tmp16[i];
                        double __out;

                        ///////////////////
                        // Tasklet code (_Add_)
                        __out = (__in1 + __in2);
                        ///////////////////

                        __tmp31 = __out;
                    }
                    {
                        double __inp = __tmp31;
                        double __out;

                        ///////////////////
                        // Tasklet code (assign_105_12)
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
    delete[] tmp5;
    delete[] tmp6;
    delete[] tmp7;
    delete[] tmp8;
    delete[] tmp9;
    delete[] tmp10;
    delete[] tmp11;
    delete[] tmp12;
    delete[] tmp13;
    delete[] tmp14;
    delete[] tmp15;
    delete[] tmp16;
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

