/* ADF Converter
 * File: convert.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include "convert.h"
#include "adfconv.h"
#include "progress.h"
#include <stdio.h>
#include <stdlib.h>

static int file_exists(const char *filename);
static size_t filesize(FILE *stream);

/* Convert ADF to MP3 and back. */
int adf_convert(const char *fsrc, const char *fdest) {
  int status = EXIT_FAILURE;
  FILE *src = NULL;
  FILE *dest = NULL;
  size_t i, count, fsiz;
  byte *buf = NULL;

  if (file_exists(fdest)) {
    fprintf(stderr, "Error: Destination file '%s' exists.\n", fdest);
    goto Cleanup;
  }

  src = fopen(fsrc, "rb");
  if (!src) {
    fprintf(stderr, "Error: Cannot open source file: '%s'.\n", fsrc);
    goto Cleanup;
  }

  dest = fopen(fdest, "wb");
  if (!dest) {
    fprintf(stderr, "Error: Cannot write destination file: '%s'.\n", fdest);
    goto Cleanup;
  }

  buf = (byte *)malloc(BUFSIZ);
  if (NULL == buf) {
    fprintf(stderr, "Error: Insufficient memory available.\n");
    goto Cleanup;
  }

  fsiz = filesize(src);
  printf("File name: %s\n"
         "Size: %ld bytes\n\n",
         fsrc, fsiz);

  progress_init(fsiz);

  while (!feof(src)) {
    count = fread(buf, sizeof(byte), BUFSIZ, src);

    for (i = 0; i < count; i++) {
      buf[i] ^= 0x22; /* Encrypt */
      progress_update();
    }

    fwrite(buf, sizeof(byte), count, dest);
  }

  progress_final();

  status = EXIT_SUCCESS;
  printf("Done!\n");

Cleanup:
  free(buf);

  if (NULL != dest) {
    fclose(dest);
  }

  if (NULL != src) {
    fclose(src);
  }

  return status;
}

/* Checking if a file exists. */
static int file_exists(const char *filename) {
  FILE *stream = fopen(filename, "r");
  if (stream != NULL) {
    fclose(stream);
    return 1;
  }
  return 0;
}

/* Get file size in bytes. */
static size_t filesize(FILE *stream) {
  size_t fsiz;
  fseek(stream, 0L, SEEK_END);
  fsiz = (size_t)ftell(stream);
  fseek(stream, 0L, SEEK_SET);
  return fsiz;
}
