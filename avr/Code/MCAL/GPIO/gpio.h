/* gpio.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */

#ifndef GPIO__H_
#define GPIO__H_

#include "../../UTALITIES/types.h"


typedef enum
{
    GPIO_OK,
    WRONG_PIN,
    WRONG_PORT,
    WRONG_DIRECTION,
    WRONG_VALUE
} EN_gpioError_t;

typedef enum
{
    PORT_A = 'A',
    PORT_B = 'B',
    PORT_C = 'C',
    PORT_D = 'D'
} EN_port_t;

typedef enum
{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7
} EN_pin_t;

typedef enum
{
    LOW,
    HIGH
} EN_value_t;

typedef enum
{
    IN,
    OUT
} EN_direction_t;

/* this function is to set the direction of a pin as IN or OUT
 * takes EN_pint_t as pinNumber, EN_port_t as portNumber, and EN_direction_t as the direction
 * returns EN_gpioError_t (GPIO_OK, WRONG_PIN, WRONG_PORT, WRONG_DIRECTION)
 */
EN_gpioError_t GPIO_initPin(EN_pin_t, EN_port_t, EN_direction_t);

/* this function is to write on the bin HIGH or LOW
 * takes EN_pin_t as pinNumber, EN_port_t portNumber, and EN_value_t as value
 * returns EN_gpioError_t (GPIO_OK, WRONG_PIN, WRONG_PORT, WRONG_VALUE)
 */
EN_gpioError_t GPIO_writePin(EN_pin_t, EN_port_t, EN_value_t);

/* this function is to read the value of a bin HIGH or LOW
 * takes EN_pin_t as pinNumber, EN_port_t portNumber, and a pointer to EN_value_t as the value buffer
 * returns EN_gpioError_t (GPIO_OK, WRONG_PIN, WRONG_PORT)
 */
EN_gpioError_t GPIO_readPin(EN_pin_t, EN_port_t, EN_value_t *);

/* this function is to toggle the value of a bin
 * takes EN_pin_t as pinNumber and EN_port_t as portNumber
 * returns EN_gpioError_t (GPIO_OK, WRONG_PIN, WRONG_PORT)
 */
EN_gpioError_t GPIO_togglePin(EN_pin_t, EN_port_t);

/* this function is to set the direction of a port as IN or OUT
 * takes EN_pin_t as pinNumber and uint8_t as the direction
 * returns EN_gpioError_t (GPIO_OK, WRONG_PORT)
 */
EN_gpioError_t GPIO_initPort(EN_port_t, uint8_t);

/* this functin is to write on the bins of the port
 * takes EN_port_t as portNumber and uint8_t as the value
 * returns EN_gpioError_t (GPIO_OK, WRONG_PORT)
 */
EN_gpioError_t GPIO_writePort(EN_port_t, uint8_t);

/* this function is to read the value of the bins of a port
 * takes EN_port_t as portNumber and a pointer to uint8_t as the value buffer
 * returns EN_gpioError_t (GPIO_OK, WRONG_PORT)
 */
EN_gpioError_t GPIO_readPort(EN_port_t, uint8_t *);

/* this function is to toggle the value of the bins of a port
 * takes EN_port_t as portNumber
 * returns EN_gpioError_t (GPIO_OK, WRONG_PORT)
 */
EN_gpioError_t GPIO_togglePort(EN_port_t);

#endif /*GPIO__H_*/