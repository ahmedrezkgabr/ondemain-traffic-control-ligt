#include "app.h"

EN_systemState_t currentState = CAR;
uint8_t counter = 0, timerCounter = 0;
ST_timer0_t timer;

void APP_start(void)
{
    /*---------------------------------------------------
     *SETUP CODE
     *---------------------------------------------------*/
    GPIO_initPin(PIN_0, PORT_C, OUT);
    /*init the leds of the cars*/
    ST_led_t greenCarLed = {PIN_0, PORT_A};
    ST_led_t yellowCarLed = {PIN_1, PORT_A};
    ST_led_t redCarLed = {PIN_2, PORT_A};

    LED_init(greenCarLed);
    LED_init(yellowCarLed);
    LED_init(redCarLed);

    /*init the leds of the men*/
    ST_led_t greenManLed = {PIN_0, PORT_B};
    ST_led_t yellowManLed = {PIN_1, PORT_B};
    ST_led_t redManLed = {PIN_2, PORT_B};

    LED_init(greenManLed);
    LED_init(yellowManLed);
    LED_init(redManLed);

    /*init the button*/
    ST_button_t button = {PIN_2, PORT_D};

    BUTTON_init(button);

    /*enable the general interrupt*/
    GIE_enable();

    /*init the timer*/
    timer.mode = TIMER0_NORMAL;
    timer.ocMode = OC0_DISCONNECTED;
    timer.prescaler = TIMER0_1024_PS;
    TIMER0_init(&timer);

    /*enable the overflow interrupt*/
    TIMER0_OVF_interruptEnable();

    /*set the calback function of the timer0 interrupt*/
    TIMER0_OVF_setCallBackFunction(&timerISR);

    /*init the exti0*/
    EXTI0_init(EXTI_FALLING_EDGE);

    /*set the callback function of the exti0*/
    EXTI0_setCallBack(&ISR);

    /*---------------------------------------------------
     *SUPER LOOP CODE
     *---------------------------------------------------*/
    while (TRUE)
    {
        /*switch the state of the system*/
        switch (currentState)
        {
        case CAR:
            if (counter < 50) /*in the 5 sec of the state*/
            {
                /* in CAR mode:
                 *              the car green light is on
                 *              the man red light is on
                 *              the other light is off
                 * */
                
                LED_on(greenCarLed);
                LED_on(redManLed);

                LED_off(greenManLed);
                LED_off(redCarLed);
                LED_off(yellowManLed);
                LED_off(yellowCarLed);

                /*increment the counter*/
                counter++;
            }
            else
            {
                currentState = YELLOW_CAR;
                counter = 0;
            }
            break;
        case YELLOW_CAR:
            if (counter < 50) /*in the 5 sec of the state*/
            {
                /* in YELLOW_CAR mode:
                 *              the car yellow light is on and toggle
                 *              the man red light is on
                 *              the other light is off
                 * */
                
                LED_on(redManLed);

                LED_off(redCarLed);

                LED_off(greenCarLed);
                LED_off(greenManLed);

                LED_off(yellowManLed);
                if ((counter % 5) == 0) /*toggling every 0.5 sec*/
                {
                    /*toggle the yellow of the car*/
                    LED_toggle(yellowCarLed);
                }

                /*increment the counter*/
                counter++;
            }
            else
            {
                /*change the state to the next*/
                currentState = MAN;

                /*reset the counter*/
                counter = 0;
            }
            break;
        case MAN:
            if (counter < 50) /*in the 5 sec of the state*/
            {
                /* in MAN mode:
                 *              the car red light is on
                 *              the man green light is on
                 *              the other light is off
                 * */

                LED_on(greenManLed);
                LED_on(redCarLed);

                LED_off(greenCarLed);
                LED_off(redManLed);
                LED_off(yellowCarLed);
                LED_off(yellowManLed);
                /*increment the counter*/
                counter++;
            }
            else
            {
                /*change the state to the next*/
                currentState = YELLOW_MAN;

                /*reset the counter*/
                counter = 0;
            }
            break;
        case YELLOW_MAN:
            if (counter < 50) /*in the 5 sec of the state*/
            {
                /* in YELLOW_MAN mode:
                 *              the man yellow light is on and toggle
                 *              the car red light is on
                 *              the other light is off
                 * */
                LED_on(redCarLed);

                LED_off(redManLed);
                LED_off(greenCarLed);
                LED_off(greenManLed);
                LED_off(yellowCarLed);
                if ((counter % 5) == 0) /*toggling every 0.5 sec*/
                {
                    /*toggle the yellow of the man*/
                    LED_toggle(yellowManLed);
                }
                
                /*increment the counter*/
                counter++;
            }
            else
            {
                /*change the state to the next*/
                currentState = CAR;

                /*reset the counter*/
                counter = 0;
            }
            break;

        default:
            break;
        }

        /*wait to 1/10 of the sec*/
        delayOneTenthSec(&timer);
    }
}

void delayOneTenthSec(ST_timer0_t *ptr_timer0)
{
    uint8_t flag = TRUE;
    uint8_t nothing = 0;

    /*start the timer*/
    TIMER0_start(ptr_timer0);
    /*wait until the number of overflows*/
    while (flag)
    {
        TIMER0_getTimerValue(&nothing);
        switch (timerCounter)
        {
        case 3:

            flag = FALSE;
            break;
        default:
            break;
        }
    }

    /*reset the overflow counter*/
    timerCounter = 0;

    /*stop the timer*/
    TIMER0_stop();
}

void ISR(void)
{
    /*switch over the current state of the system*/
    switch (currentState)
    {
    case CAR: /*in CAR state change the state to YELLOW_CAR and make the counter 0*/
        currentState = YELLOW_CAR;
        counter = 0;
        break;
    case YELLOW_CAR: /*in YELLOW_CAR state*/
        /* code */
        break;
    case MAN: /*in MAN state*/
        /* code */
        break;
    case YELLOW_MAN: /*in YELLOW_MAN*/
        /* code */
        break;

    default:
        break;
    }
}

void timerISR(void)
{
    /*increment the counter that indicates the overflows number*/
    timerCounter++;
}
