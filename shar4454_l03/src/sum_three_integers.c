/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2023-09-09
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {

    // your code here
    int num1, num2, num3;
    int sum;

    do {
        printf("Enter three comma-separated integers: ");

        if (scanf("%d,%d,%d", &num1, &num2, &num3) == 3) {
            sum = num1 + num2 + num3;
            break; 
        } else {
            
            printf("The integers were not properly entered.\n");
            while (getchar() != '\n'); 
        }
    } while (1); 

    return sum;

}
