/*
 * ExInterrupt_type.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Amr Mohamed
 */

#ifndef MCAL_INTERRUPTS_EXINTERRUPT_TYPE_H_
#define MCAL_INTERRUPTS_EXINTERRUPT_TYPE_H_


#define ON                                  1u
#define OFF                                 0u


typedef enum
{
	  EXT_INT0
	, EXT_INT1
	, EXT_INT2

}ExInterrupt_VectorType;


typedef enum
{
	  External_Interrupt_0_P=0
	, External_Interrupt_1_P
	, External_Interrupt_2_P

}ExInterrupt_PeripheralType;


typedef enum
{
	  NO_LEVEL=0
	, LOW_LEVEL
	, RISING_EDGE
	, FALLING_EDGE
	, ANY_LOGIC_CHANGE

}ExInterrupt_EdgeType;

typedef struct
{
	ExInterrupt_PeripheralType Type;
	ExInterrupt_EdgeType EdgeType;

}ExInterrupt_Config;

#endif /* MCAL_INTERRUPTS_EXINTERRUPT_TYPE_H_ */
