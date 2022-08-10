/* keypad.h file
 * author: ahmed rezk, 	github: https://github.com/ahmedrezkgabr
 *						Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *						mail: ahmedrezkofficial@gmail.com
 */

#ifndef KEYPAD__H_
#define KEYPAD__H_

#include "../../MCAL/GPIO/gpio.h"


/*define the size of the kpd*/
#define COLUMN_SIZE 4
#define ROW_SIZE    4

/*macro to not pressed state*/
#define NOT_PRESSED 101


/*define the keys*/
#define KPD_ARR		    {						\
							{'7','8','9','/'},	\
							{'4','5','6','*'},	\
							{'1','2','3','-'},	\
							{'C','0','=','+'}	\
						}						\

/*define the kpd port*/
#define KPD_PORT     PORT_C


/*define which pin is row and wich is column*/

/* The columns pins : OUT */
#define KPD_COLUMN0_PIN    PIN_0
#define KPD_COLUMN1_PIN    PIN_1
#define KPD_COLUMN2_PIN    PIN_2
#define KPD_COLUMN3_PIN    PIN_3

/* The rows pins : IN */
#define KPD_ROW0_PIN       PIN_4
#define KPD_ROW1_PIN       PIN_5
#define KPD_ROW2_PIN       PIN_6
#define KPD_ROW3_PIN       PIN_7


/* this function is to initialize the keypad device
 * takes void
 * returns void
 */
void KEYPAD_init(void);

/* this function is to get the pressed key from the keys of the keypad
 * takes void
 * returns uint8_t indicates the element in the KPD_ARR (NOT_PRESSED, KPD_ARR[][])
 */
uint8_t KEYPAD_getPressedKey(void);

#endif /*KEYPAD__H_*/