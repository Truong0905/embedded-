################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.c 

OBJS += \
./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o \
./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.o \
./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.o \
./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.o 

C_DEPS += \
./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d \
./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.d \
./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.d \
./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.d 


# Each subdirectory must supply rules for building sources it contributes
CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.c CommonF7/SEGGER/SEGGER/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/OS" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.c CommonF7/SEGGER/SEGGER/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/OS" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.c CommonF7/SEGGER/SEGGER/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/OS" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.c CommonF7/SEGGER/SEGGER/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/OS" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/SEGGER" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CommonF7-2f-SEGGER-2f-SEGGER-2f-Syscalls

clean-CommonF7-2f-SEGGER-2f-SEGGER-2f-Syscalls:
	-$(RM) ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.su ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.d ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.o ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.su ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.d ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.o ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.su ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.d ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.o ./CommonF7/SEGGER/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.su

.PHONY: clean-CommonF7-2f-SEGGER-2f-SEGGER-2f-Syscalls

