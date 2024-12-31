#!/bin/bash

# 烧录脚本：用于将编译生成的固件文件烧录到 STM32 芯片
# 需要安装 st-flash 工具（适用于使用 ST-Link 调试器）

# 检查是否提供了固件文件路径
if [ $# -ne 1 ]; then
    echo "Usage: $0 <path_to_firmware.bin>"
    exit 1
fi

FIRMWARE_PATH=$1

# 检查固件文件是否存在
if [ ! -f "$FIRMWARE_PATH" ]; then
    echo "Error: Firmware file '$FIRMWARE_PATH' not found."
    exit 1
fi

# 烧录固件
echo "Flashing firmware: $FIRMWARE_PATH"
st-flash --reset write "$FIRMWARE_PATH" 0x8000000

# 检查烧录结果
if [ $? -eq 0 ]; then
    echo "Flashing completed successfully."
else
    echo "Error: Flashing failed."
    exit 1
fi
