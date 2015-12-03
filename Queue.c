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
#include "GLCD.h"

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

void initQueues() {
	int i = 0;
	int j = 0;
	
	queues[12].activeColor = Yellow;
	queues[11].activeColor = Orange;
	queues[10].activeColor = Red;
	queues[9].activeColor  = Purple;
	queues[8].activeColor  = Olive;
	queues[7].activeColor  = Blue;
	queues[6].activeColor  = Green;
	queues[5].activeColor  = Yellow;
	queues[4].activeColor  = Orange;
	queues[3].activeColor  = Red;
	queues[2].activeColor  = Purple;
	queues[1].activeColor  = Olive;
	queues[0].activeColor  = Maroon;
	
	for (i = 0; i < NUMBER_OF_QUEUES; i++) {
		for (j = 0; j < QUEUE_LENGTH; j++) {
			queues[i].queue[j] = 0;
		}
	}
}
