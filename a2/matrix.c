/*
 * your program signature
 */ 
#include <stdio.h>
#include <math.h>
#include "matrix.h"

/**
 *  add your comment
 */
float norm(float *v, int n) {
// your code
    int sum = 0;
    int a;
    for(int i = 0; i < n; ++i){
        a = v[i] * v[i];
        sum = sum + a;
    }
    int normal = sqrt(sum);
    return normal;
}

/**
 *  add your comment
 */
float dot_product(float *v1, float *v2, int n) {
// your code
    double result = 0.0;
    for(int i = 0; i < n; i++){
        result += v1[i] * v2[i];
    }
    return result;
}

/**
 *  add your comment
 */
void matrix_multiply_matrix(float *m1, float *m2, float *m3, int n) {
// your code
    float s = 0;
    int i, j, k;

    for (i = 0; i < n; i++) { //row
        for (j = 0; j < n; j++) { //column
            s = 0;
            for (k = 0; k < n; k++) {
                s += *(m1 + i * n+k) * *(m2 + k * n+j);

            }
            *(m3 + i * n + j) = s;
        }
    }

}

/**
 *  add your comment
 */
void matrix_multiply_vector(float *m, float *vin, float *vout, int n) {
// your code
    float s = 0;
    for (int i = 0; i < n; i++) {
        s = 0;
        for (int j = 0; j < n; j++) {
            s += *(m + i * n+j) * *(vin + j);
        }
        *(vout + i) = s;
    }
}