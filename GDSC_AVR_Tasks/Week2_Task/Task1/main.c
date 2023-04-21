/*
 * main.c
 *
 *  Created on: Apr 21, 2023
 *      Author: YOGA 640
 */
/*
 C code to control a led using a push button.
 Requirements:
•The Led 1 & 2 is connected to pin 0 & 1 in PORTA.
• The switch 1 , 2 , 3 is connected to pin 0 & 1 & 2 in PORTB.
• If switch 1 is pressed just turn on the first led1 only
• If switch 2 is pressed just turn on led2 only
• If switch 3 is pressed turn on the 2 leds .
• In case no switches are pressed both leds are off.
  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTER_ADDRESS.h"

int main(void)
{
   //Active Pull Up Resistor in Port B
   DDRB = 0;
   PORTB = 255;
   //set pin 0 , 1 in port A as Output
   DDRA = 0x03;
   PORTA = 0;
   while(1)
   {
	   u8 button1 , button2 , button3;
	   button1 = GET_BIT(PINB , 0); //pin 0
	   button2 = GET_BIT(PINB , 1); //pin 1
	   button3 = GET_BIT(PINB , 2); //pin 2
	   if(button1 == 0)
	   {
		   SET_BIT(PORTA , 0);
		   CLEAR_BIT(PORTA , 1);
	   }
	   else if(button2 == 0)
	   {
		   SET_BIT(PORTA , 1);
		   CLEAR_BIT(PORTA , 0);
	   }
	   else if(button3 == 0)
	   {
		   SET_BIT(PORTA , 0);
		   SET_BIT(PORTA , 1);
	   }
	   else
		   PORTA = 0;
     }

    return 0;
}

