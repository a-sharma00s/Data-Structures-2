/*
 * your program signature
 */ 

#include <stdio.h>
#include <math.h>
#include "polynomial.h"

#define EPSILON 1e-6

/**
 *  add your comment
 */
float horner(float *p, int n, float x)
{
// your code
    float r = 0;
    for (int i = 0; i < n; i++) {
        r = r*x + p[i];
    }
    return r;
}

/**
 *  add your comment
 */
float bisection(float *p, int n, float a, float b)
{
// your code
    float c = 0;

    while (fabs(a-b) > EPSILON) {
        c = (a+b) / 2;
        
        if (fabs(horner(p, n, c)) < EPSILON) {
            return c;
        }

        if (horner(p, n, c) * horner(p, n, a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    
    return c;
}