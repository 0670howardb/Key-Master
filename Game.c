/* Brandon Howard
	 Key Master!
	 Embedded Systems
	 Game.c
*/

#include <lpc17xx.h>
#include "Piano.h"
#include "Game.h"
#include "Songs.h"
#include "Screen.h"
#include "Queue.h"

uint16_t keysToPlay = 0;
short state = 0;
short iNote = 0;
int counter = 0;
short health = MAX_HEALTH;

struct queue queues[NUMBER_OF_QUEUES];

// Performs Game Logic
void SysTick_Handler(void) {           

	if (counter != 100) {
		counter++;
	} else {
		// Check if note played is right.
		compareTargetAndActual();
		
		// Reset keysPressed
		keysPressed &= 0x00000000;
	
		// Switch to new note
		keysToPlay = marryHadALittleLamb[iNote];	
		iNote++;
		
		counter = 0;
		render = 1;
	}
	
}

void compareTargetAndActual() {
	if (keysToPlay == keysPressed) { // Success
		if (health < MAX_HEALTH) { 
			health++; 
		}
	} else { // Fail
		health--;
	} 
}

void updateQueues() {
	
	int i = 0; 
	for (i = 0; i < NUMBER_OF_QUEUES; i++) {
		dequeue(&queues[i]);
		enqueue(&queues[i], INACTIVE);
	}
	
	// Add proper values to queue
	if ((keysToPlay & 0x1000) == 0x1000) { // C0
		enqueue(&queues[12], ACTIVE);
	}
	if ((keysToPlay & 0x800) == 0x800) { // Cs
		enqueue(&queues[11], SHARP);
	}
	if ((keysToPlay & 0x400) == 0x400) { // D0
		enqueue(&queues[10], ACTIVE);
	}
	if ((keysToPlay & 0x200) == 0x200) { // Ds
		enqueue(&queues[9], SHARP);
	}
	if ((keysToPlay & 0x100) == 0x100) { // E0
		enqueue(&queues[8], ACTIVE);
	}
	if ((keysToPlay & 0x80) == 0x80) { // F0
		enqueue(&queues[7], ACTIVE);
	}
	if ((keysToPlay & 0x40) == 0x40) { // Fs
		enqueue(&queues[6], SHARP);
	}
	if ((keysToPlay & 0x20) == 0x20) { // G0
		enqueue(&queues[5], ACTIVE);
	}
	if ((keysToPlay & 0x10) == 0x10) { // Gs
		enqueue(&queues[4], SHARP);
	}
	if ((keysToPlay & 0x8) == 0x8) { // A0
		enqueue(&queues[3], ACTIVE);
	}
	if ((keysToPlay & 0x4) == 0x4) { // As
		enqueue(&queues[2], SHARP);
	}
	if ((keysToPlay & 0x2) == 0x2) { // B0
		enqueue(&queues[1], ACTIVE);
	}	
	if ((keysToPlay & 0x1) == 0x1) { // C1
		enqueue(&queues[0], ACTIVE);
	}	
}
