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

#include <stdio.h>
#include "adfconv.h"
#include "convert.h"

void usage()
{
    printf("Converter ADF (GTA Vice City) to MP3 and back.\n"
           "Version: " ADFCONV_VERSION "\n\n"
           "Usage: adfconv <source> <destination> [-b]\n");
}

int main(int argc, const char *argv[])
{
    if (argc == 3) {
        adf_convert(argv[1], argv[2], 1);
    } else if (argc == 4) {

        if (strcmp(argv[3], "-b") == 0) {
            adf_convert(argv[1], argv[2], 2);
        } else {
            usage();
        }
    } else {
        usage();
    }
    return 0;
}
