/* BitMath.h
 *

 *      Author: Tarek Maher
 */

#ifndef MCAL_EXINT_EXINT_INTERFACE_H_
#define MCAL_EXINT_EXINT_INTERFACE_H_

void __vector_1(void)    __attribute__((signal,used));
void EXTI_voidInit0();
void EXTI_voidEnableEXTI0();
void EXTI_voidDisableEXTI0();
void EXTI_voidSetSignalLatch0(u8 EXTISenseMode);

void __vector_2(void)    __attribute__((signal,used));
void EXTI_voidInit1();
void EXTI_voidEnableEXTI1();
void EXTI_voidDisableEXTI1();
void EXTI_voidSetSignalLatch1(u8 EXTISenseMode);

void __vector_3(void)    __attribute__((signal,used));
void EXTI_voidInit2();
void EXTI_voidEnableEXTI2();
void EXTI_voidDisableEXTI2();
void EXTI_voidSetSignalLatch2(u8 EXTISenseMode);

void EXTI_voidSetCallBack(void (*ptr) (void));
#endif /* MCAL_EXINT_EXINT_INTERFACE_H_ */
