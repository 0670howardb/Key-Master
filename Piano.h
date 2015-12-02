#ifndef _PIANO_H
#define _PIANO_H

#define KEY_MASK 0x1

void Piano_Init(void);
void checkKeys(void);
void handleKeyPress(void);
void selectSongFromKeyPress(void);

extern uint16_t keysPressed;

extern short C0;
extern short Cs;
extern short D0;
extern short Ds;
extern short E0;
extern short F0;
extern short Fs;
extern short G0;
extern short Gs;
extern short A0;
extern short As;
extern short B0;
extern short C1;

#endif
