#ifndef _PROGRESS_BAR_H_INCLUDED_
#define _PROGRESS_BAR_H_INCLUDED_

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

#endif // _PROGRESS_BAR_H_INCLUDED_
