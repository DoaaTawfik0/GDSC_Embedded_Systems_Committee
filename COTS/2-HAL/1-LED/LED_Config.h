/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik   ***************/
/**************   Layer:  HAL           ***************/
/**************   SWC:    LED           ***************/
/**************   Version:1.00          ***************/
/*****************************************************/
/*****************************************************/
#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

#define LED_NUM 3

typedef struct
{
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8ConnType;
	u8 LED_u8InitState;

}LED_t;



#endif
