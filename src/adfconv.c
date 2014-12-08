/* ADF Converter
 *
 * How to compile the code (example):
 * cc adfconv.c convert.c progress_bar.c -o adfconv
 * cl adfconv.c convert.c progress_bar.c
 *
 * File: adfconv.c
 * Author: Sergey Pershin <sergey dot pershin at hotmail dot com>
 */

#include <stdio.h>
#include "adfconv.h"
#include "convert.h"

int main(int argc, const char *argv[])
{
    if (argc == 3) {
        if (adf_convert(argv[1], argv[2]))
            printf("\nDone!\n");
    } else {
        printf("Converter ADF (GTA Vice City) to MP3 and back.\n"
            "Version: " ADFCONV_VERSION "\n\n"
            "ADFCONV source destination\n");
    }
    return 0;
}
