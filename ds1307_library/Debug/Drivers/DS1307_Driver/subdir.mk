################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DS1307_Driver/ds1307.c 

OBJS += \
./Drivers/DS1307_Driver/ds1307.o 

C_DEPS += \
./Drivers/DS1307_Driver/ds1307.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/DS1307_Driver/%.o Drivers/DS1307_Driver/%.su Drivers/DS1307_Driver/%.cyclo: ../Drivers/DS1307_Driver/%.c Drivers/DS1307_Driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Projects/Library/ds1307_library/Drivers/DS1307_Driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-DS1307_Driver

clean-Drivers-2f-DS1307_Driver:
	-$(RM) ./Drivers/DS1307_Driver/ds1307.cyclo ./Drivers/DS1307_Driver/ds1307.d ./Drivers/DS1307_Driver/ds1307.o ./Drivers/DS1307_Driver/ds1307.su

.PHONY: clean-Drivers-2f-DS1307_Driver

