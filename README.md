# STM32F411 Bare-Metal Startup & Linker Script

## Overview
This repository demonstrates a bare-metal STM32F411 project focusing on
ARM Cortex-M startup code and GNU LD linker script implementation.

All build steps are executed manually using the GNU ARM Embedded Toolchain.
STM32CubeIDE is used only as a code editor.

## Target
- MCU: STM32F411RE
- Core: ARM Cortex-M4

## Repository Structure
- `startup/` : Cortex-M startup code (vector table, Reset_Handler)
- `linker/`  : Custom GNU LD linker script defining memory layout
- `src/`     : Application entry point (`main.c`)
- `docs/`    : Build commands and notes

## Build Process
- Compilation: `arm-none-eabi-gcc`
- Linking: `arm-none-eabi-ld`
- Inspection: `arm-none-eabi-objdump`, `.map` file analysis

## Key Learning Outcomes
- Understanding Cortex-M boot sequence
- FLASH/RAM memory mapping
- Symbol communication between linker and startup code
- Manual control of the build process
