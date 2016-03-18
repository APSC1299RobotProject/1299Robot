#include "sumovore.h"
#include "motor_control.h"
#include "../Common/TimeDelays.h"

void follow_simple_curves(void);
void spin_left(void);
void turn_left(void);
void straight_fwd(void);
void turn_right(void);
void spin_right(void);

void motor_control(void)
{
    while(1)
    {
        set_motor_speed(left,stop,0);         //set left to fast forward
        set_motor_speed(right,fast,+185);        //set right to fast forward
        WaitOneSecond();        //delay for running speed at fast for 3 seconds
        WaitOneSecond();
        WaitOneSecond();
        set_motor_speed(left,fast,0);
        set_motor_speed(right,rev_fast,0);
        WaitOneSecond();        //delay for running speed at fast for 3 seconds
        WaitOneSecond();
        WaitOneSecond();
        set_motor_speed(left,fast,0);
        set_motor_speed(right,slow,0);
        WaitOneSecond();        //delay for running speed at fast for 3 seconds
        WaitOneSecond();
        WaitOneSecond();
        /*set_motor_speed(left, medium,0);        //set left to fast forward
        set_motor_speed(right, medium,0);      //set right to fast forward
        WaitOneSecond();        //delay for running speed at medium for 3 seconds
        WaitOneSecond();
        WaitOneSecond();
        set_motor_speed(left, slow,0);        //set left to slow forward
        set_motor_speed(right, slow,0);      //set right to slow forward
        WaitOneSecond();        //delay for running speed at slow for 3 seconds
        WaitOneSecond();
        WaitOneSecond();
        set_motor_speed(left,stop,0);        //stop
        set_motor_speed(right,stop, 0);      //stop
        WaitOneSecond();        //stop for 3 seconds
        WaitOneSecond();
        WaitOneSecond();
        set_motor_speed(left, rev_slow,0);        //set left to slow backwards
        set_motor_speed(right, rev_slow,0);      //set right to slow backwards
        WaitOneSecond();        //delay for running speed at slow for 3 seconds
        WaitOneSecond();
        WaitOneSecond();
        set_motor_speed(left, rev_medium,0);        //set left to medium backwards
        set_motor_speed(right, rev_medium,0);      //set right to medium backwards
        WaitOneSecond();        //delay for running speed at medium for 3 seconds
        WaitOneSecond();
        WaitOneSecond();
        set_motor_speed(left, rev_fast,0);        //set left to fast backwards
        set_motor_speed(right, rev_fast,0);      //set right to fast backwards
        WaitOneSecond();        //delay for running speed at fast for 3 seconds
        WaitOneSecond();
        WaitOneSecond();*/      
    }
     // very simple motor control
     switch(SeeLine.B)
     {
        case 0b00100u:
        case 0b00010u:
        case 0b01000u:
        case 0b00001u:
        case 0b10000u:
                       //no breaks all above readings end up here
                       follow_simple_curves();
                       break;
        case 0b00000u:
                        motors_brake_all();
                       break;
        default:       break;
      } 
}

void follow_simple_curves(void)
{
     if ( SeeLine.b.Center ) straight_fwd();
     else if (SeeLine.b.Left) spin_left();
     else if (SeeLine.b.CntLeft) turn_left();
     else if (SeeLine.b.CntRight) turn_right();
    else if (SeeLine.b.Right) spin_right();
}

void spin_left(void)
{
  set_motor_speed(left, rev_fast, 0); 
  set_motor_speed(right, fast, 0); 
}

void turn_left(void)
{
  set_motor_speed(left, stop, 0); 
  set_motor_speed(right, fast, 0); 
}
void straight_fwd(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, fast, 0); 
}
void spin_right(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, rev_fast, 0); 
}
void turn_right(void)
{
  set_motor_speed(left, fast, 0); 
  set_motor_speed(right, stop, 0); 
}
