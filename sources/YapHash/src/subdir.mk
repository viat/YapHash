################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Array2d_32f.cpp \
../src/Audio.cpp \
../src/Stft.cpp \
../src/Stwt.cpp \
../src/VAD.cpp \
../src/VIATUtilities.cpp \
../src/Wave.cpp \
../src/WaveLash.cpp \
../src/YapHash.cpp \
../src/main.cpp \
../src/melFB.cpp \
../src/parseConfig.cpp 

OBJS += \
./src/Array2d_32f.o \
./src/Audio.o \
./src/Stft.o \
./src/Stwt.o \
./src/VAD.o \
./src/VIATUtilities.o \
./src/Wave.o \
./src/WaveLash.o \
./src/YapHash.o \
./src/main.o \
./src/melFB.o \
./src/parseConfig.o 

CPP_DEPS += \
./src/Array2d_32f.d \
./src/Audio.d \
./src/Stft.d \
./src/Stwt.d \
./src/VAD.d \
./src/VIATUtilities.d \
./src/Wave.d \
./src/WaveLash.d \
./src/YapHash.d \
./src/main.d \
./src/melFB.d \
./src/parseConfig.d 

# Each subdirectory must supply rules for building sources it contributes
src/%.o: src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I../../FW_1.3.1_Lin64 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
