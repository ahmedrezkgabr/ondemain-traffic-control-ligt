/* types.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */

#ifndef TYPES__H_
#define TYPES__H_

typedef unsigned char uint8_t;
typedef signed char sint8_t;

typedef unsigned short int uint16_t;
typedef signed short int sint16_t;

typedef unsigned long int uint32_t;
typedef signed long int sint32_t;

typedef float f32_t;
typedef double f64_t;
typedef long double f128_t;

#define NULL ((void *)0)

typedef enum
{
    FALSE,
    TRUE
} EN_bool_t;

#endif /*TYPES__H_*/