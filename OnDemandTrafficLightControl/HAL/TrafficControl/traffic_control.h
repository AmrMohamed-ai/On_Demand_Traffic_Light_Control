/*
 * traffic_control.h
 *
 *  Created on: Oct 18, 2022
 *      Author: Amr Mohamed
 */

#ifndef HAL_TRAFFICCONTROL_TRAFFIC_CONTROL_H_
#define HAL_TRAFFICCONTROL_TRAFFIC_CONTROL_H_

#include"../../MCAL/timers/timer0.h"
#include"../../MCAL/interrupts/ExInterrupt.h"
#include"../LED/LED.h"
#include"../BUTTON/BUTTON.h"

#define TIMER_INTIAL_VALUE  0x0C
#define CARSPORT            PORT_A
#define PEDSPORT            PORT_B
#define BUTTONPORT          PORT_D
#define CARSREDPIN              0
#define CARSYELLOWPIN           1
#define CARSGREENPIN            2
#define PEDSREDPIN              0
#define PEDSYELLOWPIN           1
#define PEDSGREENPIN            2
#define SWITCHINGTIME           5
#define USEDEXINTERRUPT			External_Interrupt_0_P

typedef enum
{
	  green=0
	, greentored
	, red
	, redtogreen
}Traffic_State;


error_state Traffic_init();

error_state Traffic_normalMode();

error_state Traffic_timerDelay(uint8 a_time);

error_state CARSRED_on();

error_state CARSGREEN_on();

error_state PEDSRED_on();

error_state PEDSGREEN_on();

error_state CARSRED_off();

error_state CARSGREEN_off();

error_state PEDSRED_off();

error_state PEDSGREEN_off();

error_state YELLOW_blinks();

void TIMER_counter(void);

void Traffic_pedestrianMode();






#endif /* HAL_TRAFFICCONTROL_TRAFFIC_CONTROL_H_ */
