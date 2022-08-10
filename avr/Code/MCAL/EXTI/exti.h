/* exti.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */

#ifndef EXTI__H_
#define EXTI__H_

#include "../../UTALITIES/types.h"

/*bits defination*/
#define ISC00 0 /*Interrupt Sense Control 0 bit 0*/
#define ISC01 1 /*Interrupt Sense Control 0 bit 1*/
#define ISC10 2 /*Interrupt Sense Control 1 bit 0*/
#define ISC11 3 /*Interrupt Sense Control 1 bit 1*/
#define ISC2 6  /*Interrupt Sense Control 2*/
#define INT0 6  /*External Interrupt Request 0 Enable*/
#define INT1 7  /*External Interrupt Request 1 Enable*/
#define INT2 5  /*External Interrupt Request 2 Enable*/
#define INTF0 6 /*External Interrupt Flag 0*/
#define INTF1 7 /*External Interrupt Flag 1*/
#define INTF2 5 /*External Interrupt Flag 2*/

typedef enum
{
    EXTI_LOW_LEVEL,    /*interrupt fired if the logic is 0*/
    EXTI_FALLING_EDGE, /*interrupt fired if the logic is 1 and become 0*/
    EXTI_RISING_EDGE,  /*interrupt fired if the logic is 0 and become 1*/
    EXTI_CHANGING      /*interrupt fired if the logic is changed*/
} EN_senseControl_t;

typedef enum
{
    EXTI_OK,
    EXTI_WRONG_SENSE_CTRL
} EN_extiError_t;

/* this function is to initialize the external interrupt 0
 * takes EN_senseControl_t as sensControl
 * returns EN_extiError_t (EXTI_OK, EXTI_WRONG_SENSE_CTRL)
 */
EN_extiError_t EXTI0_init(EN_senseControl_t);

/* this function is to initialize the external interrupt 1
 * takes EN_senseControl_t as sensControl
 * returns EN_extiError_t (EXTI_OK, EXTI_WRONG_SENSE_CTRL)
 */
EN_extiError_t EXTI1_init(EN_senseControl_t);

/* this function is to initialize the external interrupt 2
 * takes EN_senseControl_t as sensControl this interrupt is only rising or falling nothing else
 * returns EN_extiError_t (EXTI_OK, EXTI_WRONG_SENSE_CTRL)
 */
EN_extiError_t EXTI2_init(EN_senseControl_t);

/* this function is to set the call back function of external interrupt 0
 * takes a pointer to function takes void and returns void
 * returns void
 */
void EXTI0_setCallBack(void (*ptr_callBackFunction)(void));

/* this function is to set the call back function of external interrupt 1
 * takes a pointer to function takes void and returns void
 * returns void
 */
void EXTI1_setCallBack(void (*ptr_callBackFunction)(void));

/* this function is to set the call back function of external interrupt 2
 * takes a pointer to function takes void and returns void
 * returns void
 */
void EXTI2_setCallBack(void (*ptr_callBackFunction)(void));

#endif /*EXTI__H_*/