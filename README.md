# AlleSys Bare-Metal

This code is a conversion from a CPP code that used arduino. It was an iot sensor with mqtt. 

I highly recommend to run this code on a Linux OS, since handling hex and binaries are too annoying due to mac
permissions also it has some crashes due to the ARM, since xtensa is not fully supported
on ARM.

## Requirements 

_CMake_ (any version)

_x86 Computer with Linux_

_Python 3_

_pip 3_

or use 

_sudo apt install esptool_

``wget https://dl.espressif.com/dl/xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz``

`mkdir -p ~/esp
tar -xzf xtensa-lx106-elf-gcc8_4_0-esp-2020r3-linux-amd64.tar.gz -C ~/esp
`
`export PATH=$PATH:$HOME/esp/xtensa-lx106-elf/bin
`
`source ~/.bashrc
`

## Compiling

Inside build folder

`cmake ..`

`make`

Make sure to have the bin file, otherwise run 

`xtensa-lx106-elf-objcopy -O binary esp8266_bare_metal esp8266_bare_metal.bin
`