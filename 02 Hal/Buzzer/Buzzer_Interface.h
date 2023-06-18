/* BitMath.h
 *

 *      Author: Tarek Maher
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "../../00 Lib/STD.h"
#include "../../01 MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_Buzzer_Void_BuzzerInit(void);
void H_Buzzer_Void_BuzzerOn(void);
void H_Buzzer_Void_BuzzerOff(void);
void H_Buzzer_Void_BuzzerTog(void);
void H_Buzzer_Void_BuzzerOnce(void);
void H_Buzzer_Void_BuzzerTwice(void);

#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
