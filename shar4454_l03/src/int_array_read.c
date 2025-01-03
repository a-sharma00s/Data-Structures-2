/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {

    // your code here
    printf("Enter %d values for an array of int.\n", size);

    for(int i = 0; i < size; i++) {
        printf("Value for index %d: ", i);

        while (scanf("%d", &array[i]) != 1) {
            printf("Not a valid integer\n");

            while (getchar() != '\n');

            printf("Value for index %d: ", i);
        }

        while (getchar() != '\n');
    }
}
