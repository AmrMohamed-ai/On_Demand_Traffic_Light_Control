/*
 * interrupt.h
 *
 *  Created on: Oct 16, 2022
 *      Author: Amr Mohamed
 */

#ifndef MCAL_INTERRUPTS_EXINTERRUPT_H_
#define MCAL_INTERRUPTS_EXINTERRUPT_H_

#include"ExInterrupt_type.h"
#include"../../utilities/std_types.h"
#include"../../utilities/common_macros.h"
#include"../../utilities/micro_config.h"
#include"../../utilities/Registers.h"


#define NULL ((void*)0)
#define MAX_INT    3



error_state ExInterrupt_init( ExInterrupt_Config* configrations );

error_state ExInterrupt_CallBack( ExInterrupt_VectorType ISR_ID , void(*function_ptr)(void)  );

error_state Interrupt_GlobalEnable (bool enable);

error_state ExInterrupt_DeInit(ExInterrupt_PeripheralType type);

#endif /* MCAL_INTERRUPTS_EXINTERRUPT_H_ */
