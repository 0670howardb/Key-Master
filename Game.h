#ifndef _GAME_H
#define _GAME_H

#include <lpc17xx.h>
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define MAX_HEALTH 8
#define NUMBER_OF_QUEUES 13

void compareTargetAndActual(void);
void updateQueues(void);

extern uint16_t keysToPlay;
extern short state;
extern uint16_t keysPressed;
extern short health;
extern struct queue queues[];

enum keyType {
	INACTIVE,
	ACTIVE,
	SHARP
};

#endif
