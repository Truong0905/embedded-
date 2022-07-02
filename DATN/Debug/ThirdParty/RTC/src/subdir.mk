################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/RTC/src/rtc.c 

OBJS += \
./ThirdParty/RTC/src/rtc.o 

C_DEPS += \
./ThirdParty/RTC/src/rtc.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/RTC/src/%.o ThirdParty/RTC/src/%.su: ../ThirdParty/RTC/src/%.c ThirdParty/RTC/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F767xx -c -I../Core/Inc -I"C:/Code/WorkSpace/RTOS_TEST/DATN/ThirdParty/RTC/inc" -I"C:/Code/WorkSpace/RTOS_TEST/DATN/ThirdParty/SD_CARD/Inc" -I"C:/Code/WorkSpace/RTOS_TEST/DATN/ThirdParty/FreeRTOS" -I"C:/Code/WorkSpace/RTOS_TEST/DATN/ThirdParty/FreeRTOS/include" -I"C:/Code/WorkSpace/RTOS_TEST/DATN/ThirdParty/FreeRTOS/portable/GCC/ARM_CM7/r0p1" -I../Drivers/STM32F7xx_HAL_Driver/Inc -I../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-RTC-2f-src

clean-ThirdParty-2f-RTC-2f-src:
	-$(RM) ./ThirdParty/RTC/src/rtc.d ./ThirdParty/RTC/src/rtc.o ./ThirdParty/RTC/src/rtc.su

.PHONY: clean-ThirdParty-2f-RTC-2f-src

