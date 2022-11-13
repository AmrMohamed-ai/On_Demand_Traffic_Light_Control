/*
 * TrafficLights.h
 *
 *  Created on: Oct 17, 2022
 *      Author: Amr Mohamed
 */

#ifndef HAL_LED_LED_H_
#define HAL_LED_LED_H_

#include"../../MCAL/DIO/DIO.h"




/**************************************************************************************
 *
 *
 *                                  FUNCTIONS
 *
 *
 **************************************************************************************/


error_state LED_init( uint8 port, uint8 pin);

error_state LED_on( uint8 port, uint8 pin);

error_state LED_off( uint8 port, uint8 pin);

error_state LED_toggle( uint8 port, uint8 pin);

#endif /* HAL_LED_LED_H_ */
