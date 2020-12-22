# GreenhouseSensorSystem

# 许可条款
    Copyright (C) 2020  hunterteaegg

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

# 简介
```
    本温室传感系统包括数据采集模块与无线蓝牙传输模块，主控MCU为STM32F103C8T6。
    主要文件及文件夹为： 
   - ./Drivers/Peripheral 
   - ./Core/Src/main.c
```
## 开发环境
```
   - 系统：windows 10
   - 集成开发环境：STM32CubeIDE 
   - 下载工具：STM32CubeProgrammer + CH340（USB to TTL）
```
## 子模块
### 传感模块
```
- SHT31

    SHT31为I2C总线协议温湿度传感模块，支持“单次转换”和“周期转换”模式，本次设计中使用单次转换模式。
- GY30

    GY30为I2C总线协议光照传感模块，支持“单次转换”和“周期转换”模式，本次设计中使用周期转换模式。
```
### 传输模块
    HC-05为无线蓝牙传输模块，支持串口收发。预先于PC上使用AT指令配置蓝牙热点，接上单片机即可直接收发数据。

## 引脚分配
```
- STM32 ===     外设/引脚
- PA2   ===     HC-05/RXD
- PA3   ===     HC-05/TXD
- PA5   ===     LCD1602/WR
- PA6   ===     LCD1602/RD
- PA7   ===     LCD1602/E
- PA15  ===     LCD1602/D0
- PB3   ===     LCD1602/D1
- PB4   ===     LCD1602/D2
- PB5   ===     LCD1602/D3
- PB6   ===     LCD1602/D4
- PB7   ===     LCD1602/D5
- PB8   ===     LCD1602/D6
- PB9   ===     LCD1602/D7
- PB10  ===     I2C-SCL（总线）
- PB11  ===     I2C-SDA（总线）
```
