/******************************************************/
/******************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  MCAL          ***************/
/**************   SWC:    Timer0        ***************/
/**************   Version: 1.00         ***************/
/******************************************************/
/******************************************************/

#ifndef   TIMER0_CONFIG_H_
#define   TIMER0_CONFIG_H_

#include "Timer0_Private.h"

#define   MODE_OF_OPERATION       NORMAL_MODE

#define   CLOCK_SOURCE            PRESCALER_8

#define   TIMER_PRESCALER         PRESCALER_8



/*
 ****For Normal/CTC(Non_PWM)  Mode
 *   ->DISCONNECT_OC0
 *   ->Toggle_OC0
 *   ->Clear_OC0
 *   ->Set_OC0
 *
 ****For Phase Correct PWM  Mode
 *   ->DISCONNECT_OC0
 *   ->Clear_OC0  ...this will clear OC0 on compare match , set OC0 at TOP
 *   ->Set_OC0    ...this will set OC0 on compare match , clear OC0 at TOP
 *
 ****For Fast PWM  Mode
 *   ->DISCONNECT_OC0
 *   ->Clear_OC0  ...this will clear OC0 on compare match when up_counting , set OC0 on compare match when down_counting
 *   ->Set_OC0    ...this will set OC0 on compare match when up_counting , clear OC0 on compare match when down_counting
 *
 */
#define   OC0_MODE                DISCONNECT_OC0

//Freq in KHZ
#define   TIMER_F_CPU             (1000UL)  //1 Mega HZ




#endif
