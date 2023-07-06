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

void read (void);
u8 y =0;
u32 num ;
u32 cel;


int main(void)
{
	u16 num =0;
	u16 volt=0;

	H_LED_Void_LedInit(LED_YEL_PIN);
	M_DIO_Void_SetPinDirection(PA0_PIN,INPUT);
	H_Lcd_Void_LCDInit();
	Intrupt_GlobalEnable();
	M_ADC_Void_ADCInit();

	while (1)
	{
		M_ADC_Void_ADCRead();
		H_Lcd_Void_LCDClear();
		_delay_ms(1);
		H_Lcd_Void_LCDGoTo(1,0);
		H_Lcd_Void_LCDWriteString("voltmetermode");
		H_Lcd_Void_LCDGoTo(2,0);
		volt = num/204.8*18;
		volt=((4400)/(89))*volt;
		H_Lcd_Void_LCDWriteNumber(volt);
		H_Lcd_Void_LCDWriteString("mvolt");
		H_LED_Void_LedTog(PB7_PIN);
		_delay_ms(500);
	}
	
}


