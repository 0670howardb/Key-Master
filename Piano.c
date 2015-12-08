/* Brandon Howard
	 Final Project - Key Master!
	 Embedded Systems
	 Piano.c
*/

#include <lpc17xx.h>
#include "Piano.h"
#include "Game.h"
#include "Screen.h"
#include "Sound.h"

uint16_t keysPressed = 0;

short C0 = 0;
short D0 = 0;
short E0 = 0;
short F0 = 0;
short G0 = 0;
short A0 = 0;
short B0 = 0;
short C1 = 0;
short Cs = 0;
short Ds = 0;
short Fs = 0;
short Gs = 0;
short As = 0;

void Piano_Init() {
	LPC_SC->PCONP |= ( 1 << 15 );
	LPC_GPIO2->FIODIR &= ~((1 << 10)|(1 << 11)|(1 << 12));
	LPC_GPIO1->FIODIR &= ~((1 << 16)|(1 << 17)|(1 << 26)
	                      |(1 << 25)|(1 << 23)|(1 << 21)
	                      |(1 << 20)|(1 << 19));
	LPC_GPIO0->FIODIR &= ~((1 <<  4)|(1 <<  6));
}

void checkKeys() {
	C0 = ~(LPC_GPIO2->FIOPIN >> 12) & KEY_MASK;
	Cs = ~(LPC_GPIO2->FIOPIN >> 11) & KEY_MASK;
	D0 = ~(LPC_GPIO2->FIOPIN >> 10) & KEY_MASK;
	Ds = ~(LPC_GPIO1->FIOPIN >> 16) & KEY_MASK;
	E0 = ~(LPC_GPIO1->FIOPIN >> 17) & KEY_MASK;
	F0 = ~(LPC_GPIO0->FIOPIN >>  4) & KEY_MASK;
	Fs = ~(LPC_GPIO0->FIOPIN >>  6) & KEY_MASK;
	G0 = ~(LPC_GPIO1->FIOPIN >> 26) & KEY_MASK;
	Gs = ~(LPC_GPIO1->FIOPIN >> 25) & KEY_MASK;
	A0 = ~(LPC_GPIO1->FIOPIN >> 23) & KEY_MASK;
	As = ~(LPC_GPIO1->FIOPIN >> 21) & KEY_MASK;
	B0 = ~(LPC_GPIO1->FIOPIN >> 20) & KEY_MASK;
	C1 = ~(LPC_GPIO1->FIOPIN >> 19) & KEY_MASK;
	
	if (C0) {
		playSound(53);
	}
	else if (Cs) {
		playSound(56);
	}
	else if (D0) {
		playSound(60);
	}
	else if (Ds) {
		playSound(63);
	}
	else if (E0) {
		playSound(66);
	}
	else if (F0) {
		playSound(70);
	}
	else if (Fs) {
		playSound(73);
	}
	else if (G0) {
		playSound(78);
	}
	else if (Gs) {
		playSound(82);
	}
	else if (A0) {
		playSound(87);
	}
	else if (As) {
		playSound(92);
	}
	else if (B0) {
		playSound(98);
	}
	else if (C1) {
		playSound(103);
	}
}

void handleKeyPress() {
	keysPressed |= ((C0 << 12)|(Cs << 11)|(D0 << 10)|(Ds << 9)
	               |(E0 << 8 )|(F0 << 7 )|(Fs << 6 )|(G0 << 5)
	               |(Gs << 4 )|(A0 << 3 )|(As << 2 )|(B0 << 1)
	               |(C1));
}

void selectSongFromKeyPress() {
	
	if (keysPressed != 0) {
		menuRender = 1;
		currentState = PLAY;
	}
	
	if ((keysPressed & 0x1000) == 0x1000) { // C0
		currentSong = ODE_TO_JOY;
	} else if ((keysPressed & 0x400) == 0x400) { // D0
		currentSong = MARY_HAD_A_LITTLE_LAMB;
	} else if ((keysPressed & 0x100) == 0x100) { // E0
		currentSong = IMPERIAL_MARCH;
	} else if ((keysPressed & 0x80) == 0x80) { // F0
		currentSong = JINGLE_BELLS;
	} else if ((keysPressed & 0x20) == 0x20) { // G0
		currentSong = DO_RE_MI;
	} else if ((keysPressed & 0x8) == 0x8) { // A0
		currentSong = HEART_AND_SOUL;
	} else if ((keysPressed & 0x2) == 0x2) { // B0
		currentSong = THE_FINAL_COUNTDOWN;
	}	else if ((keysPressed & 0x1) == 0x1) { // C1
		currentSong = OLD_MCDONALD;
	}	
}
