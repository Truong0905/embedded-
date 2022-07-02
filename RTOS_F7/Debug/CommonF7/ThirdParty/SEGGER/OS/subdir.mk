################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c 

OBJS += \
./CommonF7/ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o 

C_DEPS += \
./CommonF7/ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
CommonF7/ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c CommonF7/ThirdParty/SEGGER/OS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CommonF7-2f-ThirdParty-2f-SEGGER-2f-OS

clean-CommonF7-2f-ThirdParty-2f-SEGGER-2f-OS:
	-$(RM) ./CommonF7/ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.d ./CommonF7/ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.o ./CommonF7/ThirdParty/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.su

.PHONY: clean-CommonF7-2f-ThirdParty-2f-SEGGER-2f-OS

