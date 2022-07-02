################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c 

S_UPPER_SRCS += \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S 

OBJS += \
./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o \
./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o \
./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o \
./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o 

S_UPPER_DEPS += \
./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d 

C_DEPS += \
./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d \
./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d \
./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d 


# Each subdirectory must supply rules for building sources it contributes
CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.c CommonF7/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S CommonF7/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m7 -g3 -DDEBUG -c -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"
CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.c CommonF7/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.c CommonF7/ThirdParty/SEGGER/SEGGER/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CommonF7-2f-ThirdParty-2f-SEGGER-2f-SEGGER

clean-CommonF7-2f-ThirdParty-2f-SEGGER-2f-SEGGER:
	-$(RM) ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.d ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.o ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT.su ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.d ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.o ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.d ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.o ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_RTT_printf.su ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.d ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.o ./CommonF7/ThirdParty/SEGGER/SEGGER/SEGGER_SYSVIEW.su

.PHONY: clean-CommonF7-2f-ThirdParty-2f-SEGGER-2f-SEGGER

