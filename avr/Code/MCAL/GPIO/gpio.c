#include "../../UTALITIES/bit.h"      /*included here to be not accessable to the uper layers*/
#include "../../UTALITIES/register.h" /*included here to be not accessable to the uper layers*/
#include "gpio.h"

EN_gpioError_t GPIO_initPin(EN_pin_t pinNumber, EN_port_t portNumber, EN_direction_t direction)
{
    /* function skeleton
     * 1-check if the pin is available
     * 2-switch over the portNumber
     *     2.1-in each case check the direction
     *         2.1.1-if the direction IN, CLR the corresponding bit in DDRx
     *         2.1.2-if the direction OUT, SET the corresponding bit in DDRx
     *         2.1.3-if not IN or OUT, then WRONG_DIRECTION
     *     2.2-if not A, B, C, or D, then WRONG_PORT
     *  3-return the result
     */

    EN_gpioError_t ret = GPIO_OK;
    if ((pinNumber < PIN_0) || (pinNumber > PIN_7))
    {
        ret = WRONG_PIN;
    }

    if (ret == GPIO_OK)
    {
        switch (portNumber)
        {
        case PORT_A:
            if (direction == IN)
            {
                CLR_BIT(DDRA, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(DDRA, pinNumber);
            }
            else
            {
                ret = WRONG_DIRECTION;
            }
            break;

        case PORT_B:
            if (direction == IN)
            {
                CLR_BIT(DDRB, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(DDRB, pinNumber);
            }
            else
            {
                ret = WRONG_DIRECTION;
            }
            break;

        case PORT_C:
            if (direction == IN)
            {
                CLR_BIT(DDRC, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(DDRC, pinNumber);
            }
            else
            {
                ret = WRONG_DIRECTION;
            }
            break;

        case PORT_D:
            if (direction == IN)
            {
                CLR_BIT(DDRD, pinNumber);
            }
            else if (direction == OUT)
            {
                SET_BIT(DDRD, pinNumber);
            }
            else
            {
                ret = WRONG_DIRECTION;
            }
            break;

        default:
            ret = WRONG_PORT;
            break;
        }
    }

    return ret;
}

EN_gpioError_t GPIO_writePin(EN_pin_t pinNumber, EN_port_t portNumber, EN_value_t value)
{
    /* function skeleton
     * 1-check if the pin is available
     * 2-switch over the portNumber
     *     2.1-in each case check the value
     *         2.1.1-if the value LOW, CLR the corresponding bit in PORTx
     *         2.1.2-if the value HIGH, SET the corresponding bit in PORTx
     *         2.1.3-if not HIGH or LOW, then WRONG_VALUE
     *     2.2-if not A, B, C, or D, then WRONG_PORT
     * 3-return the result
     */

    EN_gpioError_t ret = GPIO_OK;
    if ((pinNumber < PIN_0) || (pinNumber > PIN_7))
    {
        ret = WRONG_PIN;
    }

    if (ret == GPIO_OK)
    {
        switch (portNumber)
        {
        case PORT_A:
            if (value == LOW)
            {
                CLR_BIT(PORTA, pinNumber);
            }
            else if (value == HIGH)
            {
                SET_BIT(PORTA, pinNumber);
            }
            else
            {
                ret = WRONG_VALUE;
            }
            break;

        case PORT_B:
            if (value == LOW)
            {
                CLR_BIT(PORTB, pinNumber);
            }
            else if (value == HIGH)
            {
                SET_BIT(PORTB, pinNumber);
            }
            else
            {
                ret = WRONG_VALUE;
            }
            break;

        case PORT_C:
            if (value == LOW)
            {
                CLR_BIT(PORTC, pinNumber);
            }
            else if (value == HIGH)
            {
                SET_BIT(PORTC, pinNumber);
            }
            else
            {
                ret = WRONG_VALUE;
            }
            break;

        case PORT_D:
            if (value == LOW)
            {
                CLR_BIT(PORTD, pinNumber);
            }
            else if (value == HIGH)
            {
                SET_BIT(PORTD, pinNumber);
            }
            else
            {
                ret = WRONG_VALUE;
            }
            break;

        default:
            ret = WRONG_PORT;
            break;
        }
    }

    return ret;
}

EN_gpioError_t GPIO_readPin(EN_pin_t pinNumber, EN_port_t portNumber, EN_value_t *value)
{
    /* function skeleton
     * 1-check if the pin is available
     * 2-switch over the portNumber
     *    2.1-in each case fill the value buffer with the content of PINx register
     *    2.2-if not A, B, C, or D, then WRONG_PORT
     * 3-return the result
     */

    EN_gpioError_t ret = GPIO_OK;
    if ((pinNumber < PIN_0) || (pinNumber > PIN_7))
    {
        ret = WRONG_PIN;
    }

    if (ret == GPIO_OK)
    {
        switch (portNumber)
        {
        case PORT_A:
            *value = GET_BIT(PINA, pinNumber);
            break;

        case PORT_B:
            *value = GET_BIT(PINB, pinNumber);
            break;

        case PORT_C:
            *value = GET_BIT(PINC, pinNumber);
            break;

        case PORT_D:
            *value = GET_BIT(PIND, pinNumber);
            break;

        default:
            ret = WRONG_PORT;
            break;
        }
    }

    return ret;
}

EN_gpioError_t GPIO_togglePin(EN_pin_t pinNumber, EN_port_t portNumber)
{
    /* function skeleton
     * 1-check if the pin is available
     * 2-switch over the portNumber
     *     2.1-in each case toggle the corresponding bit in PORTx register
     *     2.2-if not A, B, C, or D, then WRONG_PORT
     * 3-return the result
     */

    EN_gpioError_t ret = GPIO_OK;
    if ((pinNumber < PIN_0) || (pinNumber > PIN_7))
    {
        ret = WRONG_PIN;
    }

    if (ret == GPIO_OK)
    {
        switch (portNumber)
        {
        case PORT_A:
            TGL_BIT(PORTA, pinNumber);
            break;

        case PORT_B:
            TGL_BIT(PORTB, pinNumber);
            break;

        case PORT_C:
            TGL_BIT(PORTC, pinNumber);
            break;

        case PORT_D:
            TGL_BIT(PORTD, pinNumber);
            break;

        default:
            ret = WRONG_PORT;
            break;
        }
    }

    return ret;
}

EN_gpioError_t GPIO_initPort(EN_port_t portNumber, uint8_t direction)
{
    /* function skeleton
     * 1-switch over the portNumber
     *     1.1-in each case SET DDRx register to the direction
     *     1.2-if not A, B, C, or D, then WRONG_PORT
     * 2-return the result
     */
    
    EN_gpioError_t ret = GPIO_OK;

    switch (portNumber)
    {
    case PORT_A:
        DDRA = direction;
        break;
    case PORT_B:
        DDRB = direction;
        break;
    case PORT_C:
        DDRC = direction;
        break;
    case PORT_D:
        DDRD = direction;
        break;
    default:
        ret = WRONG_PORT;
        break;
    }

    return ret;
}

EN_gpioError_t GPIO_writePort(EN_port_t portNumber, uint8_t value)
{
    /* function skeleton
     * 1-switch over the portNumber
     *     1.1-in each case fill PORTx register with the content of value
     *     1.2-1.2-if not A, B, C, or D, then WRONG_PORT
     * 2-return the result
     */
    EN_gpioError_t ret = GPIO_OK;
    switch (portNumber)
    {
    case PORT_A:
        PORTA = value;
        break;
    case PORT_B:
        PORTB = value;
        break;
    case PORT_C:
        PORTC = value;
        break;
    case PORT_D:
        PORTD = value;
        break;
    default:
        ret = WRONG_PORT;
        break;
    }

    return ret;
}

EN_gpioError_t GPIO_readPort(EN_port_t portNumber, uint8_t *value)
{
    /* function skeleton
     * 1-switch over the portNumber
     *      1.1-in each case fill the value buffer with the content of PINx register
     *      1.2-1.2-if not A, B, C, or D, then WRONG_PORT
     * 2-return the result
     */
    EN_gpioError_t ret = GPIO_OK;
    switch (portNumber)
    {
    case PORT_A:
        *value = PINA;
        break;
    case PORT_B:
        *value = PINB;
        break;
    case PORT_C:
        *value = PINC;
        break;
    case PORT_D:
        *value = PIND;
        break;
    default:
        ret = WRONG_PORT;
        break;
    }

    return ret;
}

EN_gpioError_t GPIO_togglePort(EN_port_t portNumber)
{
    /* function skeleton
     * 1-switch over the portNumber
     *      1.1-in each case toggle the content of PORTx register
     *      1.2-1.2-if not A, B, C, or D, then WRONG_PORT
     * 2-return the result
     */
    EN_gpioError_t ret = GPIO_OK;
    switch (portNumber)
    {
    case PORT_A:
        PORTA = ~PORTA;
        break;
    case PORT_B:
        PORTB = ~PORTB;
        break;
    case PORT_C:
        PORTC = ~PORTC;
        break;
    case PORT_D:
        PORTD = ~PORTD;
        break;
    default:
        ret = WRONG_PORT;
        break;
    }

    return ret;
}