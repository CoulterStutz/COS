// screen.h
// Partially Written by IKnowYourBrain for free use with bare-metal C programming
//      Youtube: https://www.youtube.com/@iknowbrain
//      Github: https://github.com/iknowbrain
//      Bitcoin: 13jStC1PWwZttLc8rhG6Xn1UeKE7rAP6hQ

#ifndef SCREEN_H
#define SCREEN_H

#include "types.h"  // Assuming types.h defines uint8_t, uint16_t, etc.

// Screen size constants
#define MAX_ROWS 25
#define MAX_COLS 80

// Attribute byte for our default color scheme
#define WHITE_ON_BLACK 0x0F

// Screen device I/O ports
#define REG_SCREEN_CTRL 0x3D4
#define REG_SCREEN_DATA 0x3D5

// Public kernel API
void clearScreen();
void print(char* message);
void print_at(char* message, int col, int row);
void print_char(char character, int col, int row, char attribute_byte);
void set_cursor(int col, int row);

// You might also have functions for color management
void print_red(char* message);
void print_blue(char* message);
void print_pink(char* message);
void print_cyan(char* message);
void print_green(char* message);
void print_gold(char* message);
void print_light_blue(char* message);
void print_orange(char* message);
void print_purple(char* message);

// ... other color functions ...

#endif // SCREEN_H
