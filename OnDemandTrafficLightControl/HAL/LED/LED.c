/*
 * TrafficLights.c
 *
 *  Created on: Oct 17, 2022
 *      Author: Amr Mohamed
 */


#include"LED.h"



error_state LED_init( uint8 port, uint8 pin)
{
	return DIO_init(port, pin, OUT);
}

error_state LED_on( uint8 port, uint8 pin)
{
	return DIO_write(port, pin, HIGH);
}

error_state LED_off( uint8 port, uint8 pin)
{
	return DIO_write(port, pin, LOW);
}


error_state LED_toggle( uint8 port, uint8 pin)
{
	return DIO_toggle(port, pin);
}
