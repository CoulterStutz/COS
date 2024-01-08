// Used for doing mathematical operations
// Written by Coulter C. Stutz

#include "include/math.h"
#include "include/types.h"

int add(int a, int b) {     // Integer Add
    int c;
    c = a + b;

    return c;
}

int sub(int a, int b) {     // Integer Sub
    int c;
    c = a - b;

    return c;
}

double mul(double a, double b) {   // Multiply
    double c;   // Product
    c = a * b;

    return c;
}

double div(double a, double b){    // Double 
    double c;   // Quotient
    if (b != 0.0) {
        c = a / b;
    } else {
        // Handle division by zero if necessary, for now, returning 0
        c = 0.0;
    }

    return c;
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

double dadd(double a, double b) {   // Double Add
    double sum;
    sum = a + b;

    return sum;
}

double dsub(double a, double b) {   // Double Sub
    double difference;
    difference = a - b;

    return difference;
}