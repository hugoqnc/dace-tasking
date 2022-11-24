#include "omp.h"
#include <stdio.h>

int main(){
    #pragma omp parallel for
    for (auto i = 0; i < 8; i += 1) {
        for (auto j = 0; j < 10; j += 1) {
            {
                printf("\u001b[3%dm%d-%d[%d] \u001b[30m",omp_get_thread_num(),i,j,omp_get_thread_num());
            }
        }
    }
    return 0;
}