/* Brandon Howard */

#include "Screen.h"
#include "GLCD.h"
#include "Queue.h"
#include "Game.h"

short render = 1;
int scaledX = 0;
int scaledY = 0;

/* Given the scaled x and y coordinate passed into
	 this function, a square of PIXEL_SIZE (defined
	 in screen.h) is drawn at the actual x and y
	 coordinate. The color must be set prior to
	 calling this function.
*/
void fillSquare(int x, int y, uint16_t color) {
	int iX = 0;
	int iY = 0;
	x = x*PIXEL_SIZE + 20;
	y = y*PIXEL_SIZE + 3;
	
	for (iX = x+1; iX < x + PIXEL_SIZE; iX++)
		for (iY = y+1; iY < y + PIXEL_SIZE; iY++)
			 LCD_SetPoint(iX + 20, iY, color); // Note: + 20 because 320%30 ~= 20, shift for writing text.
}

/* This function maps a PIXEL_SIZE block of pixels
	 to a single pixel for the scaled value. A scaled 
	 value is reconverted to the correct pixels in the
	 fillSquare function is called.
*/
void setupGrid() {
	int x = 0;
	int y = 0;
	
	scaledX = SCREEN_WIDTH / PIXEL_SIZE;
	scaledY = SCREEN_HEIGHT / PIXEL_SIZE;
	
	for (x = 0; x < SCALED_X; x++)
		for (y = 0; y < SCALED_Y; y++)
			fillSquare(x, y, White);
}

void drawScreen() {
	
	int i = 0;
	int iElement = 0;
	for (i = 0; i < NUMBER_OF_QUEUES; i++) {
		for (iElement = 0; iElement < QUEUE_LENGTH; iElement++) {
			// There are six cases to be concerned about.
			// The seventh is when they are equal. Do nothing in this case.
			if (queues[i].queue[iElement] == queues[i].previousQueue[iElement]) {
				// Do nothing.
			} else  if (queues[i].queue[iElement] == INACTIVE && queues[i].previousQueue[iElement] == ACTIVE) {
				fillSquare(iElement, i, White);
			} else  if (queues[i].queue[iElement] == INACTIVE && queues[i].previousQueue[iElement] == SHARP) {
				fillSquare(iElement, i, White);
			} else  if (queues[i].queue[iElement] == ACTIVE && queues[i].previousQueue[iElement] == INACTIVE) {
				fillSquare(iElement, i, queues[i].activeColor);
			} else  if (queues[i].queue[iElement] == ACTIVE && queues[i].previousQueue[iElement] == SHARP) {
				fillSquare(iElement, i, queues[i].activeColor);
			} else  if (queues[i].queue[iElement] == SHARP && queues[i].previousQueue[iElement] == INACTIVE) {
				fillSquare(iElement, i, queues[i].sharpColor);
			} else  if (queues[i].queue[iElement] == SHARP && queues[i].previousQueue[iElement] == ACTIVE) {
				fillSquare(iElement, i, queues[i].sharpColor);
			}
		}
	}
	
}
