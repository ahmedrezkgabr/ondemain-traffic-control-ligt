
#include "button.h"

EN_buttonError_t BUTTON_init(ST_button_t button)
{
    /* function skeleton
     * 1-call GPIO_initPin and pass buttonPin, buttonPort, and IN as the direction
     * 2-switch over the flag (return of GPIO_initPin)
     *      2.1-in each case fill the result with the corresponding EN_ledError_t
     * 3-return the result
     */

    EN_buttonError_t ret = BUTTON_OK;
    EN_gpioError_t flag;

    /* 1-call GPIO_initPin and pass buttonPin, buttonPort, and IN as the direction (button is an input device) */
    flag = GPIO_initPin(button.buttonPin, button.buttonPort, IN);

    /* 2-switch over the flag (return of GPIO_initPin) */
    switch (flag)
    {
        /* 2.1-in each case fill the result with the corresponding EN_ledError_t */
    case GPIO_OK:
        ret = BUTTON_OK;
        break;
    case WRONG_PIN:
        ret = WRONG_BUTTON_PIN;
        break;
    case WRONG_PORT:
        ret = WRONG_BUTTON_PORT;
    default:
        break;
    }

    /* 3-return the result */
    return ret;
}
EN_buttonError_t BUTTON_getState(ST_button_t *pButton)
{
    /* function skeleton
     * 1-call GPIO_readPin and pass buttonPin, buttonPort, and the address of buttonState to be the value buffer
     * 2-switch over the flag (return of GPIO_readPin)
     *      2.1-in each case fill the result with the corresponding EN_ledError_t
     * 3-return the result
     */

    EN_buttonError_t ret = BUTTON_OK;
    EN_gpioError_t flag;

    /* 1-call GPIO_readPin and pass buttonPin, buttonPort, and the address of buttonState to be the value buffer */
    flag = GPIO_readPin(pButton->buttonPin, pButton->buttonPort, &pButton->buttonState);

    /* 2-switch over the flag (return of GPIO_initPin) */
    switch (flag)
    {
        /* 2.1-in each case fill the result with the corresponding EN_ledError_t */
    case GPIO_OK:
        ret = BUTTON_OK;
        break;
    case WRONG_PIN:
        ret = WRONG_BUTTON_PIN;
        break;
    case WRONG_PORT:
        ret = WRONG_BUTTON_PORT;
    default:
        break;
    }

    /* 3-return the result */
    return ret;
}
