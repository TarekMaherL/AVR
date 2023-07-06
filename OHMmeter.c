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


u16 out=0;
u16 number =0;
u16 volt=0;
u16 ohm=0;


int main()
{	
	H_LED_Void_LedInit(LED_YEL_PIN);
	M_DIO_Void_SetPinDirection(PA0_PIN,INPUT);
	
	H_Lcd_Void_LCDInit();
	
	
	M_GIE_Void_GlobalInterruptEnable();
	M_ADC_Void_ADCInit();
	M_ADC_Void_ADCRead(ADC_CHANNEL_0);
	
	
	while(1)
	{
		M_ADC_Void_ADCRead(ADC_CHANNEL_0);
		number = M_ADC_Void_ADCRead(ADC_CHANNEL_0);
		H_Lcd_Void_LCDClear();
		_delay_ms(1);
		H_Lcd_Void_LCDGoTo(1,0);
		H_Lcd_Void_LCDWriteString("ohm metermode");
		H_Lcd_Void_LCDGoTo(2,0);
		volt = number/204.8*18;
		volt=((4400)/(89))*voltt;
		ohm=1000*((4400/volt)-1);
		ohm=ohm/1000;
		H_Lcd_Void_LCDWriteNumber(ohm);
		H_Lcd_Void_LCDWriteString("kohm");
		H_LED_Void_LedTog(PB7_PIN);
		_delay_ms(500);
	}
	return 0;	
}


void Tog(void)
{
	H_LED_Void_LedTog(PA6_PIN);
}