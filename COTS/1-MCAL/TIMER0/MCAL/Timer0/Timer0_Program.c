/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    Timer0        ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/ERROR_STATE.h"
#include "../../LIB/BIT_MATH.h"

#include "../Interrupt.h"

#include "Timer0_Register.h"
#include "Timer0_Interface.h"
#include "Timer0_Config.h"
#include "Timer0_Private.h"


static u32 TIMER0_u32NumOVF = 0;
static u32 TIMER0_u32Preload = 0;

volatile static void (* TIMER0_pfunISRFun)(void*) = NULL;
volatile static void * TIMER0_pvidISRParameter = NULL;

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuInitialize.                                   **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : void.                                                   **/
/** Functionality   : Setting MODE of Operation , Clock Source & OC0 Pin Mode **/
/*******************************************************************************/
/*******************************************************************************/

ES_t  TIMER0_enuInitialize(void)
{
	ES_t   Local_enuErrorState = ES_NOK;

	/*Mode Select*/
#if  MODE_OF_OPERATION == NORMAL_MODE
	//Choose Normal Mode
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);

	//Choose Output Compare Pin Mode
#if  OC0_MODE == DISCONNECT_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == TOGGLE_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == CLEAR_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == SET_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error "OC0 Mode Is Incorrect"
#endif

	Local_enuErrorState = ES_OK;

#elif  MODE_OF_OPERATION == PWM_PHASE_CORRECT_MODE
	//Choose Phase Correct PWM Mode
	SET_BIT(TCCR0 , TCCR0_WGM00);
	CLEAR_BIT(TCCR0 , TCCR0_WGM01);
	//Choose Output Compare Pin Mode
#if  OC0_MODE == DISCONNECT_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == CLEAR_OC0    /*clear oc0 up_counting ,, set oc0 down_counting*/

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);


#elif  OC0_MODE == SET_OC0     /*set oc0 up_counting ,, clear oc0 down_counting*/

	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error "OC0 Mode Is Incorrect"
#endif

	Local_enuErrorState = ES_OK;

#elif  MODE_OF_OPERATION == CTC_MODE
	//Choose CTC Mode
	CLEAR_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	//Choose Output Compare Pin Mode
#if  OC0_MODE == DISCONNECT_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == TOGGLE_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == CLEAR_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == SET_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error "OC0 Mode Is Incorrect"
#endif

	Local_enuErrorState = ES_OK;

#elif  MODE_OF_OPERATION == FAST_PWM_MODE
	//Choose Fast PWM Mode
	SET_BIT(TCCR0 , TCCR0_WGM00);
	SET_BIT(TCCR0 , TCCR0_WGM01);

	//Choose Output Compare Pin Mode
#if  OC0_MODE == DISCONNECT_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	CLEAR_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == CLEAR_OC0

	CLEAR_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#elif  OC0_MODE == SET_OC0

	SET_BIT(TCCR0 , TCCR0_COM00);
	SET_BIT(TCCR0 , TCCR0_COM01);

#else
#error "OC0 Mode Is Incorrect"
#endif

	Local_enuErrorState = ES_OK;

#else
#error "Mode of Operation is Incorrect"

#endif

	/*Clock Select*/
#if  CLOCK_SOURCE == NO_CLOCK_SOURCE

	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == NO_PRESCALER

	SET_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;



#elif  CLOCK_SOURCE == PRESCALER_8

	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == PRESCALER_64

	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	CLEAR_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == PRESCALER_256

	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == PRESCALER_1024

	SET_BIT(TCCR0 , TCCR0_CS00);
	CLEAR_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == EXTERNAL_T0PIN_FALLING_EDGE

	CLEAR_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#elif  CLOCK_SOURCE == EXTERNAL_T0PIN_RISING_EDGE

	SET_BIT(TCCR0 , TCCR0_CS00);
	SET_BIT(TCCR0 , TCCR0_CS01);
	SET_BIT(TCCR0 , TCCR0_CS02);

	Local_enuErrorState = ES_OK;

#else
#error "Clock Source is Incorrect"

#endif


	return  Local_enuErrorState;

}

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuSetPreload.                                   **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : Copy_u8Prescaller.                                      **/
/** Functionality   : Setting TCNT0 Register to Preload Value                 **/
/*******************************************************************************/
/*******************************************************************************/

ES_t  TIMER0_enuSetPreload(u8 Copy_u8Preload)
{
	ES_t   Local_enuErrorState = ES_NOK;

	TCNT0 = Copy_u8Preload;
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}

