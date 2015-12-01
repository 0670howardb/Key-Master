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

void printKeyStatus(void);
void printTargetAndCurrent(void);
void printHealth(void);

unsigned char printString[15];

int main (void) {
  SystemInit();
	SysTick_Config(SystemCoreClock/100);
	LCD_Initialization();
	LCD_Clear(Black);
	Piano_Init();
	setupGrid();
	initQueues();
	
	printKeyStatus();
  while (1) {
		checkKeys();
		handleKeyPress();
		
		if (render == 1) {
			updateQueues();
			drawScreen();
			render = 0;
		}		
	}
}

void printKeyStatus() {
	LCD_PutText(3, 10, "C", White, Black);
	LCD_PutText(3, 30, "C#", White, Black);
	LCD_PutText(3, 50, "D", White, Black);
	LCD_PutText(3, 70, "D#", White, Black);
	//GLCD_DisplayString(1, 0, "B");
	//GLCD_DisplayString(2, 0, "A");
	//GLCD_DisplayString(3, 0, "G");
	//GLCD_DisplayString(4, 0, "F");
	//GLCD_DisplayString(5, 0, "E");
	//GLCD_DisplayString(6, 0, "D");
	//GLCD_DisplayString(7, 0, "C");
}

void printTargetAndCurrent() {
	//sprintf((char *)printString, "Target : %x         ", keysToPlay);
	//GLCD_DisplayString(8, 0, printString);
	//sprintf((char *)printString, "Current: %x         ", keysPressed);
	//GLCD_DisplayString(9, 0, printString);
}

void printHealth() {
	//sprintf((char *)printString, "Health : %d         ", health);
	//GLCD_DisplayString(7, 0, printString);
}
