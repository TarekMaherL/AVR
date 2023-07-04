/*
 *
 *
 * 
 * Author : Tarek Maher
 */ 

#include <avr/io.h>

#include "01 MCAL/DIO/DIO_Interface.h"
#include "01 MCAL/EXINT/GEXTINT_interface.h"
#include "01 MCAL/GIE/GIE_Interface.h"
#include "02 HAL/LED/LED_Interface.h"
#include "02 HAL/SSD/SSD_Interface.h"
#include "02 HAL/LCD/LCD_Interface.h"
#include "02 HAL/KEYPAD/Keypad_Interface.h"
#include "02 HAL/BUZZER/Buzzer_Interface.h"
#include "02 HAL/BUTTON/PushButton_Interface.h"

int main(void)
{
	u8 x= 'N';
	u8 input_counter=0;
	u8 oper='N';
	u32 first=0,sec=0 , res =0;
	H_KeyPad_Void_KeyPadInit();
	H_Lcd_Void_LCDInit();
	H_Buzzer_Void_BuzzerInit(LED_YEL_PIN);

	
	while (1)
	{
		
		x=H_KeyPad_U8_KeyPadRead();
		if (x=='c')
		{ H_Lcd_Void_LCDClear();
			input_counter=0;
		}
		
		if(x!='N' && x!='c'  ){
			if (input_counter==0)
			{
				x=x-'0';
				H_Lcd_Void_LCDWriteCommand(x);
				first=x;
				
				}else if (input_counter==1){
				oper=x;
				H_Lcd_Void_LCDWriteCharacter(x);
				}else if (input_counter==2){
				x=x-'0';
				H_Lcd_Void_LCDWriteNumber(x);
				sec=x;
			}else if (input_counter==3)
			{
				H_Lcd_Void_LCDWriteCharacter(x);
				
			}
			x='N';
			input_counter++;
		}
		if (input_counter==4)
		{
			switch (oper)
			{
				case '+': H_Lcd_Void_LCDWriteNumber (first+sec);
						input_counter=0; break;
				case '-': H_Lcd_Void_LCDWriteNumber (first-sec );
				 		input_counter=0; break;
				case '*':
						res = first * sec;
				H_Lcd_Void_LCDWriteNumber (res );
						input_counter=0; break;
				case '/': H_Lcd_Void_LCDWriteNumber (first/sec );
					 	input_counter=0;break;
				
			}
			
		}
		
		
		
		
	}				
	
}

