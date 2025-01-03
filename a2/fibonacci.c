/**
 * your program signature
 */ 

#include "fibonacci.h"

/**
 *  add your comment
 */
int recursive_fibonacci(int n) {
    // your code
    if(n <= 1){
        return n;
    }
    else{
        return (recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2));
    }

}

/**
 *  add your comment
 */
int iterative_fibonacci(int n)
{
    // your code
    int f1 = 1;
    int f2 = 2;
    int temp;
    if(n <= 1){
        return n;
    }
    else{
        for(int i = 3; i <= n; ++i){
            temp = f2;
            f2 = f1 + f2;
            f1 = temp;
        }
    }
    return f1;
    
}

/**
 *  add your comment
 */
int dpbu_fibonacci(int *f, int n) {
    // your code
    f[n + 2];
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i <= n; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

/**
 *  add your comment
 */
int dptd_fibonacci(int *f, int n) {
    // your code
    if(f[n] > 0){
        return f[n];
    }
    else if(n <= 1){
        f[n] = n;
        return n;
    }
    else{
        f[n] = dptd_fibonacci(f, n - 2) + dptd_fibonacci(f, n - 1);
        return f[n];
    }
}