#ifndef PROGRESS_H
#define PROGRESS_H

#include <stdio.h>

#ifdef __linux
#define FULL_BLOCK "\xE2\x96\x88"
#elif __APPLE__
#define FULL_BLOCK "\xE2\x96\x88"
#else
#define FULL_BLOCK "\xDB"
#endif // __linux

#define PROGRESS_BAR_WIDTH 31

void progress_init(size_t fsiz);

void progress_update(void);

void progress_final(void);

#endif /* PROGRESS_H */
