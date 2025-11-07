#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H

#ifdef __linux
#define FULL_BLOCK 0x8D
#elif __APPLE__
#define FULL_BLOCK '*'
#else
#define FULL_BLOCK 0xDB
#endif // __linux

void progress_bar_start(unsigned long long int fsize);

void progress_bar(void);

void progress_bar_stop(void);

#endif /* PROGRESS_BAR_H */
