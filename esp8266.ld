ENTRY(main)

/*// 32 KB Instruction RAM*/
MEMORY
{
  IRAM (rx) : ORIGIN = 0x40100000, LENGTH = 0x8000
  DRAM (rw) : ORIGIN = 0x3FFE8000, LENGTH = 0x4000
}
/*  // 16 KB Data RAM*/

SECTIONS
{
  .text : {
    *(.text)
    *(.rodata)
  } > IRAM

  .data : {
    *(.data)
  } > DRAM

  .bss : {
    *(.bss)
  } > DRAM
}


/* Briefing about Linker script*/
/*A linker script is a configuration file used by the linker (such as ld from GNU) to define how the program's */
/*sections should be arranged in memory. */
/*In a bare-metal embedded system, there is no operating system to handle memory management, */
/*so you must specify where your program's code and data should be placed in the microcontroller's memory.*/
/*The ESP8266 has different types of memory (like instruction RAM, data RAM, and flash), */
/*and the linker script tells the compiler how to organize your program to run correctly on the hardware.*/

/*  The .text section contains the executable code*/
/*  Place all .text sections from object files here*/
/*  Place all read-only data sections here*/
/*  Map the .text section to the instruction RAM (IRAM)*/
/*
/* The .data section contains initialized data*/
/* Place all .data sections from object files here*/
/* Map the .data section to the data RAM (DRAM)*/
/*
/* The .bss section contains uninitialized data*/
/* Place all .bss sections from object files here*/
/* Map the .bss section to the data RAM (DRAM)*/

