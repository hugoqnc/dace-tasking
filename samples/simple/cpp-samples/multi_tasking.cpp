#include "omp.h"
#include <stdio.h>
#include <chrono>
#include <thread>

int main(){
    int sleepMillis = 50;
    int iterationsPerLoop = 100;
    omp_set_nested(1); // Very important: allows to have multiple threads per task. I don't think setting it is necessary for DaCe because an environment variable seems to be set already.

    #pragma omp parallel
    {
        #pragma omp single nowait
        {
            #pragma omp task
            {
                int threadNum = omp_get_thread_num();
                #pragma omp parallel for
                for (auto i = 0; i < iterationsPerLoop; i += 1) {
                    {
                        std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
                        printf("\u001b[3%dm1:%d[%d,%d] \u001b[30m",omp_get_thread_num(),i,threadNum,omp_get_thread_num());
                    }
                }
            }
            #pragma omp task
            {
                int threadNum = omp_get_thread_num();
                #pragma omp parallel for
                for (auto i = 0; i < iterationsPerLoop; i += 1) {
                    {
                        std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
                        printf("\u001b[3%dm2:%d[%d,%d] \u001b[30m",omp_get_thread_num(),i,threadNum,omp_get_thread_num());
                    }
                }
            }
            #pragma omp task
            {
                int threadNum = omp_get_thread_num();
                #pragma omp parallel for
                for (auto i = 0; i < iterationsPerLoop; i += 1) {
                    {
                        std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
                        printf("\u001b[3%dm3:%d[%d,%d] \u001b[30m",omp_get_thread_num(),i,threadNum,omp_get_thread_num());
                    }
                }
            }
            #pragma omp task
            {
                int threadNum = omp_get_thread_num();
                #pragma omp parallel for
                for (auto i = 0; i < iterationsPerLoop; i += 1) {
                    {
                        std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
                        printf("\u001b[3%dm4:%d[%d,%d] \u001b[30m",omp_get_thread_num(),i,threadNum,omp_get_thread_num());
                    }
                }
            }
        } 
        #pragma omp taskwait
    }
    return 0;
}