
/*
 * main.c
 *
 *  Created on: Apr 15, 2023
 *      Author: YOGA 640
 */

/*
  TASK:C code to turn on the LED on Pin A0
       for 1 second and then turn it off.

  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTER_ADDRESS.h"
#include <util/delay.h>
int main (void)
{
    SET_BIT(DDRA , 0);
	while(1)
	{
		SET_BIT(PORTA , 0);
		_delay_ms(500);
		TOGGLE_BIT(PORTA , 0);
		_delay_ms(500);
	}


	return 0;
}

