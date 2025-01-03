/*
 * @author Ashish Sharma
 */ 

#include "mysort.h"

void swap(float **x, float **y) 
{
    float *temp = *y;
    *y = *x;
    *x = temp;
}

/**
 * Use selection sort algorithm to sort array of float pointers such that their pointed values are incresing order.
 *
 * @param *a[] - array of float pointers.
 * @param left - the start index of float pointer in array.
 * @param right - the end index of float pointer in array
 */
void select_sort_inc(float *a[], int left, int right)
{
    // your code
    int i, j, k;

    for (int i = left; i <= right; ++i) {
        k = i;

        for (j = i + 1; j <= right; ++j) {
            if (*a[j] < *a[k]) {
                k = j;
            }
        }

        if (i != k) {
            swap(&a[i], &a[k]);
        }
    }

}

/**
 * Use quick sort algorithm to sort array of float pointers such that their pointed values are incresing order.
 *
 * @param *a[] - array of float pointers.
 * @param left - the start index of float pointer in array.
 * @param right - the end index of float pointer in array
 */
void quick_sort_inc(float *a[], int left, int right)
{ 
    // your code
    if (left < right) {
        float *pivot = a[left];
        int i = left + 1;
        int j = right;

        while (i <= j) {
            while (i <= right && *a[i] <= *pivot)
                i++;
            while (j >= left && *a[j] > *pivot)
                j--;

            if (i < j) {
                swap(&a[i], &a[j]);
            }
        }

        swap(&a[left], &a[j]);

        quick_sort_inc(a, left, j - 1);
        quick_sort_inc(a, j + 1, right);
    }
}
