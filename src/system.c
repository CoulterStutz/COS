// Used for system functions
// Written by Coulter C. Stutz

#include "include/system.h"
#include "include/sys.h"
#include "include/types.h"

// System Interaction Functions

void halt(){
    asm("hlt");
}

// System Information Functions
void get_cpu_vendor(char *vendor) {
    return; // coming soon
}

// System Based Functions
void delay(int count) {     // Feeling Quirky might move to Terminal.c
    volatile int i;
    for (i = 0; i < count; i++) {
        __asm__("nop"); // No Operation
    } 
}
