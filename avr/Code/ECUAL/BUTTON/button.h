/* button.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */

#ifndef BUTTON__H_
#define BUTTON__H_
#include "../../MCAL/GPIO/gpio.h"

typedef enum
{
    BUTTON_OK,
    WRONG_BUTTON_PIN,
    WRONG_BUTTON_PORT
    
} EN_buttonError_t;

typedef struct
{
    EN_pin_t buttonPin;
    EN_port_t buttonPort;
    EN_value_t buttonState;
} ST_button_t;

/* this function is to initialize the button device
 * takes ST_button_t which contain EN_pin_t as buttonPin, EN_port_t as buttonPort, and EN_value_t as buttonState
 * returns EN_buttonError_t (BUTTON_OK, WRONG_BUTTON_PIN, WRONG_BUTTON_PORT)
 */
EN_buttonError_t BUTTON_init(ST_button_t);

/* this function is to get the state of the device
 * takes pointer to ST_button_t which contain EN_pin_t as buttonPin, EN_port_t as buttonPort, and EN_value_t as buttonState
 * returns EN_buttonError_t (BUTTON_OK, WRONG_BUTTON_PIN, WRONG_BUTTON_PORT)
 */
EN_buttonError_t BUTTON_getState(ST_button_t *);

#endif /*BUTTON__H_*/