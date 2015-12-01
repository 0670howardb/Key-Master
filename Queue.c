/* Brandon Howard
	 Key Master!
	 Embedded Systems
	 Queue.c
*/

#include <lpc17xx.h>
#include "Queue.h"
#include "Piano.h"
#include "Game.h"
#include "Songs.h"

void enqueue(struct queue *q, int item) {
	q->queue[QUEUE_LENGTH - 1] = item;
}

int dequeue(struct queue *q) {
	
	int i = 0;
	int returnValue = q->queue[0];
	
	// Make a copy of the old queue (for comparing later).
	for (i = 0; i < QUEUE_LENGTH; i++) {
		q->previousQueue[i] = q->queue[i];
	}
	
	// Shift everything down
	for (i = 0; i < QUEUE_LENGTH - 1; i++) {
		q->queue[i] = q->queue[i+1];
	}
	
	return returnValue;

}
