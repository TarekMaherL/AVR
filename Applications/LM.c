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
	H_LED_Void_LedInit(LED_YEL_PIN);
	M_DIO_Void_SetPinDirection(PA0_PIN,INPUT);
	H_SSD_Void_SSDInit();
	
	Intrupt_GlobalEnable();
	M_ADC_Void_ADCEXTI(void);
	M_ADC_Void_ADCInit();
	M_ADC_Void_ADCRead(ADC_CHANNEL_0);

	while (1)
	{
		
		
		if(y==1){
			num= M_ADC_Void_ADCRead(ADC_CHANNEL_0);
			cel = (num*4.88);
			cel = (cel/10.00);
			y=0;
		}
		H_SSD_Void_SSDDisplay(cel);
		M_ADC_Void_ADCEnableI();
	}
	
}
void read (void){
	y=1;
	 
}

