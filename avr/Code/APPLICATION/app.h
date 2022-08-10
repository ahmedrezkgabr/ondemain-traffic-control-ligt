/* app.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */

#ifndef APP__H_
#define APP__H_

#include "../UTALITIES/types.h"
#include "../MCAL/TIMER/timer.h"
#include "../MCAL/EXTI/exti.h"
#include "../MCAL/GIE/gie.h"
#include "../ECUAL/BUTTON/button.h"
#include "../ECUAL/LED/led.h"

typedef enum
{
    CAR,
    YELLOW_CAR,
    MAN,
    YELLOW_MAN
} EN_systemState_t;

/* this function contains the flowchart of the system and start the system
 * takes void
 * returns void
 */
void APP_start(void);

/* this function is a delay for 1/10 of the sec
 * takes pointer to ST_timer0_t to operate with it
 * returns void
 */
void delayOneTenthSec(ST_timer0_t *);

/* this function is the Interrupt Serviece Routine for timer0
 * takes void
 * returns void
 */
void timerISR(void);

/* this function is the Interrupt Serviece Routine for exti0
 * takes void
 * returns void
 */
void ISR(void);

#endif /*APP__H_*/