################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/naive_impl/LocationNaive.cpp \
../src/naive_impl/WorldFacadeNaiveImpl.cpp 

OBJS += \
./src/naive_impl/LocationNaive.o \
./src/naive_impl/WorldFacadeNaiveImpl.o 

CPP_DEPS += \
./src/naive_impl/LocationNaive.d \
./src/naive_impl/WorldFacadeNaiveImpl.d 


# Each subdirectory must supply rules for building sources it contributes
src/naive_impl/%.o: ../src/naive_impl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


