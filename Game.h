#ifndef _GAME_H
#define _GAME_H

#include <lpc17xx.h>
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define MAX_HEALTH 8
#define NUMBER_OF_QUEUES 13

void compareTargetAndActual(void);
void updateQueues(void);
void resetGameVariables(void);
void selectNextNote(void);
void displayWinMessage(void);
void displayLoseMessage(void);
void checkIfSongIsOver(void);

extern uint16_t keysToPlay;
extern uint16_t keysToQueue;
extern short state;
extern uint16_t keysPressed;
extern short health;
extern struct queue queues[];

enum keyType {
	INACTIVE,
	ACTIVE
};

enum gameState {
	MENU,
	PLAY,
	WIN,
	LOSE
};

enum songs {
	ODE_TO_JOY,
	MARY_HAD_A_LITTLE_LAMB,
	IMPERIAL_MARCH,
	JINGLE_BELLS,
	DO_RE_MI,
	TAKE_ON_ME,
	THE_FINAL_COUNTDOWN,
	OLD_MCDONALD
};

extern enum songs currentSong;
extern enum gameState currentState;

#endif
