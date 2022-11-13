/*
 * app.c
 *
 *  Created on: Oct 23, 2022
 *      Author: Amr Mohamed
 */

#include"../HAL/TrafficControl/traffic_control.h"

void app_init()
{
	Traffic_init();
}

void app_start()
{
	while(1)
		{
			Traffic_normalMode();
		}
}
