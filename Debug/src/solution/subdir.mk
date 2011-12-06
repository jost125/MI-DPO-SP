################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/solution/IRefCounter.cpp \
../src/solution/ITarget.cpp \
../src/solution/LocationImpl.cpp \
../src/solution/RefCounter.cpp \
../src/solution/SmartPointer.cpp \
../src/solution/WorldFacadeImpl.cpp 

OBJS += \
./src/solution/IRefCounter.o \
./src/solution/ITarget.o \
./src/solution/LocationImpl.o \
./src/solution/RefCounter.o \
./src/solution/SmartPointer.o \
./src/solution/WorldFacadeImpl.o 

CPP_DEPS += \
./src/solution/IRefCounter.d \
./src/solution/ITarget.d \
./src/solution/LocationImpl.d \
./src/solution/RefCounter.d \
./src/solution/SmartPointer.d \
./src/solution/WorldFacadeImpl.d 


# Each subdirectory must supply rules for building sources it contributes
src/solution/%.o: ../src/solution/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


