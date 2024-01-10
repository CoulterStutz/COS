#ifndef STRING_H
#define STRING_H

#include "types.h"  // Assuming types.h defines uint16, etc.

typedef char* string;  // Define string as a pointer to char

// Function prototype to calculate the length of a string
uint16 strlength(string ch);

// Function prototype to compare two strings (returns 1 if equal, 0 otherwise)
uint8 strEql(string ch1, string ch2);

// Function prototype to copy a string from src to dest
void strcpy(string dest, string src);

// Function prototype to concatenate two strings
void strcat(string dest, string src);

// Function prototype to compare two strings (returns 0 if equal, <0 if ch1 < ch2, >0 if ch1 > ch2)
int strcmp(string ch1, string ch2);

#endif // STRING_H
