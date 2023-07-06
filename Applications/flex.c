/*
 * main.c
 *
 * Created: 6/12/2023 10:33:27 AM
 *  Author: Doudo
 */ 
#include <avr/io.h>
#include "00 Lib/BitMath.h"
#include "00 Lib/STD.h"
#include "01 MCAL/DIO/\dio_interface.h"
#include "02 Hal/Keypad/Keypad_Interface.h"
#include "02 Hal/Buzzer/Buzzer_Interface.h"
#include "02 Hal/LCD/LCD_Interface.h"
#include "01 MCAL/EXINT/EXTI_interface.h"
#include "01 MCAL/TIMER/Timer_Interface.h"
#include "02 Hal/LED/LED_Interface.h"
#include "01 MCAL/GIE/GIE_Interface.h"

/*


             NOt WORking 
			 
			 */



int main()
{	
	u16 number =0;
	H_LED_Void_LedInit(PB7_PIN);
	M_DIO_Void_SetPinDirection(PA0_PIN,INPUT);
	H_SSD_Void_SSDInit();
	
	M_GIE_Void_GlobalInterruptEnable();
	M_ADC_Void_ADCInit();
	
	while(1)
	{
		number = M_ADC_Void_ADCRead(ADC_CHANNEL_0)
		H_SSD_Void_SSDDisplay(number);
		H_LED_Void_LedTog(PB7_PIN);
	}
	return 0;	
}
