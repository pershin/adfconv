/* Progress bar
 * File: progress.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include <stdio.h>
#include "progress.h"

int j = 0;
int k = 0;

void progress_bar(unsigned long long int i, unsigned long long int fsize)
{
    if (i == 0) {
        printf("          0%%           50%%           100%%\n"
            "Progress: ");
    } else {
        if (j != k) {
            putchar(FULL_BLOCK);
            j = k;
        }
        k = i * 32 / fsize;
    }
    fflush(stdout);
}
