#include "omp.h"
#include <stdio.h>
#include <unistd.h>

int iterationsPerThread = 10;
int numberOfThreads = 8;

int main(){
    #pragma omp parallel for num_threads(8)
    for (auto i = 0; i < iterationsPerThread*numberOfThreads; i += 1) {
        {   
            if (i<iterationsPerThread) {
                sleep(3); // sleep 3 times more for the first iterations
            } else {
                sleep(1);
            }
            printf("\u001b[3%dm%d[%d] \u001b[30m",omp_get_thread_num(),i,omp_get_thread_num());
        }
    }
    return 0;
}