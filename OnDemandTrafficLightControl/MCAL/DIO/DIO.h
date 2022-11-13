/*
 * DIO.h
 *
 *  Created on: Oct 10, 2022
 *      Author: Amr Mohamed
 */

#ifndef MCAL_DIO_DIO_H_
#define MCAL_DIO_DIO_H_

#include"../../utilities/micro_config.h"
#include"../../utilities/std_types.h"
#include"../../utilities/common_macros.h"
#include"../../utilities/Registers.h"

#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'


#define IN 0
#define OUT 1






error_state DIO_init( uint8 port, uint8 pin , uint8 direction ); // set pin direction

error_state DIO_write( uint8 port, uint8 pin , uint8 value ); // write pin

error_state DIO_read( uint8 port, uint8 pin , uint8 *value ); // read pin

error_state DIO_toggle( uint8 port, uint8 pin );





#endif /* MCAL_DIO_DIO_H_ */
