################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/AT24C256C_eeprom/AT24C256C_eeprom.c 

OBJS += \
./Drivers/AT24C256C_eeprom/AT24C256C_eeprom.o 

C_DEPS += \
./Drivers/AT24C256C_eeprom/AT24C256C_eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/AT24C256C_eeprom/%.o Drivers/AT24C256C_eeprom/%.su Drivers/AT24C256C_eeprom/%.cyclo: ../Drivers/AT24C256C_eeprom/%.c Drivers/AT24C256C_eeprom/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/Projects/Library/AT24C256C_eeprom/Drivers/AT24C256C_eeprom" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-AT24C256C_eeprom

clean-Drivers-2f-AT24C256C_eeprom:
	-$(RM) ./Drivers/AT24C256C_eeprom/AT24C256C_eeprom.cyclo ./Drivers/AT24C256C_eeprom/AT24C256C_eeprom.d ./Drivers/AT24C256C_eeprom/AT24C256C_eeprom.o ./Drivers/AT24C256C_eeprom/AT24C256C_eeprom.su

.PHONY: clean-Drivers-2f-AT24C256C_eeprom

