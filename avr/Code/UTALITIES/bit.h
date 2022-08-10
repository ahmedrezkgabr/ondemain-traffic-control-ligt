/* bit.h file
 * author: ahmed rezk,  github: https://github.com/ahmedrezkgabr
 *                      Li: https://www.linkedin.com/in/ahmed-rezk-926944199
 *                      mail: ahmedrezkofficial@gmail.com
 */
#ifndef BIT__H_
#define BIT__H_

#define     CLR_BIT(Var, Bit_No)        ((Var) &= (~(1 << Bit_No)))
#define     SET_BIT(Var, Bit_No)        ((Var) |= (1 << Bit_No))
#define     TGL_BIT(Var, Bit_No)        ((Var) ^= (1 << Bit_No))
#define     GET_BIT(Var, Bit_NO)        ((Var>>Bit_NO)&1)

#endif  /*BIT__H_*/
