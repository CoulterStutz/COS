#include "include/string.h"

// Function to calculate the length of a string
uint16 strlength(string ch) {
    uint16 length = 0;
    while (ch[length] != '\0') {
        length++;
    }
    return length;
}

// Function to compare two strings (returns 1 if equal, 0 otherwise)
uint8 strEql(string ch1, string ch2) {
    uint16 i = 0;
    while (ch1[i] == ch2[i]) {
        if (ch1[i] == '\0') return 1;
        i++;
    }
    return 0;
}

// Function to copy a string from src to dest
void strcpy(string dest, string src) {
    uint16 i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Null-terminate the destination string
}

// Function to concatenate two strings
void strcat(string dest, string src) {
    uint16 dest_len = strlength(dest);
    uint16 i = 0;

    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0'; // Null-terminate the destination string
}

// Function to compare two strings (returns 0 if equal, <0 if ch1 < ch2, >0 if ch1 > ch2)
int strcmp(string ch1, string ch2) {
    while (*ch1 && (*ch1 == *ch2)) {
        ch1++;
        ch2++;
    }
    return *(const unsigned char*)ch1 - *(const unsigned char*)ch2;
}
