/* Brandon Howard
	 Key Master!
	 Embedded Systems
	 Game.c
*/

#include <lpc17xx.h>
#include "stdio.h"
#include "Piano.h"
#include "Game.h"
#include "Songs.h"
#include "Screen.h"
#include "Queue.h"
#include "LED.h"
#include "GLCD.h"

uint16_t keysToPlay = 0;
uint16_t keysToQueue = 0;
short state = 0;
short iNote = 0;
int counter = 0;
short health = MAX_HEALTH;
struct queue queues[NUMBER_OF_QUEUES];
enum gameState currentState;
enum songs currentSong;

// Performs Game Logic
void SysTick_Handler(void) {           
	if (currentState == PLAY) {
		if (counter != 100) {
			counter++;
		} else {
			// Check if note played is right.
			compareTargetAndActual();
			
			// Reset keysPressed
			keysPressed &= 0x00000000;
	
			// Switch to new note and check if song is over
			selectNextNote();
			
			counter = 0;
			render = 1;
		}
	}
}

void compareTargetAndActual() {
	if (keysToPlay == keysPressed) { // Success
		if (health < MAX_HEALTH) { 
			health++; 
		}
	} else { // Fail
		health--;
		if (health == 0) {
			currentState = LOSE;
		}
	} 
}

void updateQueues() {
	
	int i = 0; 
	for (i = 0; i < NUMBER_OF_QUEUES; i++) {
		dequeue(&queues[i]);
		enqueue(&queues[i], INACTIVE);
	}
	
	// Add proper values to queue
	if ((keysToQueue & 0x1000) == 0x1000) { // C0
		enqueue(&queues[12], ACTIVE);
	}
	if ((keysToQueue & 0x800) == 0x800) { // Cs
		enqueue(&queues[11], ACTIVE);
	}
	if ((keysToQueue & 0x400) == 0x400) { // D0
		enqueue(&queues[10], ACTIVE);
	}
	if ((keysToQueue & 0x200) == 0x200) { // Ds
		enqueue(&queues[9], ACTIVE);
	}
	if ((keysToQueue & 0x100) == 0x100) { // E0
		enqueue(&queues[8], ACTIVE);
	}
	if ((keysToQueue & 0x80) == 0x80) { // F0
		enqueue(&queues[7], ACTIVE);
	}
	if ((keysToQueue & 0x40) == 0x40) { // Fs
		enqueue(&queues[6], ACTIVE);
	}
	if ((keysToQueue & 0x20) == 0x20) { // G0
		enqueue(&queues[5], ACTIVE);
	}
	if ((keysToQueue & 0x10) == 0x10) { // Gs
		enqueue(&queues[4], ACTIVE);
	}
	if ((keysToQueue & 0x8) == 0x8) { // A0
		enqueue(&queues[3], ACTIVE);
	}
	if ((keysToQueue & 0x4) == 0x4) { // As
		enqueue(&queues[2], ACTIVE);
	}
	if ((keysToQueue & 0x2) == 0x2) { // B0
		enqueue(&queues[1], ACTIVE);
	}	
	if ((keysToQueue & 0x1) == 0x1) { // C1
		enqueue(&queues[0], ACTIVE);
	}	
}

void resetGameVariables() {
	initQueues();
	iNote = 0;
	keysToPlay = 0;
	keysToQueue = 0;
	counter = 0;
	health = MAX_HEALTH;
	keysPressed = 0;
}

void selectNextNote() {
	// Start queueing first note of song, this is a silly way to do this, and should be modified in a revision.
	// The plus 7 is necessary because I want to start queueing the first actual note of the song, but it still needs
	// to be shifted 8 times before it's time to play that note.
	
	switch (currentSong) {
		case ODE_TO_JOY:
			if (iNote > odeToJoyLength)
				currentState = WIN;
			keysToPlay = odeToJoy[iNote];
			keysToQueue = odeToJoy[iNote + 7];
			break;
			
		case MARY_HAD_A_LITTLE_LAMB:
			if (iNote > maryHadALittleLambLength)
				currentState = WIN;
			keysToPlay = maryHadALittleLamb[iNote];
			keysToQueue = maryHadALittleLamb[iNote + 7];
			break;
			
		case IMPERIAL_MARCH:
			if (iNote > imperialMarchLength)
			currentState = WIN;
			keysToPlay = imperialMarch[iNote];
			keysToQueue = imperialMarch[iNote + 7];						
			break;
			
		case JINGLE_BELLS:
			if (iNote > jingleBellsLength)
				currentState = WIN;
			keysToPlay = jingleBells[iNote];
			keysToQueue = jingleBells[iNote + 7];						
			break;
			
		case DO_RE_MI:
			if (iNote > doReMiLength)
				currentState = WIN;
			keysToPlay = doReMi[iNote];
			keysToQueue = doReMi[iNote + 7];			
			break;
			
		case HEART_AND_SOUL:
			if (iNote > heartAndSoulLength)
				currentState = WIN;
			keysToPlay = heartAndSoul[iNote];
			keysToQueue = heartAndSoul[iNote + 7];						
			break;
			
		case THE_FINAL_COUNTDOWN:
			if (iNote > theFinalCountdownLength)
				currentState = WIN;
			keysToPlay = theFinalCountdown[iNote];
			keysToQueue = theFinalCountdown[iNote + 7];						
			break;
			
		case OLD_MCDONALD:
			if (iNote > oldMcDonaldLength)
				currentState = WIN;
			keysToPlay = oldMcDonald[iNote];
			keysToQueue = oldMcDonald[iNote + 7];						
			break;
	}
	
		iNote++;
}

void displayWinMessage() {
	LCD_Clear(Black);
	LCD_PutText(75, 120, "YOU WIN!  :D", White, Black);
}

void displayLoseMessage() {
	LCD_Clear(Black);
	LCD_PutText(75, 120, "YOU LOSE! :(", White, Black);
}
