#include "omp.h"
#include <stdio.h>
#include <chrono>
#include <thread>

int main(){
    int sleepMillis = 50;
    int iterationsPerLoop = 100;
    omp_set_nested(1);

    {
        #pragma omp parallel for
        for (auto i = 0; i < iterationsPerLoop; i += 1) {
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
                printf("\u001b[3%dm1:%d[%d] \u001b[30m",omp_get_thread_num(),i,omp_get_thread_num());
            }
        }
    }
    // printf("\n\n");
    {
        #pragma omp parallel for
        for (auto i = 0; i < iterationsPerLoop; i += 1) {
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
                printf("\u001b[3%dm2:%d[%d] \u001b[30m",omp_get_thread_num(),i,omp_get_thread_num());
            }
        }
    }
    // printf("\n\n");
    {
        #pragma omp parallel for
        for (auto i = 0; i < iterationsPerLoop; i += 1) {
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
                printf("\u001b[3%dm3:%d[%d] \u001b[30m",omp_get_thread_num(),i,omp_get_thread_num());
            }
        }
    }
    // printf("\n\n");
    {
        #pragma omp parallel for
        for (auto i = 0; i < iterationsPerLoop; i += 1) {
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(sleepMillis));
                printf("\u001b[3%dm4:%d[%d] \u001b[30m",omp_get_thread_num(),i,omp_get_thread_num());
            }
        }
    }
    return 0;
}