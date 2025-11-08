/* Progress bar
 * File: progress.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include "progress.h"
#include <stdio.h>

static size_t i, bytes_per_block, blocks_left;

void progress_init(size_t fsiz) {
  printf("          0%%           50%%           100%%\n"
         "Progress: ");
  fflush(stdout);
  i = 0;
  bytes_per_block = fsiz / PROGRESS_BAR_WIDTH;
  blocks_left = PROGRESS_BAR_WIDTH;
}

void progress_update(void) {
  i++;

  if (i == bytes_per_block) {
    blocks_left--;
    i = 0;
    fputs(FULL_BLOCK, stdout);
    fflush(stdout);
  }
}

void progress_final(void) {
  while (blocks_left--) {
    fputs(FULL_BLOCK, stdout);
  }

  printf("\n");
}
