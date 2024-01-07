// screen.h
// Written by IKnowYourBrain for free use with bare-metal C programming
//      Youtube: https://www.youtube.com/@iknowbrain
//      Github: https://github.com/iknowbrain
//      Bitcoin: 13jStC1PWwZttLc8rhG6Xn1UeKE7rAP6hQ

#ifndef SYSTEM_H
#define SYSTEM_H
#include "types.h"
uint8 inportb (uint16 _port)
{
    	uint8 rv;
    	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    	return rv;
}

void outportb (uint16 _port, uint8 _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

#endif
