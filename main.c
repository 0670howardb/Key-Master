/* Brandon Howard
	 Key Master!
	 Embedded Systems
	 main.c
*/

#include <lpc17xx.h>
#include <stdio.h>
#include "GLCD.h"
#include "Piano.h"
#include "Game.h"
#include "Screen.h"
#include "Queue.h"

void printKeys(void);
void printHealth(void);

unsigned char printString[15];

int main (void) {
  SystemInit();
	SysTick_Config(SystemCoreClock/100);
	LCD_Initialization();
	LCD_Clear(Black);
	Piano_Init();
	initQueues();
	currentState = MENU;
	
		
  while (1) {
		switch (currentState) {
			case MENU:
				if (menuRender) {
					drawMenu();
					menuRender = 0;
				}
				checkKeys();
				handleKeyPress();
				selectSongFromKeyPress();
				break;
			
			case PLAY:
				checkKeys();
				handleKeyPress();
				if (menuRender) {
					setupGrid();
					printKeys();
					menuRender = 0;
				}
				if (render == 1) {
					updateQueues();
					drawScreen();
					render = 0;
				}	
				break;
				
			case WIN:
				currentState = MENU;
				break;
			
			case LOSE:
				currentState = MENU;
				break;
		}	
	}
}

void printKeys() {
	LCD_PutText(10, 8,   "C", White, Black);
	LCD_PutText(10, 32,  "B", White, Black);
	LCD_PutText(10, 56,  "A#", White, Black);
	LCD_PutText(10, 81,  "A", White, Black);
	LCD_PutText(10, 104, "G#", White, Black);
	LCD_PutText(10, 128, "G", White, Black);
	LCD_PutText(10, 152, "F#", White, Black);
	LCD_PutText(10, 176, "F", White, Black);
	LCD_PutText(10, 200, "E", White, Black);
	LCD_PutText(10, 224, "D#", White, Black);
	LCD_PutText(10, 248, "D", White, Black);
	LCD_PutText(10, 272, "C#", White, Black);
	LCD_PutText(10, 297, "C", White, Black);
}

void printHealth() {

}
