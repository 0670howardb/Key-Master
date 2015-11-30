#ifndef __SCREEN_H 
#define __SCREEN_H

#define PIXEL_SIZE 30
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

void fillSquare(int, int);
void setupGrid(void);

extern int scaledX;
extern int scaledY;
extern short render;

#endif 
