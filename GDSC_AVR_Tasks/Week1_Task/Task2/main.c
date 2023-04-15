
/*
 * main.c
 *
 *  Created on: Apr 15, 2023
 *      Author: YOGA 640
 */

/*
  TASK:C Code that apply Some LED animations
       ( Snake effect)

  */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REGISTER_ADDRESS.h"
#include <util/delay.h>
int main (void)
{
    SET_BIT(DDRA , 0);
    SET_BIT(DDRA , 1);
    SET_BIT(DDRA , 2);
    SET_BIT(DDRA , 3);
    SET_BIT(DDRA , 4);
    SET_BIT(DDRA , 5);
	while(1)
	{
		//Setting bits from 0 to 5
		SET_BIT(PORTA , 0);
		_delay_ms(100);
		SET_BIT(PORTA , 1);
		_delay_ms(100);
		SET_BIT(PORTA , 2);
		_delay_ms(100);
		SET_BIT(PORTA , 3);
		_delay_ms(100);
		SET_BIT(PORTA , 4);
		_delay_ms(100);
		SET_BIT(PORTA , 5);
		_delay_ms(100);
		//Clearing bits from 0 to 5
		CLEAR_BIT(PORTA , 0);
		_delay_ms(100);
		CLEAR_BIT(PORTA , 1);
		_delay_ms(100);
		CLEAR_BIT(PORTA , 2);
		_delay_ms(100);
		CLEAR_BIT(PORTA , 3);
		_delay_ms(100);
		CLEAR_BIT(PORTA , 4);
		_delay_ms(100);
		CLEAR_BIT(PORTA , 5);
		_delay_ms(100);
	}


	return 0;
}

