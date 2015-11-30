/* Brandon Howard */

#include "Screen.h"
#include "GLCD.h"

short render = 1;
int scaledX = 0;
int scaledY = 0;

/* Given the scaled x and y coordinate passed into
	 this function, a square of PIXEL_SIZE (defined
	 in screen.h) is drawn at the actual x and y
	 coordinate. The color must be set prior to
	 calling this function.
*/
void fillSquare(int x, int y) {
	int iX = 0;
	int iY = 0;
	x = x*PIXEL_SIZE;
	y = y*PIXEL_SIZE;
	
	for (iX = x; iX < x + PIXEL_SIZE; iX++)
		for (iY = y; iY < y + PIXEL_SIZE; iY++)
			GLCD_PutPixel(iX, iY);
}

/* This function maps a PIXEL_SIZE block of pixels
	 to a single pixel for the scaled value. A scaled 
	 value is reconverted to the correct pixels in the
	 fillSquare function is called.
*/
void setupGrid() {
	scaledX = SCREEN_WIDTH / PIXEL_SIZE;
	scaledY = SCREEN_HEIGHT / PIXEL_SIZE;
}
