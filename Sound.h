#ifndef _SOUND_H
#define _SOUND_H

#include <LPC17xx.h>

void DACInit(void);
void playSound(uint16_t[]);

/*
extern uint16_t c0Pitch;
extern uint16_t cSharpPitch;
extern uint16_t dPitch;
extern uint16_t dSharpPitch;
extern uint16_t ePitch;
extern uint16_t fPitch;
extern uint16_t fSharpPitch;
extern uint16_t gPitch;
extern uint16_t gSharpPitch;
extern uint16_t aPitch;
extern uint16_t aSharpPitch;
extern uint16_t bPitch;
extern uint16_t c1Pitch;
*/

extern uint16_t GusSinTable[];

#endif
