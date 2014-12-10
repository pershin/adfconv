#ifndef _CONVERT_H_INCLUDED_
#define _CONVERT_H_INCLUDED_

#define BUFFER_MALLOC 1048576

typedef unsigned char byte;

int file_exists(const char *filename);

unsigned long long int filesize(FILE *stream);

int adf_convert(const char *src_filename, const char *dest_filename, int mode);

#endif // _CONVERT_H_INCLUDED_
