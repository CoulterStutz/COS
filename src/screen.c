#include "screen.h"	
#include "types.h"  // Assuming this contains uint8_t, etc.	

// VGA's memory starts at 0xB8000	
#define VIDEO_ADDRESS 0xB8000	
#define MAX_ROWS 25	
#define MAX_COLS 80	

// Screen device I/O ports	
#define REG_SCREEN_CTRL 0x3D4	
#define REG_SCREEN_DATA 0x3D5	

// Global variables for cursor position	
int cursorX = 0, cursorY = 0;	

// Function to write a byte to a port	
void outportb(uint16_t port, uint8_t data) {	
    // Implementation depends on your system and compiler	
    // Typically involves inline assembly	
}	

// Function to get the screen offset for a row and column	
int get_screen_offset(int col, int row) {	
    return 2 * (row * MAX_COLS + col);	
}	

// Function to update the hardware cursor position	
void update_cursor() {	
    int offset = get_screen_offset(cursorX, cursorY);	
    outportb(REG_SCREEN_CTRL, 14);	
    outportb(REG_SCREEN_DATA, (offset >> 8) & 0xFF);	
    outportb(REG_SCREEN_CTRL, 15);	
    outportb(REG_SCREEN_DATA, offset & 0xFF);	
}	

// Function to print a character at a specified location	
void print_char(char character, int col, int row, char attribute_byte) {	
    uint8_t *vidmem = (uint8_t*) VIDEO_ADDRESS;	
    if (!attribute_byte) {	
        attribute_byte = WHITE_ON_BLACK; // default color	
    }	

    // If col and row are negative, we will print at current cursor location	
    if (col >= 0 && row >= 0) {	
        vidmem[get_screen_offset(col, row)] = character;	
        vidmem[get_screen_offset(col, row) + 1] = attribute_byte;	
    } else {	
        vidmem[get_screen_offset(cursorX, cursorY)] = character;	
        vidmem[get_screen_offset(cursorX, cursorY) + 1] = attribute_byte;	
    }	

    // Update the cursor position	
    if (character == '\n') {	
        cursorY++;	
        cursorX = 0;	
    } else {	
        cursorX++;	
        if (cursorX >= MAX_COLS) {	
            cursorX = 0;	
            cursorY++;	
        }	
    }	
    update_cursor();	
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

void print_purple(string ch) {	
    uint16 i = 0;	
    uint8 length = strlength(ch);	
    for (; i < length; i++) {	
        printch_color(ch[i], 0x05); // Purple color	
    }	
}