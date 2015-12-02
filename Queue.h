#ifndef _QUEUE_H
#define _QUEUE_H

#define QUEUE_LENGTH 8

struct queue {
	int queue[QUEUE_LENGTH];
	int previousQueue[QUEUE_LENGTH];
	unsigned short activeColor;
	int y;
};

void enqueue(struct queue*, int);
int dequeue(struct queue*);
void initQueues(void);

#endif
