/* Progress bar
 * File: progress.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include "progress.h"
#include <stdio.h>

int i, j, k;

void progress_bar_start(size_t fsiz) {
  printf("          0%%           50%%           100%%\n"
         "Progress: ");
  i = 0;
  j = 0;
  k = fsiz / 1024 / PROGRESS_BAR_WIDTH;
}

void progress_bar(void) {
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

void progress_bar_stop(void) { printf("\n"); }
