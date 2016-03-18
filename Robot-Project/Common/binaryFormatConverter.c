#include <xc.h>         // library of functions for this chip 
#include <stdio.h>      // library containing printf() function
#include "binaryFormatConverter.h"      //include prototypes for binary form functions

void printCharAsBinary(unsigned char number)
{

if ( ((number & 0b10000000) >> 7 ) == 1)
   printf("0b1");
else
   printf("0b0");

if ( ((number & 0b01000000) >> 6 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b00100000) >> 5 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b00010000) >> 4 ) == 1)
   printf("1");
else
   printf("0"); 


if ( ((number & 0b00001000) >> 3 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b00000100) >> 2 ) == 1)
   printf("1");
else
   printf("0");

if ( ((number & 0b00000010) >> 1 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b00000001) ) == 1)
   printf("1");
else
   printf("0");

}


void WaitOneSecond(void)
{
int  i = 0;
for(i=0; i<=5; i++) 
   {
    _delay(50000ul);  // 50 000 * 4 / 1 000 000 = 1/5 s 
   }
}

void printIntAsBinary(unsigned int number)
{

if ( ((number & 0b1000000000000000) >> 15 ) == 1)
   printf("0b1");
else
   printf("0b0");

if ( ((number & 0b0100000000000000) >> 14 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b0010000000000000) >> 13 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b0001000000000000) >> 12 ) == 1)
   printf("1");
else
   printf("0"); 


if ( ((number & 0b0000100000000000) >> 11 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b0000010000000000) >> 10 ) == 1)
   printf("1");
else
   printf("0");

if ( ((number & 0b0000001000000000) >> 9 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b0000000100000000) >> 8 ) == 1)
   printf("1");
else
   printf("0");

if ( ((number & 0b0000000010000000) >> 7 ) == 1)
   printf("1");
else
   printf("0");

if ( ((number & 0b0000000001000000) >> 6 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b0000000000100000) >> 5 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b0000000000010000) >> 4 ) == 1)
   printf("1");
else
   printf("0"); 


if ( ((number & 0b0000000000001000) >> 3 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b0000000000000100) >> 2 ) == 1)
   printf("1");
else
   printf("0");

if ( ((number & 0b00000010) >> 1 ) == 1)
   printf("1");
else
   printf("0");


if ( ((number & 0b0000000000000001) ) == 1)
   printf("1");
else
   printf("0");

}