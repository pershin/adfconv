/* ADF Converter
 * File: convert.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include "progress.h"

/* Checking if a file exists. */
int file_exists(const char *filename)
{
    FILE *stream = fopen(filename, "r");
    if (stream != NULL) {
        fclose(stream);
        return 1;
    }
    return 0;
}

/* Get file size in bytes. */
unsigned long long int filesize(FILE *stream)
{
    unsigned long long int fsiz;
    fseek(stream, 0L, SEEK_END);
    fsiz = ftell(stream);
    fseek(stream, 0L, SEEK_SET);
    return fsiz;
}

/* Convert ADF to MP3 and back. */
int adf_convert(const char *fsrc, const char *fdest)
{
    FILE *src, *dest;
    int i, count;
    unsigned long long int fsiz;
    byte *buf;

    if (file_exists(fdest)) {
        printf("Error: Destination file '%s' exists.\n", fdest);
        return 0;
    }

    src = fopen(fsrc, "rb");
    if (!src) {
        printf("Error: Cannot open source file: '%s'.\n", fsrc);
        return 0;
    }

    dest = fopen(fdest, "wb");
    if (!dest) {
        fclose(src);
        printf("Error: Cannot write destination file: '%s'.\n", fdest);
        return 0;
    }

    fsiz = filesize(src);
    printf("File name: %s\n"
           "Size: %llu bytes\n\n", fsrc, fsiz);

    progress_bar_start(fsiz);

    buf = (byte *)malloc(BUFSIZ);

    while (!feof(src)) {
        count = fread(buf, sizeof(byte), BUFSIZ, src);

        for (i = 0; i < count; i++) {
            buf[i] = buf[i] ^ 0x22; /* Encrypt */
            progress_bar();
        }

        fwrite(buf, sizeof(byte), count, dest);
    }

    free(buf);

    progress_bar_stop();

    fclose(dest);
    fclose(src);

    printf("Done!\n");

    return 1;
}
