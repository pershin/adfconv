/* ADF Converter
 *
 * How to compile the code
 * Linux: cc adfconv.c convert.c progress.c -o adfconv
 * Windows: cl adfconv.c convert.c progress.c
 * DOS (Turbo C 2.01): tcc adfconv.c convert.c progress.c
 *
 * File: adfconv.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include "adfconv.h"
#include "convert.h"
#include <stdio.h>
#include <stdlib.h>

static void usage(const char *program_name);

int main(int argc, const char *argv[]) {
  int status;

  status = EXIT_FAILURE;

  if (argc == 3) {
    status = adf_convert(argv[1], argv[2]);
  } else {
    usage(argv[0]);
  }

  return status;
}

static void usage(const char *program_name) {
  printf("Converter ADF (GTA Vice City) to MP3 and back.\n"
         "Version: " ADFCONV_VERSION "\n\n"
         "Usage: %s <source> <destination>\n",
         program_name);
}
