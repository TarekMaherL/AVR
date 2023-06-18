/*
 * Seven_Segmant.c
 *
 * Created: 6/10/2023 8:02:38 PM
 *  Author: Doudo
 */ 


#include "Seven_Segmant.h"

void Seg7_Init()
{
	M_DIO_Void_SetPinDirection(26,OUTPUT);
	
	M_DIO_Void_SetPinDirection(20,OUTPUT);
	M_DIO_Void_SetPinDirection(21,OUTPUT);
	M_DIO_Void_SetPinDirection(22,OUTPUT);
	M_DIO_Void_SetPinDirection(24,OUTPUT);

}
void Seg7_Enable()
{
	M_DIO_Void_SetPinValue(26,HIGH);
}
void Seg7_Display(u8 number)
{
	M_DIO_Void_SetPinValue(20,GET_BIT(number,0));
	M_DIO_Void_SetPinValue(21,GET_BIT(number,1));
	M_DIO_Void_SetPinValue(22,GET_BIT(number,2));
	M_DIO_Void_SetPinValue(24,GET_BIT(number,3));
}
