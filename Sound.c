
// cristinel.ababei 
// examples of creating sounds;
// 1-- just a beep, boring one
// 2-- another beep, cooler
// 3-- a sine wave

#include "LPC17xx.H" 

#define DAC_BIAS (0x1<<16)
#define DATA_LENGTH	0x400

uint16_t GusSinTable[45] = 
{
  410, 467, 523, 576, 627, 673, 714, 749, 778,
  799, 813, 819, 817, 807, 789, 764, 732, 694, 
  650, 602, 550, 495, 438, 381, 324, 270, 217,
  169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
  20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};


void DACInit( void )
{
  LPC_PINCON->PINSEL1 = 0x00200000;  // set P0.26 to DAC output;  
  LPC_DAC->DACCNTVAL = 0x00FF;
  LPC_DAC->DACCTRL = (0x1<<1)|(0x1<<2);
  return;
}

void playSound(uint16_t audio[]) {
	int i = 0;
	for (i = 0; i < 45; i++) {  
		LPC_DAC->DACR = (GusSinTable[i] << 6);
	}
}
