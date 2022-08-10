/* gie.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */
#ifndef GIE__H_
#define GIE__H_

#include "../../UTALITIES/types.h"

/*bits defination*/
#define I 7

/* this function to enable the global interrupt
 * takes void
 * returns void
 */
void GIE_enable(void);

/* this function to disable the global interrupt
 * takes void
 * returns void
 */
void GIE_disable(void);

#endif /*GIE__H_*/