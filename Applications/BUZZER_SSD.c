/*
 *
 *
 * 
 * Author : Tarek Maher
 */ 

#include <avr/io.h>

#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXINT/GEXTINT_interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "HAL/LED/LED_Interface.h"
#include "HAL/SSD/SSD_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KEYPAD/Keypad_Interface.h"
#include "HAL/BUZZER/Buzzer_Interface.h"
#include "HAL/BUTTON/PushButton_Interface.h"

int main(void)
{
    H_LED_Void_LedInit(LED_YEL_PIN);
    H_PushButton_Void_PushButtonInit(PUSH_BUTTON_0);
    H_PushButton_Void_PushButtonInit(PUSH_BUTTON_1);
    H_PushButton_Void_PushButtonInit(PUSH_BUTTON_2);
    H_Buzzer_Void_BuzzerInit();
    H_SSD_Void_SSDInit();
	u8 buzz=1,led=1,Inc=1,Dec=1;
	u32 counter=0;
	H_SSD_Void_SSDDisplay(1);
	while (1)
	{
		
		H_PushButton_U8_PushButtonRead(PUSH_BUTTON_0);
		H_PushButton_U8_PushButtonRead(PUSH_BUTTON_1);
		H_PushButton_U8_PushButtonRead(PUSH_BUTTON_2);
		H_PushButton_U8_PushButtonRead(PUSH_BUTTON_3);
		
		if (Inc==0)
		{
			counter++;
			
			_delay_ms(250);
			Inc=1;
		}
		if (Dec==0)
		{
			counter--;
			
			_delay_ms(250);
			Dec=1;
		}
		
		if (led==0)
		{
			H_LED_Void_LedTog(LED_YEL_PIN)
			_delay_ms(200);
			led=1;
		}
		
		if (buzz==0)
		{
			
			H_Buzzer_Void_BuzzerTog();
			_delay_ms(200);
			buzz=1;
		}
		
		H_SSD_Void_SSDDisplay(counter);
		
	}
}

