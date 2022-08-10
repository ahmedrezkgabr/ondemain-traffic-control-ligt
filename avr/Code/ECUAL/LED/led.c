#include "led.h"

EN_ledError_t LED_init(ST_led_t led)
{
    /* function skeleton
     * 1-call GPIO_initPin and pass ledPin, ledPort, and OUT as the direction
     * 2-switch over the flag (return of GPIO_initPin)
     *      2.1-in each case fill the result with the corresponding EN_ledError_t
     * 3-return the result
     */
    EN_ledError_t ret = LED_OK;
    EN_gpioError_t flag;

    /* 1-call GPIO_initPin and pass ledPin, ledPort, and OUT as the direction */
    flag = GPIO_initPin(led.ledPin, led.ledPort, OUT); // output device

    /* 2-switch over the flag (return of GPIO_initPin) */
    switch (flag)
    {
        /* 2.1-in each case fill the result with the corresponding EN_ledError_t */
    case GPIO_OK:
        ret = LED_OK;
        break;
    case WRONG_PIN:
        ret = WRONG_LED_PIN;
        break;
    case WRONG_PORT:
        ret = WRONG_LED_PORT;
    default:
        break;
    }
    /* 3-return the result */
    return ret;
}

EN_ledError_t LED_on(ST_led_t led)
{
    /* function skeleton
     * 1-call GPIO_writePin and pass ledPin, ledPort, and HIGH as a value
     * 2-switch over the flag (return of GPIO_writePin)
     *      2.1-in each case fill the result with the corresponding EN_ledError_t
     * 3-return the result
     */
    EN_ledError_t ret = LED_OK;
    EN_gpioError_t flag;

    /* 1-call GPIO_writePin and pass ledPin, ledPort, and HIGH as a value */
    flag = GPIO_writePin(led.ledPin, led.ledPort, HIGH); // led on when high

    /* 2-switch over the flag (return of GPIO_writePin) */
    switch (flag)
    {
        /* 2.1-in each case fill the result with the corresponding EN_ledError_t */
    case GPIO_OK:
        ret = LED_OK;
        break;
    case WRONG_PIN:
        ret = WRONG_LED_PIN;
        break;
    case WRONG_PORT:
        ret = WRONG_LED_PORT;
    default:
        break;
    }

    /* 3-return the result */
    return ret;
}

EN_ledError_t LED_off(ST_led_t led)
{
    /* function skeleton
     * 1-call GPIO_writePin and pass ledPin, ledPort, and LOW as a value
     * 2-switch over the flag (return of GPIO_writePin)
     *     2.1-in each case fill the result with the corresponding EN_ledError_t
     * 3-return the result
     */
    EN_ledError_t ret = LED_OK;
    EN_gpioError_t flag;

    /* 1-call GPIO_writePin and pass ledPin, ledPort, and LOW as a value */
    flag = GPIO_writePin(led.ledPin, led.ledPort, LOW); // led on when low

    /* 2-switch over the flag (return of GPIO_writePin) */
    switch (flag)
    {
        /* 2.1-in each case fill the result with the corresponding EN_ledError_t */
    case GPIO_OK:
        ret = LED_OK;
        break;
    case WRONG_PIN:
        ret = WRONG_LED_PIN;
        break;
    case WRONG_PORT:
        ret = WRONG_LED_PORT;
    default:
        break;
    }

    /* 3-return the result */
    return ret;
}

EN_ledError_t LED_toggle(ST_led_t led)
{
    /* function skeleton
     * 1-call GPIO_togglePin and pass ledPin and ledPort
     * 2-switch over the flag (return of GPIO_togglePin)
     *    2.1-in each case fill the result with the corresponding EN_ledError_t
     * 3-return the result
     */
    EN_ledError_t ret = LED_OK;
    EN_gpioError_t flag;

    /* 1-call GPIO_togglePin and pass ledPin and ledPort */
    flag = GPIO_togglePin(led.ledPin, led.ledPort);

    /* 2-switch over the flag (return of GPIO_togglePin) */
    switch (flag)
    {
        /* 2.1-in each case fill the result with the corresponding EN_ledError_t */
    case GPIO_OK:
        ret = LED_OK;
        break;
    case WRONG_PIN:
        ret = WRONG_LED_PIN;
        break;
    case WRONG_PORT:
        ret = WRONG_LED_PORT;
    default:
        break;
    }

    /* 3-return the result */
    return ret;
}