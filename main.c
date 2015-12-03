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
#include "LED.h"

void printKeys(void);
void printHealth(void);
void dirtyDelay(int);
//unsigned char printString[15];

int main (void) {
  SystemInit();
	SysTick_Config(SystemCoreClock/100);
	LCD_Initialization();
	LCD_Clear(Black);
	LED_Init();
	Piano_Init();
	currentState = MENU;
	
	
  while (1) {
		switch (currentState) {
			case MENU:
				if (menuRender) {
					drawMenu();
					resetGameVariables();
					menuRender = 0;
				}
				checkKeys();
				handleKeyPress();
				selectSongFromKeyPress();
				break;
			
			case PLAY:
				checkKeys();
				handleKeyPress();
				LED_MultipleOff(health);
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
				displayWinMessage();
				menuRender = 1;
				dirtyDelay(1);
				break;
			
			case LOSE:
				currentState = MENU;
				resetGameVariables();
				displayLoseMessage();
				menuRender = 1;
				dirtyDelay(1);
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

void dirtyDelay(int time) {
	int i = 0;
	for (i = 0; i < time * 25000000; i++) {
		// Do nothing. Dirty delay.
	}
}

