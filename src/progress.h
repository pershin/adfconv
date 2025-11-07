#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <stdio.h>

#ifdef __linux
#define FULL_BLOCK 0x8D
#elif __APPLE__
#define FULL_BLOCK '*'
#else
#define FULL_BLOCK 0xDB
#endif // __linux

#define PROGRESS_BAR_WIDTH 31

void progress_bar_start(size_t fsiz);

void progress_bar(void);

void progress_bar_stop(void);

#endif /* PROGRESS_BAR_H */
