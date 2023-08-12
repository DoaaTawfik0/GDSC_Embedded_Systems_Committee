################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTI/EXTI.Program.c \
../MCAL/EXTI/EXTI_Config.c 

OBJS += \
./MCAL/EXTI/EXTI.Program.o \
./MCAL/EXTI/EXTI_Config.o 

C_DEPS += \
./MCAL/EXTI/EXTI.Program.d \
./MCAL/EXTI/EXTI_Config.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTI/%.o: ../MCAL/EXTI/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


