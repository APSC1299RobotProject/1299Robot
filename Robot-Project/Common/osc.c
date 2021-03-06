#include <xc.h>
#include "osc.h"

//***********************************************************************************
//
//                          set_osc_32MHz()
//
//    sets the oscillator frequency to 32 MHz
//
//    Note TOSC = 1/(32 MHz) = 0.03125 mus and TCY = 4*TOSC = 0.125 mus
//
//***********************************************************************************


void set_osc_32MHz(void)
{
  int i;
 
  OSCCONbits.IRCF2 = 1;     // Set the OSCILLATOR Control Register to 8 MHz
  OSCCONbits.IRCF1 = 1;      
  OSCCONbits.IRCF0 = 1;     

  OSCTUNEbits.PLLEN = 1;    // Turbo! Currently disabled
                            // set to 1 at 4 MHz and 8 MHz to get 16 and 32 MHz 
                            
 
  for(i=0;i<500;i++);       // delay to allow clock PLL to lock (stabilize)
   
}

void set_osc_16MHz(void)
{
    int i;
    
    OSCCONbits.IRCF2 = 1;           //set oscillation to 4 MHz
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 0;
    OSCTUNEbits.PLLEN = 1;          //boost oscillation by 4 to 16MHz
    
    for(i = 0; i < 500; i++);       //delay for PLLEN to take effect
    
}

void set_osc_8MHz(void)
{
    OSCCONbits.IRCF2 = 1;           //set oscillation to 4 MHz
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 1;
}


void set_osc_4MHz(void)
{
    OSCCONbits.IRCF2 = 1;           //set oscillation to 4 MHz
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 0;
}


void set_osc_2MHz(void)
{
    OSCCONbits.IRCF2 = 1;           //set oscillation to 4 MHz
    OSCCONbits.IRCF1 = 0;
    OSCCONbits.IRCF0 = 1;
}

void set_osc_1MHz(void)
{
    OSCCONbits.IRCF2 = 1;
    OSCCONbits.IRCF1 = 0;
    OSCCONbits.IRCF0 = 0;
}