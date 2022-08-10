#include "../../UTALITIES/register.h" /*included here to be not accessable to the uper layers*/
#include "../../UTALITIES/bit.h"      /*included here to be not accessable to the uper layers*/

#include "gie.h"

void GIE_enable()
{
    /* general interrupt enabled by setting bit I in Status Register */
    SET_BIT(SREG, I);
}

void GIE_disable()
{
    /* general interrupt enabled by clearing bit I in Status Register */
    CLR_BIT(SREG, I);
}