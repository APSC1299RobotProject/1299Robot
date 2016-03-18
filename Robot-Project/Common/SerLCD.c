#include "SerLCD.h"
#include <xc.h>
#include <stdio.h>
#include "configureUSART.h"

void LCD_ClearDisplay()
{
        printf("%c%c",0xFE,0x01);    //    clear display
}

void underlineON()
{
    printf("%c%c", 0xFE, 254+14);         //Underline is on you can use a decimal with it
}

void firstLine()
{
    printf("%c%c", 0xFE, 128+0+0);
}

void SecondLine()
{
    printf("%c%c", 0xFE, 128+64);
}

void SecondLineThirdSpot()
{
    printf("%c%c",0xFE,128+64+2);               //128 pick a position, +64 is skip line and +2 is skip 2 places
}

void TopLineEighthPosition()
{
    printf("%c%c", 0xFE, 128+7);                //128 is pick position +7 is skip 7 places
}
