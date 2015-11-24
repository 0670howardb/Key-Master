/* Brandon Howard
	 Key Master!
	 Embedded Systems
	 Game.c
*/

#include <lpc17xx.h>
#include "Piano.h"
#include "Game.h"
#include "Songs.h"

uint16_t keysToPlay = 0;
short state = 0;
short iNote = 0;
int counter = -10;
short health = MAX_HEALTH;

// Performs Game Logic
void SysTick_Handler (void) {           

	if (counter != 100) {
		counter++;
	} else {
		// Check if note played is right.
		compareTargetAndActual();
		
		// Reset keysPressed
		keysPressed &= 0x00000000;
	
		// Switch to new note
		iNote++;
		keysToPlay = marryHadALittleLamb[iNote];
		counter = 0;
	}
	
}

void compareTargetAndActual() {
	if (keysToPlay == keysPressed) { // Success
		if (health < MAX_HEALTH) { health++; }
	} else { // Fail
		health--;
	} 
}
