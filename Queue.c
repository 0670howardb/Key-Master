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
	queues[7].activeColor = Cyan;
	queues[6].activeColor = DarkGreen;
	queues[5].activeColor = Purple;
	queues[4].activeColor = Red;
	queues[3].activeColor = Navy;
	queues[2].activeColor = Yellow;
	queues[1].activeColor = Green;
	queues[0].activeColor = Blue;
	
	queues[7].sharpColor = Black;
	queues[6].sharpColor = Black;
	queues[5].sharpColor = Black;
	queues[4].sharpColor = Black;
	queues[3].sharpColor = Black;
	queues[2].sharpColor = Black;
	queues[1].sharpColor = Black;
	queues[0].sharpColor = Black;
}
