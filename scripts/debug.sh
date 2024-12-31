#!/bin/bash

# 调试脚本：用于通过 GDB 调试 STM32 芯片
# 需要安装 openocd 和 arm-none-eabi-gdb

# 默认配置文件路径（根据实际项目调整）
OPENOCD_CONFIG="interface/stlink.cfg"
TARGET_CONFIG="target/stm32f4x.cfg"

# 检查 OpenOCD 是否已安装
if ! command -v openocd &> /dev/null; then
    echo "Error: OpenOCD is not installed. Please install it first."
    exit 1
fi

# 检查 arm-none-eabi-gdb 是否已安装
if ! command -v arm-none-eabi-gdb &> /dev/null; then
    echo "Error: arm-none-eabi-gdb is not installed. Please install it first."
    exit 1
fi

# 启动 OpenOCD
echo "Starting OpenOCD..."
openocd -f "$OPENOCD_CONFIG" -f "$TARGET_CONFIG" &
OPENOCD_PID=$!

# 检查 OpenOCD 是否启动成功
sleep 2
if ! ps -p $OPENOCD_PID > /dev/null; then
    echo "Error: Failed to start OpenOCD."
    exit 1
fi

# 启动 GDB 并连接到 OpenOCD
echo "Starting GDB..."
arm-none-eabi-gdb -ex "target remote localhost:3333" -ex "monitor reset halt"

# 停止 OpenOCD
echo "Stopping OpenOCD..."
kill $OPENOCD_PID
