/* Progress bar
 * File: progress.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include "progress.h"
#include <stdio.h>

void progress_init(PROGRESS_CTX *context, size_t size) {
  context->processed = 0;
  context->size = size;
  context->bytes_per_block = size / PROGRESS_BAR_WIDTH;
  context->blocks_left = PROGRESS_BAR_WIDTH;

  printf("          0%%           50%%           100%%\n"
         "Progress: ");
  fflush(stdout);
}

void progress_update(PROGRESS_CTX *context, size_t numwritten) {
  size_t blocks = PROGRESS_BAR_WIDTH;

  context->processed += numwritten;

  if (context->bytes_per_block > 0) {
    blocks = context->processed / context->bytes_per_block;
  }

  for (; context->blocks_left > (PROGRESS_BAR_WIDTH - blocks);
       context->blocks_left--) {
    fputs(FULL_BLOCK, stdout);
  }

  fflush(stdout);
}

int progress_final(PROGRESS_CTX *context) {
  int done = 0;

  if (context->processed == context->size) {
    done = 1;
  }

  printf("\n");

  if (done) {
    printf("Done!\n");
  }

  return done;
}
