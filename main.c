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

void printKeyStatus(void);
void printTargetAndCurrent(void);
void printHealth(void);

unsigned char printString[15];

int main (void) {
  SystemInit();
	SysTick_Config(SystemCoreClock/100);
	GLCD_Init();
	GLCD_Clear(White);
	Piano_Init();
	setupGrid();
	
	GLCD_SetTextColor(Black);
	GLCD_SetBackColor(White);
	
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
	sprintf((char *)printString, "C: %x", C0);
	GLCD_DisplayString(0, 0, printString);
	sprintf((char *)printString, "D: %x", D0);
	GLCD_DisplayString(1, 0, printString);
	sprintf((char *)printString, "E: %x", E0);
	GLCD_DisplayString(2, 0, printString);
	sprintf((char *)printString, "F: %x", F0);
	GLCD_DisplayString(3, 0, printString);
	sprintf((char *)printString, "G: %x", G0);
	GLCD_DisplayString(4, 0, printString);
	sprintf((char *)printString, "A: %x", A0);
	GLCD_DisplayString(5, 0, printString);
	sprintf((char *)printString, "B: %x", B0);
	GLCD_DisplayString(6, 0, printString);
	sprintf((char *)printString, "C: %x", C1);
	GLCD_DisplayString(0, 13, printString);
	sprintf((char *)printString, "C#: %x", Cs);
	GLCD_DisplayString(0, 6, printString);
	sprintf((char *)printString, "D#: %x", Ds);
	GLCD_DisplayString(1, 6, printString);
	sprintf((char *)printString, "F#: %x", Fs);
	GLCD_DisplayString(3, 6, printString);
	sprintf((char *)printString, "G#: %x", Gs);
	GLCD_DisplayString(4, 6, printString);
	sprintf((char *)printString, "A#: %x", As);
	GLCD_DisplayString(5, 6, printString);
}

void printTargetAndCurrent() {
	sprintf((char *)printString, "Target : %x         ", keysToPlay);
	GLCD_DisplayString(8, 0, printString);
	sprintf((char *)printString, "Current: %x         ", keysPressed);
	GLCD_DisplayString(9, 0, printString);
}

void printHealth() {
	sprintf((char *)printString, "Health : %d         ", health);
	GLCD_DisplayString(7, 0, printString);
}
