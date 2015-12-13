/* Brandon Howard */

#include "Screen.h"
#include "GLCD.h"
#include "Queue.h"
#include "Game.h"

short menuRender = 1;
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
	 fillSquare function is called. It also draws the
	 initial grid for the notes.
*/
void setupGrid() {
	int x = 0;
	int y = 0;
	
	LCD_Clear(Black);
	
	scaledX = SCREEN_WIDTH / PIXEL_SIZE;
	scaledY = SCREEN_HEIGHT / PIXEL_SIZE;
	
	for (x = 0; x < SCALED_X; x++)
		for (y = 0; y < SCALED_Y; y++)
			fillSquare(x, y, White);
}

/* This function draws the screen during gameplay. It
	 does not draw the menu screen or win/lose screens.
*/
void drawScreen() {
	
	int i = 0;
	int iElement = 0;
	for (i = 0; i < NUMBER_OF_QUEUES; i++) {
		for (iElement = 0; iElement < QUEUE_LENGTH; iElement++) {
			if (queues[i].queue[iElement] == queues[i].previousQueue[iElement]) {
				// Do nothing.
			} else  if (queues[i].queue[iElement] == INACTIVE && queues[i].previousQueue[iElement] == ACTIVE) {
				fillSquare(iElement, i, White);
			} else {
				fillSquare(iElement, i, queues[i].activeColor);
			}
		}
	}
}

/* Draw the menu screen, centered horizontally. */
void drawMenu() {
	LCD_Clear(White);
	LCD_PutText(75, 10,  "Key Master!", Black, White);
	LCD_PutText(65, 40,  "Select a Song!", Black, White);
	LCD_PutText(5 , 70,  "C: Ode to Joy", Black, White);
	LCD_PutText(5 , 100, "D: Mary Had a Little Lamb", Black, White);
	LCD_PutText(5 , 130, "E: Imperial March", Black, White);
	LCD_PutText(5 , 160, "F: Jingle Bells", Black, White);
	LCD_PutText(5 , 190, "G: Do Re Mi (Sound of Music)", Black, White);
	LCD_PutText(5 , 220, "A: Heart and Soul", Black, White);
	LCD_PutText(5 , 250, "B: The Final Countdown", Black, White);
	LCD_PutText(5 , 280, "C: Old McDonald", Black, White);
}
	
