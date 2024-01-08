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

double exp(double a, int exponent){
    uint16 i = 1;
    double c = a;
    for (; i < exponent; i++){
        c = c * a;
    }

    return c;
}