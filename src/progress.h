#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#include <stdio.h>

#ifdef __linux
#define FULL_BLOCK "\xE2\x96\x88"
#elif __APPLE__
#define FULL_BLOCK "\xE2\x96\x88"
#else
#define FULL_BLOCK "\xDB"
#endif // __linux

#define PROGRESS_BAR_WIDTH 31

void progress_bar_start(size_t fsiz);

void progress_bar(void);

void progress_bar_stop(void);

#endif /* PROGRESS_BAR_H */
