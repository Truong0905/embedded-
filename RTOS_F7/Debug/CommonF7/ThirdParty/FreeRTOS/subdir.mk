################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/croutine.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/event_groups.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/list.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/queue.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/stream_buffer.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/tasks.c \
C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/timers.c 

OBJS += \
./CommonF7/ThirdParty/FreeRTOS/croutine.o \
./CommonF7/ThirdParty/FreeRTOS/event_groups.o \
./CommonF7/ThirdParty/FreeRTOS/list.o \
./CommonF7/ThirdParty/FreeRTOS/queue.o \
./CommonF7/ThirdParty/FreeRTOS/stream_buffer.o \
./CommonF7/ThirdParty/FreeRTOS/tasks.o \
./CommonF7/ThirdParty/FreeRTOS/timers.o 

C_DEPS += \
./CommonF7/ThirdParty/FreeRTOS/croutine.d \
./CommonF7/ThirdParty/FreeRTOS/event_groups.d \
./CommonF7/ThirdParty/FreeRTOS/list.d \
./CommonF7/ThirdParty/FreeRTOS/queue.d \
./CommonF7/ThirdParty/FreeRTOS/stream_buffer.d \
./CommonF7/ThirdParty/FreeRTOS/tasks.d \
./CommonF7/ThirdParty/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
CommonF7/ThirdParty/FreeRTOS/croutine.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/croutine.c CommonF7/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/ThirdParty/FreeRTOS/event_groups.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/event_groups.c CommonF7/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/ThirdParty/FreeRTOS/list.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/list.c CommonF7/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/ThirdParty/FreeRTOS/queue.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/queue.c CommonF7/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/ThirdParty/FreeRTOS/stream_buffer.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/stream_buffer.c CommonF7/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/ThirdParty/FreeRTOS/tasks.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/tasks.c CommonF7/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
CommonF7/ThirdParty/FreeRTOS/timers.o: C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/timers.c CommonF7/ThirdParty/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/SEGGER" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/Config" -I"C:/Code/WorkSpace/RTOS_TEST/CommonF7/ThirdParty/SEGGER/OS" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-CommonF7-2f-ThirdParty-2f-FreeRTOS

clean-CommonF7-2f-ThirdParty-2f-FreeRTOS:
	-$(RM) ./CommonF7/ThirdParty/FreeRTOS/croutine.d ./CommonF7/ThirdParty/FreeRTOS/croutine.o ./CommonF7/ThirdParty/FreeRTOS/croutine.su ./CommonF7/ThirdParty/FreeRTOS/event_groups.d ./CommonF7/ThirdParty/FreeRTOS/event_groups.o ./CommonF7/ThirdParty/FreeRTOS/event_groups.su ./CommonF7/ThirdParty/FreeRTOS/list.d ./CommonF7/ThirdParty/FreeRTOS/list.o ./CommonF7/ThirdParty/FreeRTOS/list.su ./CommonF7/ThirdParty/FreeRTOS/queue.d ./CommonF7/ThirdParty/FreeRTOS/queue.o ./CommonF7/ThirdParty/FreeRTOS/queue.su ./CommonF7/ThirdParty/FreeRTOS/stream_buffer.d ./CommonF7/ThirdParty/FreeRTOS/stream_buffer.o ./CommonF7/ThirdParty/FreeRTOS/stream_buffer.su ./CommonF7/ThirdParty/FreeRTOS/tasks.d ./CommonF7/ThirdParty/FreeRTOS/tasks.o ./CommonF7/ThirdParty/FreeRTOS/tasks.su ./CommonF7/ThirdParty/FreeRTOS/timers.d ./CommonF7/ThirdParty/FreeRTOS/timers.o ./CommonF7/ThirdParty/FreeRTOS/timers.su

.PHONY: clean-CommonF7-2f-ThirdParty-2f-FreeRTOS

