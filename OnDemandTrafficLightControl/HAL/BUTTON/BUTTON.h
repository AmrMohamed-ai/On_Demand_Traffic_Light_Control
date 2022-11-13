/*
 * BUTTON.h
 *
 *  Created on: Oct 20, 2022
 *      Author: Amr Mohamed
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

#include"../../MCAL/DIO/DIO.h"



error_state BUTTON_init(uint8 port, uint8 pin);

error_state BUTTON_read(uint8 port, uint8 pin, uint8* value);

#endif /* HAL_BUTTON_BUTTON_H_ */
