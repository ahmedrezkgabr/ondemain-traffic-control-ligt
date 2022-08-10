/* led.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */

#ifndef LED__H_
#define LED__H
#include "../../MCAL/GPIO/gpio.h"
typedef enum
{
    LED_OK,
    WRONG_LED_PIN,
    WRONG_LED_PORT
} EN_ledError_t;

typedef struct
{
    EN_pin_t ledPin;
    EN_port_t ledPort;
    
} ST_led_t;


/* this function is to initialize the led device
 * takes ST_led_t which contain EN_pin_t as ledPin and EN_port_t as ledPort
 * returns EN_ledError_t (LED_OK, WRONG_LED_PIN, WRONG_LED_PORT)
 */
EN_ledError_t LED_init(ST_led_t);

/* this function is to set the led device to be on
 * takes ST_led_t which contain EN_pin_t as ledPin and EN_port_t as ledPort
 * returns EN_ledError_t (LED_OK, WRONG_LED_PIN, WRONG_LED_PORT)
 */
EN_ledError_t LED_on(ST_led_t);

/* this function is to set the led device to be off
 * takes ST_led_t which contain EN_pin_t as ledPin and EN_port_t as ledPort
 * returns EN_ledError_t (LED_OK, WRONG_LED_PIN, WRONG_LED_PORT)
 */
EN_ledError_t LED_off(ST_led_t);

/* this function is to toggle the led device state (on, off)
 * takes ST_led_t which contain EN_pin_t as ledPin and EN_port_t as ledPort
 * returns EN_ledError_t (LED_OK, WRONG_LED_PIN, WRONG_LED_PORT)
 */
EN_ledError_t LED_toggle(ST_led_t);

#endif /*LED__H_*/