################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/MCP23017_io_Expander/MCP23017.c 

OBJS += \
./Drivers/MCP23017_io_Expander/MCP23017.o 

C_DEPS += \
./Drivers/MCP23017_io_Expander/MCP23017.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/MCP23017_io_Expander/%.o Drivers/MCP23017_io_Expander/%.su Drivers/MCP23017_io_Expander/%.cyclo: ../Drivers/MCP23017_io_Expander/%.c Drivers/MCP23017_io_Expander/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-MCP23017_io_Expander

clean-Drivers-2f-MCP23017_io_Expander:
	-$(RM) ./Drivers/MCP23017_io_Expander/MCP23017.cyclo ./Drivers/MCP23017_io_Expander/MCP23017.d ./Drivers/MCP23017_io_Expander/MCP23017.o ./Drivers/MCP23017_io_Expander/MCP23017.su

.PHONY: clean-Drivers-2f-MCP23017_io_Expander

