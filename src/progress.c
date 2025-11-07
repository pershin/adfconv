/* Progress bar
 * File: progress.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include "progress.h"
#include <stdio.h>

static size_t i, bytes_per_block, blocks_left;

void progress_bar_start(size_t fsiz) {
  printf("          0%%           50%%           100%%\n"
         "Progress: ");
  fflush(stdout);
  i = 0;
  bytes_per_block = fsiz / PROGRESS_BAR_WIDTH;
  blocks_left = PROGRESS_BAR_WIDTH;
}

void progress_bar(void) {
  i++;

  if (i == bytes_per_block) {
    blocks_left--;
    i = 0;
    putchar(FULL_BLOCK);
    fflush(stdout);
  }
}

void progress_bar_stop(void) {
  while (blocks_left--) {
    putchar(FULL_BLOCK);
  }

  printf("\n");
}
