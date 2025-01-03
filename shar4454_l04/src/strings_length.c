/**
 * -------------------------------------
 * @file  strings_length.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_length(strings_array *data, FILE *fp_short, FILE *fp_long, int length) {

    for (int i = 0; i < data->lines; i++) {
        char *currstring = data->strings[i];

        int strinlength = strlen(currstring);

        if (strinlength < length) {
            fprintf(fp_short, "%s\n", currstring);

        } else {
            fprintf(fp_long, "%s\n", currstring);
        }

    }

}


