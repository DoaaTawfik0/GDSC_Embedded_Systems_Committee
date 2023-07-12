/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer:  App          ***************/
/**************   SWC:    ......       ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/

#include "STD_TYPES.h"

#include "util/delay.h"

#include "DIO_Interface.h"

#include "CLCD_Interface.h"

#include "KeyPad_Interface.h"

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : App_enuGetOperand.                                    **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_Pu32Operand.                                     **/
/** Functionality   : Getting Operand from user                             **/
/*****************************************************************************/
/*****************************************************************************/

ES_t App_enuGetOperand(u32* Copy_Pu32Operand)
{
	ES_t Local_enuErrorState = ES_NOK;

	u32 Local_u32Operand = 0;
	if(Copy_Pu32Operand != NULL)
	{
		do
		{
			Local_u32Operand = KeyPad_u8PressedKey();
		}while(Local_u32Operand == 0xff);
		if((Local_u32Operand == 42) || (Local_u32Operand == 43) || (Local_u32Operand == 45) || (Local_u32Operand == 47))
		{
			CLCD_enuSendCommand(0x01);
			CLCD_enuSendString("Enter valid Operand from 0 to 9");
			Local_enuErrorState = ES_OUT_OF_RANGE;
			_delay_ms(100);
			return Local_enuErrorState;
		}
		else
		{
			CLCD_enuWriteNumber(Local_u32Operand);
		}

		*Copy_Pu32Operand = Local_u32Operand;

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}


/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : App_enuGetOperator.                                   **/
/** Return Type     : Error_State.                                          **/
/** Arguments       : Copy_Pu32Operator.                                    **/
/** Functionality   : Getting Operator from user                            **/
/*****************************************************************************/
/*****************************************************************************/

ES_t App_enuGetOperator(u32* Copy_Pu32Operator)
{
	ES_t Local_enuErrorState = ES_NOK;

	u32 Local_u32Operand = 0;
	if(Copy_Pu32Operator != NULL)
	{
		do
		{
			Local_u32Operand = KeyPad_u8PressedKey();
		}while(Local_u32Operand == 0xff);
		if((Local_u32Operand == 42) || (Local_u32Operand == 43) || (Local_u32Operand == 45) || (Local_u32Operand == 47))
		{
			CLCD_enuSendData(Local_u32Operand);

		}
		else
		{
			CLCD_enuSendString("Enter valid Operator *,/,+,-");
			Local_enuErrorState = ES_OUT_OF_RANGE;
			_delay_ms(100);
			return Local_enuErrorState;
		}

		*Copy_Pu32Operator = Local_u32Operand;

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;

}

