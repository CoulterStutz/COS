// Used for doing mathematical operations
// Written by Coulter C. Stutz

#include "include/math.h"
#include "include/types.h"

double add(double a, double b) {
    double sum;
    sum = a + b;
    return sum;
}

double sub(double a, double b) {
    double difference;
    difference = a - b;
    return difference;
}

double mul(double a, double b) {
    double product;
    product = a * b;
    return product;
}

double div(double a, double b){
    double quotient;
    if (b != 0.0) {
        quotient = a / b;
    } else {
        // Handle division by zero if necessary, for now, returning 0
        quotient = 0.0;
    }
    return quotient;
}

double exp(double a, int exponent) {
    if (exponent == 0) {
        return 1;  // Any number to the power of 0 is 1
    }

    double c = a;
    if (exponent < 0) {
        c = 1 / a;  // Handle negative exponent
        exponent = -exponent;
    }

    for (uint16 i = 1; i < exponent; i++) {
        c *= a;
    }

    return c;
}