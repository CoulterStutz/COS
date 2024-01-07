#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"
#include "system.h"
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

// Prints a string in default color
void print(string ch) {
    uint16 i = 0;
    uint8 length = strlength(ch);
    for(; i < length; i++) {
        printch(ch[i]);
    }
}

// Function to print string in red
void print_red(string ch) {
    // Similar to print but with red color code
}

// Function to print string in blue
void print_blue(string ch) {
    // Similar to print but with blue color code
}

// Function to print string in pink
void print_pink(string ch) {
    // Similar to print but with pink color code
}

// Function to print string in cyan
void print_cyan(string ch) {
    // Similar to print but with cyan color code
}

// Add implementation for color printing functions here...

#endif
