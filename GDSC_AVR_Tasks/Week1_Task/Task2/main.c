
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
	u8 i;

    //Setting bits from 0 to 5 direction as OUTPUT
    for(i = 0 ; i < 6 ; i++)
    {
    	SET_BIT(DDRA , i);
    }
	while(1)
	{
		//Setting bits from 0 to 5
		for(i = 0 ; i < 6 ; i++)
		{
			SET_BIT(PORTA , i);
			_delay_ms(100);

		}
		//Clearing bits from 0 to 5
		for(i = 0 ; i < 6 ; i++)
		{
			CLEAR_BIT(PORTA , i);
			_delay_ms(100);

		}

	}


	return 0;
}

