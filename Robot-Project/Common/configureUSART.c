//****************************************************************************************
//
// configureUSART.c
//
// Configures the PIC18LF4525 serial communication (USART) module for operation
// and set the baud rate (communication speed) in bits per second or bps.
//
// The formula produces the best match to the desired baud rate. However for small values of 
// variable spbrg, the actual baud rate may be more than a few percent off in which case the 
// MCU may not be able to talk to the output device such as the SparkFun LCD or a PC  
//
// The SparkFun LCD on works at the following baudrates, 2400, 4800, 9600, 14400, 19200,
// and 38400 bps. Your PC can communicate at much higher speeds up to 1 000 000 bps
//
// The speed at which you commicate depends on the desired baud rate and the operating frequency 
// of the MCU, FOSC. Not all combinations of baudrate and FOSC will produce values of spbrg
// that give a communication speed within tolerance. Note that this occurs for the LCD at 
// 38400 bps and the MCU at 1 MHz.    
// 
// Dan Piercce & Mike Coombes, 10 May 2011
//
//****************************************************************************************
#include <xc.h>
#include "configureUSART.h"

void configureUSART(unsigned long baudrate, float osc_freq_MHz)
{
  unsigned int spbrg;
	
  TRISCbits.RC6 = 0;     // set TX (RC6) as output 
  TRISCbits.RC7 = 1;     // and RX (RC7) as input

  // For a 16-bit sbprg value with USART_BRIGH_HIGH setting.
  // Formula from datasheet is Baudrate = FOSC/ (4 * (spbrg + 1 ))
  spbrg = (unsigned int)( ((float)osc_freq_MHz * 1.0e6) /(4.0*(float)baudrate) + 0.5 - 1.0); 

 
  OpenUSART( USART_TX_INT_OFF & USART_RX_INT_OFF & USART_ASYNCH_MODE & USART_EIGHT_BIT & 
             USART_CONT_RX & USART_BRGH_HIGH, spbrg );  
  // OpenUSART is part of the C18 usart.h library        
  
  BAUDCONbits.BRG16 = 1;  	// needed so we can use a 16-bit spbrg
							// Note that this is not discussed in the c18 Compiler Libraries guide
  _delay(10000); // small delay to allow communication speed to stabilize
					
}          


// needed for printf() to work wih xc.h 
void putch(char data) {    
     while (!TXIF)        
         continue;    // wait while send buffer is empty
     TXREG = data;    
}   
 