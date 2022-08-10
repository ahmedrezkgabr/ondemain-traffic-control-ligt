#include "keypad.h"

void KEYPAD_init(void)
{
    /* function skeleton
     * 1-init the column pins to be OUT
     * 2-SET the colum pins to HIGH
     * 3-init the row pins to be IN
     * 4-SET the row pins to HIGH to activate the internal pullup resistors
     */

    /* 1-init the column pins to be OUT */
    GPIO_initPin(KPD_COLUMN0_PIN, KPD_PORT, OUT);
    GPIO_initPin(KPD_COLUMN1_PIN, KPD_PORT, OUT);
    GPIO_initPin(KPD_COLUMN2_PIN, KPD_PORT, OUT);
    GPIO_initPin(KPD_COLUMN3_PIN, KPD_PORT, OUT);

    /* 2-SET the colum pins to HIGH */
    GPIO_writePin(KPD_COLUMN0_PIN, KPD_PORT, HIGH);
    GPIO_writePin(KPD_COLUMN1_PIN, KPD_PORT, HIGH);
    GPIO_writePin(KPD_COLUMN2_PIN, KPD_PORT, HIGH);
    GPIO_writePin(KPD_COLUMN3_PIN, KPD_PORT, HIGH);

    /* 3-init the row pins to be IN */
    GPIO_initPin(KPD_ROW0_PIN, KPD_PORT, IN);
    GPIO_initPin(KPD_ROW1_PIN, KPD_PORT, IN);
    GPIO_initPin(KPD_ROW2_PIN, KPD_PORT, IN);
    GPIO_initPin(KPD_ROW3_PIN, KPD_PORT, IN);

    /* 4-SET the row pins to HIGH to activate the internal pullup resistors */
    GPIO_writePin(KPD_ROW0_PIN, KPD_PORT, HIGH);
    GPIO_writePin(KPD_ROW1_PIN, KPD_PORT, HIGH);
    GPIO_writePin(KPD_ROW2_PIN, KPD_PORT, HIGH);
    GPIO_writePin(KPD_ROW3_PIN, KPD_PORT, HIGH);
}

uint8_t KEYPAD_getPressedKey(void)
{
    /* function skeleton
     * 1-declare the function local variables
     * 2-iterate over the columns
     *      2.1-in each iteration SET the corresponding pin as LOW
     *      2.2-iterate over the rows
     *          2.2.1-in each iteration check read the corresponding pin
     *              2.2.1.1-if it is LOW, then the corresponding key is pressed
     *                  2.2.1.1.1-wait for long press
     *                  2.2.1.1.2-SET the column again to HIGH
     *                  2.2.1.1.3 return the pressedKey
     *      2.3-if no keys in this column pressed, SET the column again to HIGH
     * 3-return the pressedKey (NOT_PRESSED)
     */

    /* 1-declare the function local variables */
    uint8_t pressedKey = NOT_PRESSED;
    uint8_t keysArray[COLUMN_SIZE][ROW_SIZE] = KPD_ARR;
    uint8_t columnIndx, rowIndx;
    EN_value_t state = HIGH;

    uint8_t columnsArray[] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN, KPD_COLUMN3_PIN};

    uint8_t rowsArray[] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};

    /* 2-iterate over the columns */
    for (columnIndx = 0; columnIndx < COLUMN_SIZE; columnIndx++)
    {
        /* 2.1-in each iteration SET the corresponding pin as LOW */
        GPIO_writePin(columnsArray[columnIndx], KPD_PORT, LOW);

        /* 2.2-iterate over the rows */
        for (rowIndx = 0; rowIndx < ROW_SIZE; rowIndx++)
        {
            /* 2.2.1-in each iteration check read the corresponding pin */
            GPIO_readPin(rowsArray[rowIndx], KPD_PORT, &state);

            /*  2.2.1.1-if it is LOW, then the corresponding key is pressed */
            if (state == LOW) /*key pressed*/
            {
                pressedKey = keysArray[rowIndx][columnIndx];

                /* 2.2.1.1.1-wait for long press */
                while (state == LOW)
                {

                    GPIO_readPin(rowsArray[rowIndx], KPD_PORT, &state);
                }

                /* 2.2.1.1.2-SET the column again to HIGH */
                GPIO_writePin(columnsArray[columnIndx], KPD_PORT, HIGH);

                /* 2.2.1.1.3 return the pressedKey */
                return pressedKey;
            }
        }

        /* 2.3-if no keys in this column pressed, SET the column again to HIGH */
        GPIO_writePin(columnsArray[columnIndx], KPD_PORT, HIGH);
    }

    /* 3-return the pressedKey (NOT_PRESSED) */
    return pressedKey;
}