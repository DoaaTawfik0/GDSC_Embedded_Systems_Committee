/*****************************************************/
/*****************************************************/
/**************   Author: Doaa Tawfik  ***************/
/**************   Layer: MCAL          ***************/
/**************   SWC: Port            ***************/
/**************   Version: 1.00        ***************/
/*****************************************************/
/*****************************************************/
#ifndef PORT_CONFIG_H_
#define PORT_CONFIG_H_

/*Zero for Input  >>  One for Output*/


/*Directions for PortA Pins:
 *   First four Pins Represent Input Pins
 *   last four Pins Represent OUTPUT For Data Pins in CLCD
 */
#define PORTA_PIN0_DIR        0
#define PORTA_PIN1_DIR        0
#define PORTA_PIN2_DIR        0
#define PORTA_PIN3_DIR        0
#define PORTA_PIN4_DIR        1
#define PORTA_PIN5_DIR        1
#define PORTA_PIN6_DIR        1
#define PORTA_PIN7_DIR        1

/*Directions for PortB Pins:
 *   First three Pins Represent OUTPUT Pins for Control Pins in CLCD
 *   last five Pins Represent INPUT Pins
 */
#define PORTB_PIN0_DIR        1
#define PORTB_PIN1_DIR        1
#define PORTB_PIN2_DIR        1
#define PORTB_PIN3_DIR        0
#define PORTB_PIN4_DIR        0
#define PORTB_PIN5_DIR        0
#define PORTB_PIN6_DIR        0
#define PORTB_PIN7_DIR        0

/*Directions for PortC Pins:
 *   First Four Pins Represent INPUT Pins for KeyBad Rows Pins
 *   last Four Pins Represent OUTPUT Pins for KeyBad Coulmns Pins
 */
#define PORTC_PIN0_DIR        0
#define PORTC_PIN1_DIR        0
#define PORTC_PIN2_DIR        0
#define PORTC_PIN3_DIR        0
#define PORTC_PIN4_DIR        1
#define PORTC_PIN5_DIR        1
#define PORTC_PIN6_DIR        1
#define PORTC_PIN7_DIR        1

//Directions for PortD Pins
#define PORTD_PIN0_DIR        0
#define PORTD_PIN1_DIR        0
#define PORTD_PIN2_DIR        0
#define PORTD_PIN3_DIR        0
#define PORTD_PIN4_DIR        0
#define PORTD_PIN5_DIR        0
#define PORTD_PIN6_DIR        0
#define PORTD_PIN7_DIR        0


/*
 * Setting Pins Initial Values
 * 0 for Floating if Input  , LOW if Output
 * 1 for PULL_UP if Input   , HIGH if Output
 */


/*
 *  Initial Values for Eight Pins in PortA Equal Zero
 */
#define PORTA_PIN0_INITIAL_VALUE       0
#define PORTA_PIN1_INITIAL_VALUE       0
#define PORTA_PIN2_INITIAL_VALUE       0
#define PORTA_PIN3_INITIAL_VALUE       0
#define PORTA_PIN4_INITIAL_VALUE       0
#define PORTA_PIN5_INITIAL_VALUE       0
#define PORTA_PIN6_INITIAL_VALUE       0
#define PORTA_PIN7_INITIAL_VALUE       0

/*
 *  Initial Values for Eight Pins in PortB Equal Zero
 */
#define PORTB_PIN0_INITIAL_VALUE       0
#define PORTB_PIN1_INITIAL_VALUE       0
#define PORTB_PIN2_INITIAL_VALUE       0
#define PORTB_PIN3_INITIAL_VALUE       0
#define PORTB_PIN4_INITIAL_VALUE       0
#define PORTB_PIN5_INITIAL_VALUE       0
#define PORTB_PIN6_INITIAL_VALUE       0
#define PORTB_PIN7_INITIAL_VALUE       0

/*
 * Initial Values for Eight Pins in PortC Equal One
 */
#define PORTC_PIN0_INITIAL_VALUE       1
#define PORTC_PIN1_INITIAL_VALUE       1
#define PORTC_PIN2_INITIAL_VALUE       1
#define PORTC_PIN3_INITIAL_VALUE       1
#define PORTC_PIN4_INITIAL_VALUE       1
#define PORTC_PIN5_INITIAL_VALUE       1
#define PORTC_PIN6_INITIAL_VALUE       1
#define PORTC_PIN7_INITIAL_VALUE       1

/*
 *  Initial Values for Eight Pins in PortD Equal Zero
 */
#define PORTD_PIN0_INITIAL_VALUE       0
#define PORTD_PIN1_INITIAL_VALUE       0
#define PORTD_PIN2_INITIAL_VALUE       0
#define PORTD_PIN3_INITIAL_VALUE       0
#define PORTD_PIN4_INITIAL_VALUE       0
#define PORTD_PIN5_INITIAL_VALUE       0
#define PORTD_PIN6_INITIAL_VALUE       0
#define PORTD_PIN7_INITIAL_VALUE       0




#endif
