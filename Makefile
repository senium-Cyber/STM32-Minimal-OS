# 项目名称
TARGET = stm32_min_os

# 编译器
CC = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE = arm-none-eabi-size

# 芯片相关参数
MCU = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16

# 编译选项
CFLAGS = $(MCU) -Wall -O2 -ffunction-sections -fdata-sections
LDFLAGS = $(MCU) -Wl,--gc-sections -Wl,-Tstm32f4xx_flash.ld

# 头文件路径
INCLUDES = -IInc -IDrivers

# 源文件
SRCS = \
    Src/main.c \
    Src/stm32f4xx_it.c \
    Src/system_stm32f4xx.c \
    Src/task_scheduler.c

# 目标文件
OBJS = $(SRCS:.c=.o)

# 输出文件
BUILD_DIR = build
ELF = $(BUILD_DIR)/$(TARGET).elf
BIN = $(BUILD_DIR)/$(TARGET).bin

# 规则
all: $(BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(ELF): $(BUILD_DIR) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $@ $(LDFLAGS)
	$(SIZE) $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BIN): $(ELF)
	$(OBJCOPY) -O binary $< $@

clean:
	rm -rf $(BUILD_DIR) *.o

flash: $(BIN)
	st-flash write $(BIN) 0x8000000
