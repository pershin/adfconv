/* Progress bar
 * File: progress_bar.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include <stdio.h>
#include "progress_bar.h"

void progress_bar(long int i, long int fsize)
{
    if (i == 0) {
        printf("          0%%           50%%           100%%\n"
            "Progress: ");
    } else {
        if (j != k) {
            putchar(FULL_BLOCK);
            fflush(stdout);
            j = k;
        }
        k = i * 32 / fsize;
    }
}
