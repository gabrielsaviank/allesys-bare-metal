cmake_minimum_required(VERSION 3.10)
project(esp8266_bare_metal C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_C_COMPILER xtensa-lx106-elf-gcc)
set(CMAKE_CXX_COMPILER xtensa-lx106-elf-g++)

set(CMAKE_C_FLAGS "-Os -Wall -Wextra -ffunction-sections -fdata-sections -nostdlib")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections -T ${CMAKE_SOURCE_DIR}/esp8266.ld -nostartfiles -nostdlib")

add_executable(esp8266_bare_metal main.c)
