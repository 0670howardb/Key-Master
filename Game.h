#ifndef _GAME_H
#define _GAME_H

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define MAX_HEALTH 8

void compareTargetAndActual(void);

extern uint16_t keysToPlay;
extern short state;
extern uint16_t keysPressed;
extern short health;

#endif
