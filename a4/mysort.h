/*
 * your program signature
 */ 

#ifndef MYSORT_H
#define MYSORT_H 

/**
 * Use selection sort algorithm to sort array of float pointers such that their pointed values are incresing order.
 *
 * @param *a[] - array of float pointers.
 * @param left - the start index of float pointer in array.
 * @param right - the end index of float pointer in array
 */
void select_sort_inc(float *a[], int left, int right);

/**
 * Use quick sort algorithm to sort array of float pointers such that their pointed values are incresing order.
 *
 * @param *a[] - array of float pointers.
 * @param left - the start index of float pointer in array.
 * @param right - the end index of float pointer in array
 */
void quick_sort_inc(float *a[], int left, int right);

/**
 * An auxillary swap function for selection sort function.
 * 
*/
void swap(float **x, float **y);

#endif