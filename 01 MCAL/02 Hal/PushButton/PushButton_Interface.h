/* BitMath.h
 *

 *      Author: Tarek Maher
 */

#ifndef HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_
#define HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_

/*--------------------------------------------------------------------------------------------*/
/*   INCLUDES   */
/*--------------------------------------------------------------------------------------------*/
#include "../../00 Lib/STD.h"
#include "../../01 MCAL/DIO/DIO_Interface.h"
#include <util/delay.h>

/*--------------------------------------------------------------------------------------------*/
/*   DEFINES   */
/*--------------------------------------------------------------------------------------------*/
#define PUSH_BUTTON_0                    0
#define PUSH_BUTTON_1                    1
#define PUSH_BUTTON_2                    2
#define PUSH_BUTTON_3                    3
#define PUSH_BUTTON_PRESSED              0
#define PUSH_BUTTON_RELEASED             1

/*--------------------------------------------------------------------------------------------*/
/*   PROTOTYPES   */
/*--------------------------------------------------------------------------------------------*/
void H_PushButton_Void_PushButtonInit(u8);
u8   H_PushButton_U8_PushButtonRead(u8);

#endif /* HAL_PUSHBUTTON_PUSHBUTTON_INTERFACE_H_ */
