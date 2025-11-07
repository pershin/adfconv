#ifndef CONVERT_H
#define CONVERT_H

#include <stdio.h>

typedef unsigned char byte;

int file_exists(const char *filename);

unsigned long long int filesize(FILE *stream);

int adf_convert(const char *fsrc, const char *fdest);

#endif /* CONVERT_H */
