//****************************************************************************************
//
// configureUSART.h
//
// Function to configure the PIC18LF2620 serial communication (USART) module for operation
// and set the baud rate (communication speed). The SparkFun LCD has 5 different 
// operating rates 2400, 4800, 9600 (default), 19200, and 38400. You can operate your 
// MCU at different frequencies. osc_freq_MHz can be 32, 16, 8, 4, 2, and 1, .5, .25, .125
//
// Note 38400 bps is not available at 1 MHz!!!
//
// You can communicate with your PC at much greater speeds up to 1 000 000 bps
//
// Dan Peirce and Mike Coombes, May 2011
//
//****************************************************************************************
void configureUSART(unsigned long baudrate, float osc_freq_MHz);

// needed for printf() to work wih xc.h 
void putch(char data);

