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
	u8 number=0;
	
	u8 flag=0;

	u8 Character1[8] = {
		0b00100,
		0b01010,
		0b01010,
		0b10101,
		0b01110,
		0b00100,
		0b01010,
		0b10001
	};
	u8 Character2[8] = {
		0b00000,
		0b00000,
		0b01000,
		0b10100,
		0b10100,
		0b01000,
		0b01010,
		0b01101
	};
	
	H_Lcd_Void_LCDInit();
	
	H_Lcd_Void_LCDWriteCharacter( Character1,0);
	H_Lcd_Void_LCDWriteCharacter( Character2,1);
	M_DIO_Void_SetPinDirection(PA0_PIN,INPUT);
 
	M_ADC_Void_ADCInit();
	
	while(1)
	{
		number = M_ADC_Void_ADCRead(ADC_CHANNEL_0);
		if(number > 100 &&flag==0){
			H_Lcd_Void_LCDWriteCommand(cursor_firstline);
			H_Lcd_Void_LCDWriteCharacter(1);
			flag=1;
			
		}
		if (number<100 &&flag==1)
		{
			H_Lcd_Void_LCDWriteCommand(cursor_firstline);
			H_Lcd_Void_LCDWriteCharacter(0);
			flag=0;
			
		}
	}
	return 0;	
}
