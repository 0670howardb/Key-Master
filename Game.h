#ifndef _GAME_H
#define _GAME_H

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define MAX_HEALTH 8

void compareTargetAndActual(void);
void updateQueues(void);

extern uint16_t keysToPlay;
extern short state;
extern uint16_t keysPressed;
extern short health;

extern struct queue C0Queue;
extern struct queue D0Queue;
extern struct queue E0Queue;
extern struct queue F0Queue;
extern struct queue G0Queue;
extern struct queue A0Queue;
extern struct queue B0Queue;
extern struct queue C1Queue;

#endif
