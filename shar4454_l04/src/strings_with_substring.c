/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_with_substring(strings_array *data, char *substr) {

    for (int i = 0; i < data->lines; i++) {

        char *curr = data->strings[i];

        char *position = strstr(curr, substr);

        if (position != NULL) {
            printf("%s\n", curr);
        }

    }

}


