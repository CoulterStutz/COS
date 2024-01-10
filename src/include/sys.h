// sys.h
// Written by IKnowYourBrain for free use with bare-metal C programming
//      Youtube: https://www.youtube.com/@iknowbrain
//      Github: https://github.com/iknowbrain
//      Bitcoin: 13jStC1PWwZttLc8rhG6Xn1UeKE7rAP6hQ

#ifndef SYS_H
#define SYS_H

#include "types.h"  // Assuming this includes type definitions like uint8_t, uint16_t, etc.

// Function prototype for reading a byte from an I/O port
uint8_t inportb(uint16_t port);

// Function prototype for writing a byte to an I/O port
void outportb(uint16_t port, uint8_t data);

// Additional system-level function prototypes
// ...

#endif // SYS_H
