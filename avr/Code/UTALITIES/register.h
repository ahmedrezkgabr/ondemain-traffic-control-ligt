/* register.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */

#ifndef REGISTER__H_
#define REGISTER__H_

#define SREG (*(volatile uint8_t *)0x5F) /*Status Register*/

/*GPIO registers*/
/*Data Direction Register*/
#define DDRA (*(volatile uint8_t *)0x3A)
#define DDRB (*(volatile uint8_t *)0x37)
#define DDRC (*(volatile uint8_t *)0x34)
#define DDRD (*(volatile uint8_t *)0x31)

/*Input Pins Address*/
#define PINA (*(volatile uint8_t *)0x39)
#define PINB (*(volatile uint8_t *)0x36)
#define PINC (*(volatile uint8_t *)0x33)
#define PIND (*(volatile uint8_t *)0x30)

/*Port Data Register*/
#define PORTA (*(volatile uint8_t *)0x3B)
#define PORTB (*(volatile uint8_t *)0x38)
#define PORTC (*(volatile uint8_t *)0x35)
#define PORTD (*(volatile uint8_t *)0x32)

/*TIMERS registers*/
#define TIMSK (*(volatile uint8_t *)0x59) /*Timer/Counter Interrupt Mask Register*/
#define TIFR (*(volatile uint8_t *)0x58)  /*Timer/Counter Interrupt Flag Register*/

/*TIMER0*/
#define TCCR0 (*(volatile uint8_t *)0x53) /*Timer/Counter Control Register*/
#define TCNT0 (*(volatile uint8_t *)0x52) /*Timer/Counter Register*/
#define OCR0 (*(volatile uint8_t *)0x5C)  /*Output Compare Register*/

/*TIMER1*/
#define TCCR1A (*(volatile uint8_t *)0x4F)  /*Timer/Counter1 Control Register A*/
#define TCCR1B (*(volatile uint8_t *)0x4E)  /*Timer/Counter1 Control Register B*/
#define TCNT1H (*(volatile uint8_t *)0x4D)  /*Timer/Counter1 High Register*/
#define TCNT1L (*(volatile uint16_t *)0x4C) /*Timer/Counter1 Low Register*/
#define OCR1AH (*(volatile uint8_t *)0x4B)  /*Output Compare Register 1 A High*/
#define OCR1AL (*(volatile uint16_t *)0x4A) /*Output Compare Register 1 A Low*/
#define OCR1BH (*(volatile uint8_t *)0x49)  /*Output Compare Register 1 B High*/
#define OCR1BL (*(volatile uint16_t *)0x48) /*Output Compare Register 1 B Low*/
#define ICR1H (*(volatile uint8_t *)0x47)   /*Input Capture Register 1 High*/
#define ICR1L (*(volatile uint16_t *)0x46)  /*Input Capture Register 1 Low*/

/*TIMER2*/
#define TCCR2 (*(volatile uint8_t *)0x45) /*Timer/Counter Control Register*/
#define TCNT2 (*(volatile uint8_t *)0x44) /*Timer/Counter Register*/
#define OCR2 (*(volatile uint8_t *)0x43)  /*Output Compare Register*/

/*EXTI registers*/
#define MCUCR (*(volatile uint8_t *)0x55)  /*MCU Control Register*/
#define MCUCSR *((volatile uint8_t *)0x54) /*MCU Control and Status Register*/
#define GICR (*(volatile uint8_t *)0x5B)   /*General Interrupt Control Register*/
#define GIFR (*(volatile uint8_t *)0x5A)   /*General Interrupt Flag Register*/

/*ADC registers*/
#define ADMUX (*(volatile uint8_t *)0x27)  /*ADC Multiplixer Register Selection*/
#define ADCSRA (*(volatile uint8_t *)0x26) /*ADC Control And Status Register*/
#define ADCL (*(volatile uint8_t *)0x24)   /*ADC Data Register Low*/
#define ADCH (*(volatile uint8_t *)0x25)   /*ADC Data Register High*/

#endif /*REGISTER__H_*/