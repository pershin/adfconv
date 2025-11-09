#ifndef PROGRESS_H
#define PROGRESS_H

#include <stdio.h>

#ifdef __linux
#define FULL_BLOCK "\xE2\x96\x88"
#elif __APPLE__
#define FULL_BLOCK "\xE2\x96\x88"
#else
#define FULL_BLOCK "\xDB"
#endif /* __linux */

#define PROGRESS_BAR_WIDTH 31

/* Progress bar context. */
typedef struct {
  size_t processed;
  size_t size;
  size_t bytes_per_block;
  size_t blocks_left;
} PROGRESS_CTX;

void progress_init(PROGRESS_CTX *context, size_t size);

void progress_update(PROGRESS_CTX *context, size_t numwritten);

int progress_final(PROGRESS_CTX *context);

#endif /* PROGRESS_H */
