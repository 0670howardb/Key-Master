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
int doReMiLength = 40;
int takeOnMeLength = 40;
int theFinalCountdownLength = 40;
int oldMcDonaldLength = 40;

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
																		
uint16_t doReMi[40] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x400, 0x1000,
                                    0x400, 0x100, 0x100, 0x100, 0x0, 0x400, 
                                    0x400, 0x400, 0x0, 0x100, 0x20, 0x20, 
                                    0x0, 0x100, 0x400, 0x1000, 0x400, 0x100, 
                                    0x100, 0x100, 0x100, 0x400, 0x400, 0x100, 
                                    0x400, 0x1000, 0x0, 0x0, 0x0};
																		
uint16_t takeOnMe[40] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x400, 0x1000,
                                    0x400, 0x100, 0x100, 0x100, 0x0, 0x400, 
                                    0x400, 0x400, 0x0, 0x100, 0x20, 0x20, 
                                    0x0, 0x100, 0x400, 0x1000, 0x400, 0x100, 
                                    0x100, 0x100, 0x100, 0x400, 0x400, 0x100, 
                                    0x400, 0x1000, 0x0, 0x0, 0x0};
																		
uint16_t theFinalCountdown[40] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x400, 0x1000,
                                    0x400, 0x100, 0x100, 0x100, 0x0, 0x400, 
                                    0x400, 0x400, 0x0, 0x100, 0x20, 0x20, 
                                    0x0, 0x100, 0x400, 0x1000, 0x400, 0x100, 
                                    0x100, 0x100, 0x100, 0x400, 0x400, 0x100, 
                                    0x400, 0x1000, 0x0, 0x0, 0x0};
																		
uint16_t oldMcDonald[40] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x100, 0x400, 0x1000,
                                    0x400, 0x100, 0x100, 0x100, 0x0, 0x400, 
                                    0x400, 0x400, 0x0, 0x100, 0x20, 0x20, 
                                    0x0, 0x100, 0x400, 0x1000, 0x400, 0x100, 
                                    0x100, 0x100, 0x100, 0x400, 0x400, 0x100, 
                                    0x400, 0x1000, 0x0, 0x0, 0x0};

