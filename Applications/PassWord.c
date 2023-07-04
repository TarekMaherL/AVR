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
	u8 password[]= "159753";
	u8 input[sizeof(password)+1];
	u8 i=0;
	u8 input_counter=0;
	u8 error_counter=0;
	u8 errflg=0;
	H_KeyPad_Void_KeyPadInit();
	H_Lcd_Void_LCDInit();
	H_Buzzer_Void_BuzzerInit();
	
		while (1)
		{
			H_Lcd_Void_LCDClear();
			_delay_ms(1);
			H_Lcd_Void_LCDWriteString("Enter password ");
			
			while (1)
			{
				x=H_KeyPad_U8_KeyPadRead();
				
				if(x!='N' ){
						if(input_counter==sizeof(password)-1)
						{
							x='N';
							break;
						}
						
					H_Lcd_Void_LCDWriteCharacter(x);
					input[input_counter]=x;
					
					input_counter++;
					x='N';
					
				
					
				}
			}
			
			
		
			while (1)//  
			{
				
				for ( i = 0; i < sizeof(password)-1; i++) {
					if (input[i] != password[i]) {
						
						error_counter++;
						H_Lcd_Void_LCDWriteNumber(error_counter);
						errflg=1;	
						break;
					}
					}
					
				if (errflg==0)
				{
					error_counter=0;
				}
					
				
					break;
			}

			while (1)
			{
				if (error_counter==0){
					H_Lcd_Void_LCDClear(void);
					_delay_ms(10);
					H_Lcd_Void_LCDWriteString("welcome");
					
					break;
				}else if(error_counter<3){
					H_Lcd_Void_LCDClear(void);
					_delay_ms(10);
					H_Lcd_Void_LCDWriteString("try again");
					H_Lcd_Void_LCDWriteNumber(error_counter);
					errflg=0;
					break;
				} else if (error_counter==3)
				{
					H_Lcd_Void_LCDClear(void);
					_delay_ms(10);
					H_Lcd_Void_LCDWriteString("ItRuder");
					H_Buzzer_Void_BuzzerOn();
					errflg=0;
					break;
				}
				
				
				
					
			}
			
		
			while(1){
				
				x= H_KeyPad_U8_KeyPadRead();
				
				if(x!='N' && x=='c'){
					
						x='N';
						input_counter=0;
						H_Buzzer_Void_BuzzerOff();
						break;	
										
				}
			}
				
			
		}



		
	
}

