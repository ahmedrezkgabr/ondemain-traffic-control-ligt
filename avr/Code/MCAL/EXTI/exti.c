#include "../../UTALITIES/register.h" /*included here to be not accessable to the uper layers*/
#include "../../UTALITIES/bit.h"      /*included here to be not accessable to the uper layers*/

#include "exti.h"

void (*EXTI0_func)(void) = NULL; /*call back function of exti 0*/
void (*EXTI1_func)(void) = NULL; /*call back function of exti 1*/
void (*EXTI2_func)(void) = NULL; /*call back function of exti 2*/

/*from interrupt vectors table in the datasheet*/
void __vector_1(void) __attribute__((signal)); /*external interrupt 0*/
void __vector_2(void) __attribute__((signal)); /*external interrupt 0*/
void __vector_3(void) __attribute__((signal)); /*external interrupt 0*/

EN_extiError_t EXTI0_init(EN_senseControl_t senseControl)
{
    EN_extiError_t ret = EXTI_OK;

    /*switch over sense control*/
    switch (senseControl)
    {
    case EXTI_LOW_LEVEL: /*ISC00 and ISC01 sould be 0*/
        CLR_BIT(MCUCR, ISC00);
        CLR_BIT(MCUCR, ISC01);
        break;
    case EXTI_CHANGING: /*ISC00 sould be 1 and ISC01 sould be 0*/
        SET_BIT(MCUCR, ISC00);
        CLR_BIT(MCUCR, ISC01);
        break;
    case EXTI_FALLING_EDGE: /*ISC00 sould be 0 and ISC01 sould be 1*/
        CLR_BIT(MCUCR, ISC00);
        SET_BIT(MCUCR, ISC01);
        break;
    case EXTI_RISING_EDGE: /*ISC00 and ISC01 sould be 1*/
        SET_BIT(MCUCR, ISC00);
        SET_BIT(MCUCR, ISC01);
        break;

    default:
        /*passed sense control is wrong*/
        ret = EXTI_WRONG_SENSE_CTRL;
        break;
    }

    /*enable the extirnal interrupt 0 by setting 1 to bit INT0*/
    SET_BIT(GICR, INT0);

    return ret;
}

EN_extiError_t EXTI1_init(EN_senseControl_t senseControl)
{
    EN_extiError_t ret = EXTI_OK;
    switch (senseControl)
    {
    case EXTI_LOW_LEVEL: /*ISC10 and ISC11 sould be 0*/
        CLR_BIT(MCUCR, ISC10);
        CLR_BIT(MCUCR, ISC11);
        break;
    case EXTI_CHANGING: /*ISC10 sould be 1 and ISC11 sould be 0*/
        SET_BIT(MCUCR, ISC10);
        CLR_BIT(MCUCR, ISC11);
        break;
    case EXTI_FALLING_EDGE: /*ISC10 sould be 0 and ISC11 sould be 1*/
        CLR_BIT(MCUCR, ISC10);
        SET_BIT(MCUCR, ISC11);
        break;
    case EXTI_RISING_EDGE: /*ISC10 and ISC11 sould be 1*/
        SET_BIT(MCUCR, ISC10);
        SET_BIT(MCUCR, ISC11);
        break;

    default:
        /*passed sense control is wrong*/
        ret = EXTI_WRONG_SENSE_CTRL;
        break;
    }

    /*enable the extirnal interrupt 1 by setting 1 to bit INT1*/
    SET_BIT(GICR, INT1);

    return ret;
}

EN_extiError_t EXTI2_init(EN_senseControl_t senseControl)
{
    EN_extiError_t ret = EXTI_OK;

    /*switch over sense control*/
    switch (senseControl)
    {
    case EXTI_FALLING_EDGE: /*ISC2 sould be 0*/
        CLR_BIT(MCUCSR, ISC2);
        break;
    case EXTI_RISING_EDGE: /*ISC2 sould be 1*/
        SET_BIT(MCUCSR, ISC2);
        break;

    default:
        /*passed sense control is wrong (this interrupt has only falling and rising sense control not else*/
        ret = EXTI_WRONG_SENSE_CTRL;
        break;
    }

    /*enable the extirnal interrupt 2 by setting 1 to bit INT2*/
    SET_BIT(GICR, INT2);

    return ret;
}

void EXTI0_setCallBack(void (*ptr_callBackFunction)(void))
{
    /*setting the call back function with the user function*/
    EXTI0_func = ptr_callBackFunction;
}

void __vector_1(void)
{
    /*called when INTF0 is set to one*/
    if (EXTI0_func != NULL)
        EXTI0_func();
}

void EXTI1_setCallBack(void (*ptr_callBackFunction)(void))
{
    /*setting the call back function with the user function*/
    EXTI1_func = ptr_callBackFunction;
}

void __vector_2(void)
{
    /*called when INTF1 is set to one*/
    if (EXTI1_func != NULL)
        EXTI1_func();
}

void EXTI2_setCallBack(void (*ptr_callBackFunction)(void))
{
    /*setting the call back function with the user function*/
    EXTI2_func = ptr_callBackFunction;
}

void __vector_3(void)
{
    /*called when INTF2 is set to one*/
    if (EXTI2_func != NULL)
        EXTI2_func();
}