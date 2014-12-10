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
    unsigned long long int fsize;
    fseek(stream, 0L, SEEK_END);
    fsize = ftell(stream);
    fseek(stream, 0L, SEEK_SET);
    return fsize;
}

/* Convert ADF to MP3 and back. */
int adf_convert(const char *src_filename, const char *dest_filename, int mode)
{
    FILE *src_stream, *dest_stream;
    int i, count;
    unsigned long long int fsize;
    byte *buffer;

    if (file_exists(dest_filename)) {
        printf("Error: Destination file '%s' exists.\n", dest_filename);
        return 0;
    }

    src_stream = fopen(src_filename, "rb");
    if (!src_stream) {
        printf("Error: Cannot open source file: '%s'.\n", src_filename);
        return 0;
    }

    dest_stream = fopen(dest_filename, "wb");
    if (!dest_stream) {
        fclose(src_stream);
        printf("Error: Cannot write destination file: '%s'.\n", dest_filename);
        return 0;
    }

    fsize = filesize(src_stream);
    printf("File name: %s\n"
        "Size: %llu bytes\n\n", src_filename, fsize);

    progress_bar_start(fsize);

    /* Reading a file, block per block. */
    if (mode == 1) {
        buffer = (byte *)malloc(BUFFER_MALLOC);

        while (!feof(src_stream)) {
            count = fread(buffer, sizeof(byte), BUFFER_MALLOC, src_stream);

            for (i = 0; i < count; i++) {
                buffer[i] = buffer[i] ^ 0x22; /* Encrypt */
                progress_bar();
            }

            fwrite(buffer, sizeof(byte), count, dest_stream);
        }

        free(buffer);
    }

    /* Reading a file, byte per byte. */
    if (mode == 2) {
        byte byte;

        while (!feof(src_stream)) {
            byte = getc(src_stream);
            byte = byte ^ 0x22; /* Encrypt */

            if (!feof(src_stream))
                putc(byte, dest_stream);

            progress_bar();
        }
    }

    progress_bar_stop();

    fclose(dest_stream);
    fclose(src_stream);

    printf("Done!\n");

    return 1;
}
