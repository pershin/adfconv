/* Progress bar
 * File: progress.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include <stdio.h>
#include "progress.h"

int i, j, k;

void progress_bar_start(unsigned long long int fsize)
{
    printf("          0%%           50%%           100%%\n"
           "Progress: ");
    i = 0;
    j = 0;
    k = fsize / 1024 / 31;
}

void progress_bar()
{
    if (i == 1024) {
        i = 0;
        j++;

        if (j == k) {
            putchar(FULL_BLOCK);
            fflush(stdout);
            j = 0;
        }
    }

    i++;
}

void progress_bar_stop()
{
    printf("\n");
}
