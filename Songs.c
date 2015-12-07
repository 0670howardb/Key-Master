/* Brandon Howard
	 Final Project - Key Master!
	 Embedded Systems
	 Songs.c
*/

#include <lpc17xx.h>
#include "Piano.h"
#include "Game.h"
#include "Songs.h"

int odeToJoyLength = 40;
int maryHadALittleLambLength = 40;
int imperialMarchLength = 56;
int jingleBellsLength = 73;
int doReMiLength = 144;
int heartAndSoulLength = 64;
int theFinalCountdownLength = 40;
int oldMcDonaldLength = 72;

uint16_t odeToJoy[40] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x100, 
	                       0x80, 0x20, 0x20, 0x80, 0x100, 0x400, 0x1000, 0x1000, 0x400, 0x100, 
	                       0x100, 0x400, 0x400, 0x0, 0x100, 0x100, 0x80, 0x20, 0x20, 0x80, 
                         0x100, 0x400, 0x1000, 0x1000, 0x400, 0x100, 0x400, 0x1000, 0x1000, 0x0};

uint16_t maryHadALittleLamb[40] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x400, 0x1000,
                                    0x400, 0x100, 0x100, 0x100, 0x0, 0x400, 
                                    0x400, 0x400, 0x0, 0x100, 0x20, 0x20, 
                                    0x0, 0x100, 0x400, 0x1000, 0x400, 0x100, 
                                    0x100, 0x100, 0x100, 0x400, 0x400, 0x100, 
                                    0x400, 0x1000, 0x0, 0x0, 0x0};
																		
uint16_t imperialMarch[56] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x0, 0x0, 0x100, 
	                            0x0, 0x0, 0x100, 0x0, 0x0,0x1000, 0x0, 0x20, 0x100, 0x0, 0x0, 0x1000, 
	                            0x0, 0x20, 0x100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0, 0x2, 0x0, 
	                            0x0, 0x2, 0x0, 0x0, 0x1, 0x0, 0x20, 0x200, 0x0, 0x0, 0x1000, 0x0, 0x20, 
                              0x100, 0x0, 0x0, 0x0, 0x0, 0x0};

																		
uint16_t jingleBells[73] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	                          0x100, 0x100, 0x100, 0x0, 0x100, 0x100, 0x100, 0x0,
	                          0x100, 0x20, 0x1000, 0x400, 0x100, 0x0, 0x0, 0x0,
	                          0x80, 0x80, 0x80, 0x80, 0x80, 0x100, 0x100, 0x100, 
	                          0x100, 0x400, 0x400, 0x100, 0x400, 0x0, 0x20, 0x0,
	                          0x100, 0x100, 0x100, 0x0, 0x100, 0x100, 0x100, 0x0,
	                          0x100, 0x20, 0x1000, 0x400, 0x100, 0x0, 0x0, 0x0,
	                          0x80, 0x80, 0x80, 0x80, 0x80, 0x100, 0x100, 0x100,
	                          0x20, 0x20, 0x8, 0x2, 0x1, 0x0, 0x1000, 0x0, 0x0};
																		
uint16_t doReMi[144] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	                     0x1000, 0x0, 0x0, 0x400, 0x100, 0x0, 0x0, 0x1000, 
	                     0x100, 0x0, 0x1000, 0x0, 0x100, 0x0, 0x0, 0x0, 
                       0x400, 0x0, 0x0, 0x100, 0x80, 0x80, 0x100, 0x400,
                       0x80, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                       0x100, 0x0, 0x0, 0x80, 0x20, 0x0, 0x0, 0x100,
                       0x20, 0x0, 0x100, 0x0, 0x20, 0x0, 0x0, 0x0,
                       0x80, 0x0, 0x0, 0x20, 0x8, 0x8, 0x20, 0x80, 
                       0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
                       0x20, 0x0, 0x0, 0x1000, 0x400, 0x100, 0x80, 0x20,
	                     0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
	                     0x8, 0x0, 0x0, 0x400, 0x100, 0x40, 0x20, 0x8,
	                     0x2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	                     0x2, 0x0, 0x0, 0x100, 0x80, 0x20, 0x08, 0x2,
	                     0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x4,
	                     0x8, 0x0, 0x80, 0x0, 0x2, 0x0, 0x20, 0x0,
	                     0x1, 0x0, 0x20, 0x0, 0x100, 0x0, 0x400, 0x0, 0x1000,
	                     0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};
																		
uint16_t heartAndSoul[64] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	                           0x200, 0x0, 0x200, 0x0, 0x200, 0x0, 0x0, 0x0,
	                           0x0, 0x200, 0x400, 0x1000, 0x400, 0x200, 0x80, 0x0,
	                           0x20, 0x0, 0x20, 0x0, 0x20, 0x0, 0x0, 0x0, 
	                           0x0, 0x20, 0x80, 0x200, 0x80, 0x20, 0x10, 0x0, 
	                           0x4, 0x0, 0x0, 0x0, 0x200, 0x0, 0x0, 0x0,
	                           0x0, 0x1, 0x4, 0x8, 0x20, 0x80, 0x200, 0x400, 0x200, 
                             0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};	
	                           
																		
uint16_t theFinalCountdown[40] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x400, 0x1000,
                                    0x400, 0x100, 0x100, 0x100, 0x0, 0x400, 
                                    0x400, 0x400, 0x0, 0x100, 0x20, 0x20, 
                                    0x0, 0x100, 0x400, 0x1000, 0x400, 0x100, 
                                    0x100, 0x100, 0x100, 0x400, 0x400, 0x100, 
                                    0x400, 0x1000, 0x0, 0x0, 0x0};
																		
uint16_t oldMcDonald[72] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 
	                          0x80, 0x80, 0x80, 0x1000, 0x400, 0x400, 0x1000, 0x0,
	                          0x8, 0x8, 0x20, 0x20, 0x80, 0x0, 0x0, 0x1000,
	                          0x80, 0x80, 0x80, 0x1000, 0x400, 0x400, 0x1000, 0x0,
                            0x8, 0x8, 0x20, 0x20, 0x80, 0x0, 0x0, 0x1000,
	                          0x8, 0x8, 0x8, 0x0, 0x8, 0x8, 0x8, 0x0, 
	                          0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 
	                          0x8, 0x8, 0x8, 0x1000, 0x400, 0x400, 0x1000, 0x0,
            	              0x8, 0x8, 0x20, 0x20, 0x80, 0x0, 0x0, 0x0};
