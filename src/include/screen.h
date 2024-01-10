// screen.h
// Partially Written by IKnowYourBrain for free use with bare-metal C programming
//      Youtube: https://www.youtube.com/@iknowbrain
//      Github: https://github.com/iknowbrain
//      Bitcoin: 13jStC1PWwZttLc8rhG6Xn1UeKE7rAP6hQ

#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "sys.h"
#include "string.h"

// Screen size and depth constants
const uint8 sw = 80, sh = 25, sd = 2;

// Cursor position
int cursorX = 0, cursorY = 0;

// Clears a line range on the screen
void clearLine(uint8 from, uint8 to) {
    uint16 i = sw * from * sd;
    string vidmem = (string)0xb8000;
    for(; i < (sw * to * sd); i += 2) {
        vidmem[i] = ' ';           // Set character to space
        vidmem[i + 1] = 0x07;      // Set attribute byte (e.g., light grey on black)
    }
}


// Updates the position of the cursor
void updateCursor() {
    unsigned temp = cursorY * sw + cursorX;
    outportb(0x3D4, 14);
    outportb(0x3D5, temp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, temp);
}

// Clears the entire screen and resets cursor position
void clearScreen() {
    clearLine(0, sh+1);
    cursorX = 0;
    cursorY = 0;
    updateCursor();
}

// Scrolls the screen up by a given number of lines
void scrollUp(uint8 lineNumber) {
    string vidmem = (string)0xb8000;
    uint16 i = 0;
    clearLine(0, lineNumber - 1);
    for(; i < sw * (sh - 1) * 2; i++) {
        vidmem[i] = vidmem[i + sw * 2 * lineNumber];
    }
    clearLine(sh - 1 - lineNumber, sh - 1);
    cursorY = (cursorY - lineNumber) < 0 ? 0 : cursorY - lineNumber;
    cursorX = cursorY == 0 ? 0 : cursorX;
    updateCursor();
}

// Checks if a new line is needed
void newLineCheck() {
    if(cursorY >= sh - 1) {
        scrollUp(1);
    }
}

// Prints a character on the screen at the cursor's position
void printch(char c) {
    string vidmem = (string)0xb8000;
    switch(c) {
        case (0x08): // Backspace
            if(cursorX > 0) {
                cursorX--;
                vidmem[(cursorY * sw + cursorX) * sd] = 0x00;
            }
            break;
        case ('\r'): // Carriage Return
            cursorX = 0;
            break;
        case ('\n'): // New Line
            cursorX = 0;
            cursorY++;
            break;
        default: // Regular character
            vidmem[((cursorY * sw + cursorX)) * sd] = c;
            vidmem[((cursorY * sw + cursorX)) * sd + 1] = 0x0F; // Default color (white)
            cursorX++;
            break;
    }
    if(cursorX >= sw) {
        cursorX = 0;
        cursorY++;
    }
    updateCursor();
    newLineCheck();
}

void printch_color(char c, uint8 color) {
    string vidmem = (string) 0xb8000;
    uint16 offset = (cursorY * sw + cursorX) * sd;

    switch(c) {
        case (0x08): // Backspace
            if(cursorX > 0) {
                cursorX--;
                vidmem[offset - 2] = ' ';
                vidmem[offset - 1] = color;
            }
            break;
        case ('\r'): // Carriage Return
            cursorX = 0;
            break;
        case ('\n'): // New Line
            cursorX = 0;
            cursorY++;
            break;
        default:
            vidmem[offset] = c;
            vidmem[offset + 1] = color;
            cursorX++; 
            break;
    }
    updateCursor(); // Update cursor position
    newLineCheck(); // Check for new line
}

// Prints a string in default color
void print(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for(; i < length; i++) {
        printch(ch[i]);
    }
}

void print_red(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for(; i < length; i++) {
        printch_color(ch[i], 0x04); // Red color
    }
}

void print_blue(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for(; i < length; i++) {
        printch_color(ch[i], 0x01); // Blue color
    }
}

void print_pink(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for(; i < length; i++) {
        printch_color(ch[i], 0x05); // Pink (Light Magenta) color
    }
}

void print_cyan(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for(; i < length; i++) {
        printch_color(ch[i], 0x03); // Cyan color
    }
}

// Function to print string in green
void print_green(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for (; i < length; i++) {
        printch_color(ch[i], 0x02); // Green color
    }
}

// Function to print string in gold
void print_gold(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for (; i < length; i++) {
        printch_color(ch[i], 0x06); // Gold color
    }
}

// Function to print string in light blue
void print_light_blue(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for (; i < length; i++) {
        printch_color(ch[i], 0x09); // Light Blue color
    }
}

// Function to print string in orange
void print_orange(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for (; i < length; i++) {
        printch_color(ch[i], 0x0C); // Orange color
    }
}

#endif
