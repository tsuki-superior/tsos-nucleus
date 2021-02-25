#!/bin/make -f
# By Tsuki Superior
.RECIPEPREFIX=:

BUILD_DIR:=../build
SRC_DIR:=../src
ASM_DIR:=../asm
INCLUDE_DIR:=../include
CONFIG_DIR:=../config
LINKER_SCRIPTS_DIR:=../linker-scripts

CC:=tsos-armeabi-gcc
CC_FLAGS:=-g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c99 -ffreestanding -O0 -Wall -Wextra -pedantic -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -c

CPP:=tsos-armeabi-g++
CPP_FLAGS:=-g -I $(INCLUDE_DIR) -I $(CONFIG_DIR) -I ./ -std=c++20 -ffreestanding -O0 -Wall -Wextra -Wno-write-strings -Wno-return-type -Wno-int-to-pointer-cast -Wno-unused-parameter -fno-exceptions -fno-rtti -nostdlib -lgcc -pedantic -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -c

AS:=tsos-armeabi-as
AS_FLAGS:=-g -mcpu=arm7tdmi -mthumb-interwork

LD:=tsos-armeabi-ld.gold
LD_FLAGS:=-g -T $(LINKER_SCRIPTS_DIR)/gba-elf.ld -mcpu=arm7tdmi -nostartfiles -mthumb-interwork -ffreestanding -O2 -nostdlib -lgcc

CPP_FILES:=$(wildcard $(SRC_DIR)/generic/*.cpp)
CPP_FILES+=$(wildcard $(SRC_DIR)/gba/*.cpp)
OBJ_FILES:=$(patsubst %.cpp, $(BUILD_DIR)/%.o, $(CPP_FILES))

default: $(BUILD_DIR)/nucleus.tse

$(BUILD_DIR)/nucleus.tse: $(OBJ_FILES) $(ASM_DIR)/gba/gba_boot.o 
:$(CPP) $(LD_FLAGS) -o $@ $^ 

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
:$(CPP) $(CPP_FLAGS) -o $@ $^ 

$(ASM_DIR)/gba/gba_boot.o: $(ASM_DIR)/gba/gba_boot.asm 
:$(AS) $(AS_FLAGS) -o $@ -c $^

clean:
:rm -rfv $(shell find ../ -name \*.o)