/*******************************************************************************/
/*******************************************************************************/
/** Function Name   : TIMER0_enuSynchDelay_ms.                                   **/
/** Return Type     : Error_State enum.                                       **/
/** Arguments       : Copy_u8Prescaller.                                      **/
/** Functionality   : Setting TCNT0 Register to Preload Value                 **/
/*******************************************************************************/
/*******************************************************************************/

ES_t  TIMER0_enuSynchDelay_ms(u32 Copy_u32DelayTime)//Polling  End of Jop
{
	ES_t   Local_enuErrorState = ES_NOK;

	CLEAR_BIT(TIMSK , TIMSK_TOIE0);//Close Interrupt

	f32    Local_f32OverFlowTime = (((f32)TIMER_PRESCALER/TIMER_F_CPU)*256) ;//calculate OverFlow Time

	f32 Local_f32NumOVF = Copy_u32DelayTime/Local_f32OverFlowTime;

	if((Local_f32NumOVF - (u32)Local_f32NumOVF) != 0.0)
	{
		u32 Local_u32NumOVF = (u32)Local_f32NumOVF+1;//increment number of overflow with one to reach nearest integer number

		Local_f32NumOVF = Local_f32NumOVF - (u32)Local_f32NumOVF;//calculate fraction in number of overflow
		u8 Local_u8Preload = 256*(1-Local_f32NumOVF);//calculate preload

		TCNT0 = Local_u8Preload;//**************
		while(Local_u32NumOVF > 0)
		{
			while(GET_BIT(TIFR , TIFR_TOV0) == 0);//wait on flag
			SET_BIT(TIFR , TIFR_TOV0);//clearing flag by writing logical one
			Local_u32NumOVF--;
		}
	}
	else
	{
		u32 Local_u32NumOVF = (u32)Local_f32NumOVF;
		while(Local_u32NumOVF > 0)
		{
			while(GET_BIT(TIFR , TIFR_TOV0) == 0);//wait on flag
			SET_BIT(TIFR , TIFR_TOV0);//clearing flag by writing logical one
			Local_u32NumOVF--;
		}

	}

	Local_enuErrorState = ES_OK;
	return  Local_enuErrorState;
}





ES_t  TIMER0_enuASynchDelay_ms(u32 Copy_u32DelayTime ,volatile void(*Copy_pfunAppFun)(void*) , void* Copy_pvidAppParameter)//Interrupt ISR
{
	ES_t   Local_enuErrorState = ES_NOK;

	f32    Local_f32OverFlowTime = (((f32)TIMER_PRESCALER/TIMER_F_CPU)*256) ;//calculate OverFlow Time

	f32 Local_f32NumOVF = Copy_u32DelayTime/Local_f32OverFlowTime;

	if((Local_f32NumOVF - (u32)Local_f32NumOVF) != 0.0)
	{
		u32 Local_u32NumOVF = (u32)Local_f32NumOVF+1;//increment number of overflow with one to reach nearest integer number
		Local_f32NumOVF = Local_f32NumOVF - (u32)Local_f32NumOVF;//calculate fraction in number of overflow
		u8 Local_u8Preload = 256*(1-Local_f32NumOVF);//calculate preload

		TIMER0_u32NumOVF = Local_u32NumOVF;
		TIMER0_u32Preload = Local_u8Preload;
		TCNT0 = TIMER0_u32Preload;
	}
	else
	{
		TIMER0_u32NumOVF = (u32)Local_f32NumOVF;
	}
	Local_enuErrorState = ES_OK;

	if(Copy_pfunAppFun != NULL)
	{
		TIMER0_pfunISRFun = Copy_pfunAppFun;
		TIMER0_pvidISRParameter = Copy_pvidAppParameter;
		SET_BIT(TIMSK , TIMSK_TOIE0);//Overflow interrupt enable

		TCNT0 = TIMER0_u32Preload;//initialize TCNT0 With Preload Value

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return  Local_enuErrorState;

}

ISR(VECT_TIMER0_OVF)
{

	if(TIMER0_pfunISRFun != NULL)
	{
		static u32 Local_u32Counter = 0;
		Local_u32Counter++;
		if(Local_u32Counter == TIMER0_u32NumOVF)
		{
			TCNT0 = TIMER0_u32Preload;
			TIMER0_pfunISRFun(TIMER0_pvidISRParameter);
			Local_u32Counter = 0;
		}
	}
}
