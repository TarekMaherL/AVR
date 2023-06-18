/* BitMath.h
 *

 *      Author: Tarek Maher
 */

#ifndef MCAL_EXINT_EXINT_PRIVATE_H_
#define MCAL_EXINT_EXINT_PRIVATE_H_

// MCUCR MCUCSR GICR

#define MCUCR   *((volatile u8*)0x55)
#define MCUCSR  *((volatile u8*)0x54)
#define GIFR    *((volatile u8*)0x5A)
#define SREG    *((volatile u8*)0x5F)
#define GICR	*((volatile u8*)0x5B)

/* Modes */
#define LOW_LEVEL		1
#define LOGICAL_CHANGE	2
#define FALLING_EDGE	3
#define RISING_EDGE		4

/* Interrupt Control (GICR) */
#define INT0	6
#define INT1	7
#define INT2	5

/* Interrupt Flags (GIFR) */
#define INTF0	6
#define INTF1	7
#define INTF2	5

/* MCUCR Register */
#define ISC00	0
#define ISC01	1
#define ISC10	2
#define ISC11	3

/* MCUCSR Register */
#define ISC2	6

#endif /* MCAL_EXINT_EXINT_PRIVATE_H_ */
