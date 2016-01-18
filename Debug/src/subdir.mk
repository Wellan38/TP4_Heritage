################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Forme.cpp \
../src/FormeSimple.cpp \
../src/Point.cpp \
../src/Segment.cpp \
../src/TP4_C++.cpp 

OBJS += \
./src/Forme.o \
./src/FormeSimple.o \
./src/Point.o \
./src/Segment.o \
./src/TP4_C++.o 

CPP_DEPS += \
./src/Forme.d \
./src/FormeSimple.d \
./src/Point.d \
./src/Segment.d \
./src/TP4_C++.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


