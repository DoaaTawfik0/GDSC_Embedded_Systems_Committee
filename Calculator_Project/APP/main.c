
#include "STD_TYPES.h"

#include "util/delay.h"

#include "Port_Interface.h"

#include "DIO_Interface.h"

#include "CLCD_Interface.h"

#include "App_Interface.h"


int main()
{
	PORT_voidInit();

	CLCD_enuInit();

	u32 Copy_u32FunctionState = 0 , Copy_u32Arr[ARR_SIZE];
	u32	 Copy_u32Iterator = 0 , Copy_u32Result = 0;
	while(1)
	{
		CLCD_enuSendString("   Calculator   ");
		_delay_ms(200);
		CLCD_enuSendCommand(0x01);
		for(Copy_u32Iterator = 0 ; Copy_u32Iterator < ARR_SIZE ; Copy_u32Iterator++)
		{
			if(Copy_u32Iterator == ARR_SIZE-1)
			{
				CLCD_enuSendString("Enter Operator: ");
				CLCD_enuGoToXY(1,0);
				Copy_u32FunctionState = App_enuGetOperator(Copy_u32Arr+Copy_u32Iterator);
				if(Copy_u32FunctionState == ES_OUT_OF_RANGE)
				{
					CLCD_enuSendCommand(0x01);
					CLCD_enuSendString("Enter Operator: ");
					CLCD_enuGoToXY(1,0);
					App_enuGetOperand(Copy_u32Arr+Copy_u32Iterator);
				}
				_delay_ms(200);
				CLCD_enuSendCommand(0x01);
			}
			else
			{
				CLCD_enuSendString("Enter Operand: ");
				CLCD_enuGoToXY(1,0);
				Copy_u32FunctionState = App_enuGetOperand(Copy_u32Arr+Copy_u32Iterator);
				if(Copy_u32FunctionState == ES_OUT_OF_RANGE)
				{
					CLCD_enuSendCommand(0x01);
					CLCD_enuSendString("Enter Operand: ");
					CLCD_enuGoToXY(1,0);
					App_enuGetOperand(Copy_u32Arr+Copy_u32Iterator);
				}
				_delay_ms(200);
				CLCD_enuSendCommand(0x01);
			}

		}
		switch(Copy_u32Arr[ARR_SIZE-1])
		{
		case '+':
			Copy_u32Result = Copy_u32Arr[0]+Copy_u32Arr[1];
			break;
		case '-':
			Copy_u32Result = Copy_u32Arr[0]-Copy_u32Arr[1];
			break;
		case '*':
			Copy_u32Result = Copy_u32Arr[0]*Copy_u32Arr[1];
			break;
		case '/':
			Copy_u32Result = Copy_u32Arr[0]/Copy_u32Arr[1];
			break;
		}
		CLCD_enuWriteNumber(Copy_u32Arr[0]);
		CLCD_enuSendData(Copy_u32Arr[ARR_SIZE-1]);
		CLCD_enuWriteNumber(Copy_u32Arr[1]);
		CLCD_enuSendData('=');
		CLCD_enuWriteNumber(Copy_u32Result);

		_delay_ms(300);
		CLCD_enuGoToXY(0 , 0);

	}

	return 0;
}


