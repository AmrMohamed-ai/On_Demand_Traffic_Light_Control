/*
 * BUTTON.c
 *
 *  Created on: Oct 20, 2022
 *      Author: Amr Mohamed
 */


#include"BUTTON.h"

error_state BUTTON_init(uint8 port, uint8 pin)
{
	return DIO_init( port, pin, IN );
}

error_state BUTTON_read(uint8 port, uint8 pin, uint8* value)
{
	return DIO_read(port, pin, value);
}
