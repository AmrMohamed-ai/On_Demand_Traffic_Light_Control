################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/TrafficControl/traffic_control.c 

OBJS += \
./HAL/TrafficControl/traffic_control.o 

C_DEPS += \
./HAL/TrafficControl/traffic_control.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/TrafficControl/%.o: ../HAL/TrafficControl/%.c HAL/TrafficControl/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"C:\WinAVR-20100110\lib\gcc\avr32\4.3.2\include\c++" -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


