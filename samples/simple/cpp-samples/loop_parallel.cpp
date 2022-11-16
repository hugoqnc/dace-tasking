#include "omp.h"
#include <stdio.h>

int main(){
    #pragma omp parallel for
    for (auto i = 0; i < 99; i += 1) {
        {
            printf("\u001b[3%dm%d[%d] \u001b[30m",omp_get_thread_num(),i,omp_get_thread_num());
        }
    }
    return 0;
}