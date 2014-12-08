#ifndef _PROGRESS_BAR_H_INCLUDED_
#define _PROGRESS_BAR_H_INCLUDED_

#ifdef __linux
#define FULL_BLOCK 0x8D
#else
#define FULL_BLOCK 0xDB
#endif // __linux

int j, k;

void progress_bar(long int i, long int fsize);

#endif // _PROGRESS_BAR_H_INCLUDED_
