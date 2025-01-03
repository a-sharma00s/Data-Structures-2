#include "factorial.h"

int factorial(n) {
    // check for negative input
    if (n < 0) {
        return -1;
    }

    // initialize result
    int result = 1;

    // use for loop for computing n! and check for overflow
    for (int i = 1; i <= n; ++i ) {
        int nextFactorial = i * result;

        // overflow check
        if (result != nextFactorial / i) {
            return 0;
        } 

        // update result
        result = nextFactorial;
    }

    return result;
}