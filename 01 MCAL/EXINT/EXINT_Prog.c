/* BitMath.h
 *

 *      Author: Tarek Maher
 */

#include"../../00 Lib/STD.h"
#include"../../00 Lib/BitMath.h"

#include"EXINT_Config.h"
#include"EXINT_Interface.h"
#include"EXINT_Private.h"

#define 		NULL			((void *)0)

static void	(*x)(void) = NULL;

void EXTI_voidInit0()
{
	
	#if		EXTI_SENSE_MODE == FALLING_EDGE
	SET_BIT(MCUCR , ISC01);
	CLR_BIT(MCUCR , ISC00);
	#elif	EXTI_SENSE_MODE == RISING_EDGE
	SET_BIT(MCUCR , ISC00);
	SET_BIT(MCUCR , ISC01);
	#elif	EXTI_SENSE_MODE == LOGICAL_CHANGE
	SET_BIT(MCUCR , ISC00);
	CLR_BIT(MCUCR , ISC01);
	#else
	#error ("Wrong Externl Interrupt Sense Mode !")
	#endif
}

void EXTI_voidSetSignalLatch0(u8 EXTISenseMode)
{
	switch(EXTISenseMode)
	{
		case	RISING_EDGE		:
			SET_BIT(MCUCR , ISC00);
			SET_BIT(MCUCR , ISC01);
				break;
		case	FALLING_EDGE	:
			CLR_BIT(MCUCR , ISC00);
			SET_BIT(MCUCR , ISC01);
				break;
		case	LOGICAL_CHANGE	:
			SET_BIT(MCUCR , ISC01);
			CLR_BIT(MCUCR , ISC00);
			break;
	}
}

void EXTI_voidEnableEXTI0()
{
	SET_BIT(GICR, 6);
}


void EXTI_voidDisableEXTI0()
{
	CLR_BIT(GICR, 6);
}





void EXTI_voidSetSignalLatch1(u8 EXTISenseMode)
{
	switch(EXTISenseMode)
	{
		case	RISING_EDGE		:
		SET_BIT(MCUCR , ISC10);
		SET_BIT(MCUCR , ISC11);
		break;
		case	FALLING_EDGE	:
		CLR_BIT(MCUCR , ISC10);
		SET_BIT(MCUCR , ISC11);
		break;
		case	LOGICAL_CHANGE	:
		SET_BIT(MCUCR , ISC11);
		CLR_BIT(MCUCR , ISC10);
		break;
	}
}

void EXTI_voidEnableEXTI1()
{
	SET_BIT(GICR, 7);
}


void EXTI_voidDisableEXTI1()
{
	CLR_BIT(GICR, 7);
}

void EXTI_voidEnableEXTI2()
{
	SET_BIT(GICR, 5);
}


void EXTI_voidDisableEXTI2()
{
	CLR_BIT(GICR, 5);
}


void EXTI_voidSetSignalLatch2(u8 EXTISenseMode)
{
	switch(EXTISenseMode)
	{
		case RISING_EDGE:
			SET_BIT(MCUCSR , 6);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCSR , 6);
			break;
	}
	
}

void EXTI_voidInit1()
{
	
	#if		EXTI_SENSE_MODE == FALLING_EDGE
	SET_BIT(MCUCR , ISC11);
	CLR_BIT(MCUCR , ISC10);
	#elif	EXTI_SENSE_MODE == RISING_EDGE
	SET_BIT(MCUCR , ISC10);
	SET_BIT(MCUCR , ISC11);
	#elif	EXTI_SENSE_MODE == LOGICAL_CHANGE
	SET_BIT(MCUCR , ISC10);
	CLR_BIT(MCUCR , ISC11);
	#else
	#error ("Wrong Externl Interrupt Sense Mode !")
	#endif
}

void EXTI_voidInit2()
{
	
	#if		EXTI_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCSR , 6);
	#elif	EXTI_SENSE_MODE == RISING_EDGE
	SET_BIT(MCUCSR , 6);
	#else
	#error ("Wrong Externl Interrupt Sense Mode !")
	#endif
}


void EXTI_voidSetCallBack(void (*ptr) (void)) 
{
	if(ptr != NULL)
	{
		x = ptr;
	}
	  
}

void __vector_1(void)  
{
	x();
}