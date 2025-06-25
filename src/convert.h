#ifndef _CONVERT_H_INCLUDED_
#define _CONVERT_H_INCLUDED_

#include <stdio.h>

typedef unsigned char byte;

int file_exists(const char *filename);

unsigned long long int filesize(FILE *stream);

int adf_convert(const char *fsrc, const char *fdest);

#endif // _CONVERT_H_INCLUDED_
