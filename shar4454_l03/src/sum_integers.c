/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author name, id, email
 *
 * @version 2024-01-25
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {

    // your code here
    int sum = 0;
	char buffer[100];
	int number;

	printf("Enter integers, one per line:\n");

	while (1) {
	    if (!fgets(buffer, sizeof(buffer), stdin)) {

	        break;
	    }


	    if (sscanf(buffer, "%d", &number) == 1) {
	        sum += number;
	    } else {

	        break;
	    }
	}

	return sum;

}
