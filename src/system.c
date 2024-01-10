// Used for system functions
// Written by Coulter C. Stutz

#include "include/system.h"

// System Interaction Functions

// System Information Functions
void get_cpu_vendor(char *vendor) {
    return; // coming soon
}

// System Based Functions
void delay(int count) {
    volatile int i;
    for (i = 0; i < count; i++) {
        __asm__("nop"); // No Operation
    } 
}