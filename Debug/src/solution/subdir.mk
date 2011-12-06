################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/solution/LocationImpl.cpp \
../src/solution/SmartPointer.cpp \
../src/solution/WorldFacadeImpl.cpp 

OBJS += \
./src/solution/LocationImpl.o \
./src/solution/SmartPointer.o \
./src/solution/WorldFacadeImpl.o 

CPP_DEPS += \
./src/solution/LocationImpl.d \
./src/solution/SmartPointer.d \
./src/solution/WorldFacadeImpl.d 


# Each subdirectory must supply rules for building sources it contributes
src/solution/%.o: ../src/solution/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


