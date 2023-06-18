/* BitMath.h
 *

 *      Author: Tarek Maher
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "../../00 Lib/BitMath.h"
#include "../../00 Lib/STD.h"
#include "../EXINT/EXINT_Interface.h"

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define ADC_CHANNEL_0              0
#define ADC_CHANNEL_1              1
#define ADC_CHANNEL_2              2
#define ADC_CHANNEL_3              3
#define ADC_CHANNEL_4              4
#define ADC_CHANNEL_5              5
#define ADC_CHANNEL_6              6
#define ADC_CHANNEL_7              7

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void M_ADC_Void_ADCInit(void);
u16  M_ADC_Void_ADCRead(u8);
void M_ADC_Void_ADCEXTI(void);
void M_ADC_Void_ADCEnableI(void);
#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
