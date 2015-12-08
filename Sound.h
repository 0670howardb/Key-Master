#ifndef _SOUND_H
#define _SOUND_H

#include <LPC17xx.h>

void DACInit(void);
void playSound(int);
extern uint16_t pitch;
extern int sinWave[];

#endif
