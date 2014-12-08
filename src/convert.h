#ifndef _CONVERT_H_INCLUDED_
#define _CONVERT_H_INCLUDED_

int file_exists(const char *filename);

long int filesize(FILE *stream);

int adf_convert(const char *src_filename, const char *dest_filename);

#endif // _CONVERT_H_INCLUDED_
