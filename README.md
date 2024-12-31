# STM32 Minimal OS

## 项目简介
这是一个基于 STM32F401CC 的最小嵌入式操作系统，实现了简单的任务调度器和外设驱动支持。

## 特性
- 任务调度器：支持简单循环调度。
- 外设支持：I2C（MPU6050）、GPIO（LED 控制）。
- 低功耗管理：支持进入 SLEEP 模式。

## 项目目录
```bash
STM32-Minimal-OS/
├── docs/                   # 文档文件夹：包含项目说明文档、数据表、原理图等
│   ├── README.md           # 项目文档的详细说明
│   ├── schematic.png       # 原理图文件
│   └── datasheets/         # 芯片及模块相关数据手册
├── src/                    # 源代码文件夹：存放所有代码
│   ├── main.c              # 主函数
│   ├── task_scheduler.c    # 任务调度器实现
│   ├── peripherals.c       # 外设初始化代码
│   ├── task_scheduler.h    # 任务调度器头文件
│   └── peripherals.h       # 外设头文件
├── inc/                    # 头文件文件夹：存放公共头文件
│   ├── stm32f4xx_hal_conf.h
│   ├── stm32f4xx_it.h
│   └── system_stm32f4xx.h
├── build/                  # 构建输出文件夹（可以在 .gitignore 中忽略）
│   └── ...                 # 编译生成的 .elf、.bin 等文件
├── scripts/                # 工具脚本：用于构建、下载或调试的脚本
│   ├── flash.sh            # 烧录脚本
│   └── debug.sh            # 调试脚本
├── .gitignore              # 忽略文件规则
├── LICENSE                 # 项目许可协议
├── README.md               # 项目说明文件
└── Makefile / CMakeLists.txt # 构建系统配置文件
```
## 快速开始
1. 克隆本仓库：
   ```bash
   git clone https://github.com/yourusername/STM32-Minimal-OS.git
   ```
2.构建项目：
   ```bash
   make
   ```
3.烧录程序：
   ```bash
   ./scripts/flash.sh
   ```
  
