################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Peripheral/Src/GY30.c \
../Drivers/Peripheral/Src/HC-05.c \
../Drivers/Peripheral/Src/LCD1602.c \
../Drivers/Peripheral/Src/SHT31.c 

OBJS += \
./Drivers/Peripheral/Src/GY30.o \
./Drivers/Peripheral/Src/HC-05.o \
./Drivers/Peripheral/Src/LCD1602.o \
./Drivers/Peripheral/Src/SHT31.o 

C_DEPS += \
./Drivers/Peripheral/Src/GY30.d \
./Drivers/Peripheral/Src/HC-05.d \
./Drivers/Peripheral/Src/LCD1602.d \
./Drivers/Peripheral/Src/SHT31.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Peripheral/Src/GY30.o: ../Drivers/Peripheral/Src/GY30.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/MyCode/GreenhouseSensorSystem/Drivers/Peripheral/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral/Src/GY30.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral/Src/HC-05.o: ../Drivers/Peripheral/Src/HC-05.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/MyCode/GreenhouseSensorSystem/Drivers/Peripheral/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral/Src/HC-05.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral/Src/LCD1602.o: ../Drivers/Peripheral/Src/LCD1602.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/MyCode/GreenhouseSensorSystem/Drivers/Peripheral/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral/Src/LCD1602.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Drivers/Peripheral/Src/SHT31.o: ../Drivers/Peripheral/Src/SHT31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/MyCode/GreenhouseSensorSystem/Drivers/Peripheral/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/Peripheral/Src/SHT31.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

