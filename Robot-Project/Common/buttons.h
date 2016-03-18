// monitor a digital input pin PORTXbits.RXn for changes

// returns 0 if no edge has happened
// returns 1 at a rising edge
// returns 2 at a falling edge
//
// could modify for just rising or just falling edges
//
#include <xc.h>

unsigned char monitor_switch1_for_edges(unsigned char digitalinputpin);
unsigned char monitor_switch2_for_edges(unsigned char digitalinputpin);