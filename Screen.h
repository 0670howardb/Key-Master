#ifndef __SCREEN_H 
#define __SCREEN_H

#include <lpc17xx.h>

#define PIXEL_SIZE 24
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCALED_X 8
#define SCALED_Y 13

void fillSquare(int, int, uint16_t color);
void fillSquareWithSharpSign(int, int, uint16_t color);
void setupGrid(void);
void drawScreen(void);

extern int scaledX;
extern int scaledY;
extern short render;

#endif 
