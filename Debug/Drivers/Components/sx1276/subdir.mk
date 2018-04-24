################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Components/sx1276/sx1276.c 

OBJS += \
./Drivers/Components/sx1276/sx1276.o 

C_DEPS += \
./Drivers/Components/sx1276/sx1276.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Components/sx1276/%.o: ../Drivers/Components/sx1276/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F302x8 -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Inc" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Drivers/STM32F3xx_HAL_Driver/Inc" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Drivers/STM32F3xx_HAL_Driver/Inc/Legacy" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Drivers/CMSIS/Device/ST/STM32F3xx/Include" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Drivers/CMSIS/Include" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Drivers/Components/sx1276" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Drivers/Components/sx1276mb1las" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Drivers/HW/Inc" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Drivers/HW/Src" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Lora/Phy" -I"C:/STM/workspace/RTK_SOFTWAREv1/MAINBOARD_ROVER/MAINBOARD_ROVER/Lora/Utilities"  -Og -g3 -Wall -fmessage-length=0 -mfpu=fpv4-sp-d16 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


