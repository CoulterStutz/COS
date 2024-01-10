#include "include/sys.h"

uint8_t inportb(uint16_t port) {
    uint8_t result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

void outportb(uint16_t port, uint8_t data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}
