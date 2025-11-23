# DuyControl

    A modular communication framework between Linux, Raspberry Pi, and STM32
    Featuring multi-threaded architecture, layered design, and interactive CLI UI.

## Overview

    DuyControl is a multi-layer, multi-thread communication system that enables:

        Linux-based Controller (WSL / Ubuntu / Raspberry Pi OS) to communicate with STM32 Microcontroller through UART / I2C / SPI interfaces.

    The project includes:

        A scalable TUI / Text-based UI

        A UI State Machine for multi-level menus

        Threaded execution (UI, RX, TX, Logic)

        Service & Driver layers for expansion

        Support for virtual UART (PTY / socat) for testing without hardware
## How to build and run source code
    Step 1:
        Download packages:
            WSL2    :    Ubuntu-22.04 (On the Internet)
            GCC     :   $ sudo apt install gcc
            Cmake   :   $ sudo apt install cmake
    Step 2: 
        Run these following commands for the first time build
            $ git clone https://github.com/duynk8123/DuyControl
            $ mkdir build
            $ cd build
            $ cmake ..
            $ make 
            $ ./dcontrol
        If you have already built, following this command:    
            $ ./dcontrol
## Project Goal

    The goal of DuyControl is to provide a clean, extensible, hardware-agnostic base for building:

        Sensor monitoring tools

        Raspberry Pi / STM32 debugging tools

        Industrial-style control applications

    All without requiring GUI frameworks — everything is accessible via terminal UI.

## Architecture

    DuyControl uses a structured architecture for maintainability and scalability:

                +============================+
                |       Application          |
                | (UI Thread, State Machine) |
                +============================+
                |         Service            |
                | (I2C, SPI, UART logic)     |
                +============================+
                |         Driver             |
                | (POSIX UART, Linux GPIO…)  |
                +============================+
                |         Hardware           |
                | (Raspberry Pi, STM32)      |
                +============================+

    Easy to test
    Hardware abstraction ready
    Modules easy to extend
## Thread Model

    The Linux-side application runs 4 main threads:

        Thread	            Purpose
        UI Thread	        Interactive menu, state machine, display
        RX Thread	        Read and parse data frames from STM32
        TX Thread	        Handle command queue and send frames
        Logic Thread	       Background logic, heartbeat, auto rules

## UI System – Multi Level State Machine

The UI is designed as a hierarchical state machine:

                MAIN MENU
                    ↓
            SELECT RASPBERRY MODEL
                    ↓
            RASPBERRY TOOL MENU
                    ↓
            I2C / SPI / UART Tools


## Example flow:

    1. Raspberry Pi Options
        → Select RPi Model
            → Tools (I2C/SPI/UART)
                → I2C Scan / Read / Write


    No multi-thread UI — everything is controlled by one UI thread.

## Communication

    Currently supported:

        UART (binary frame format)

        Virtual UART via:

            /dev/pts/X

            socat paired PTYs

            Linux PTY (openpty())

        Planned:

            I2C tools

            SPI tools

            GPIO tools

            Command framing + CRC

## Project Structure
    DuyControl/
    │
    ├── core/               # SystemContext, state, queue
    │
    ├── ui/                 # UI thread + menus + state-machine
    │   ├── ui.c
    │   ├── ui_state.h
    │   ├── ui_main_menu.c
    │   ├── ui_rasp_select.c
    │   ├── ui_rasp_tools.c
    │   ├── ui_i2c_menu.c
    │
    ├── service/            # High-level services (I2C/SPI/UART logic)
    │
    ├── driver/             # Low-level drivers
    │
    ├── comm/               # RX/TX threads (UART)
    │
    ├── logic/              # Logic thread (rules, heartbeat)
    │
    ├── main.c              # Entry point
    └── Makefile

## Build & Run
    Build:
        $ make

    Run:
        $ ./dcontrol

    Clean:
        $ make clean

## Testing Without Hardware

    You can fully test UART communication without any STM32 or Raspberry Pi.

    Using socat:
        $ socat -d -d pty,raw,echo=0 pty,raw,echo=0


    Example output:

        /dev/pts/5
        /dev/pts/6


    Run DControl:

        $ ./dcontrol /dev/pts/5


    Simulate STM32:

        $ screen /dev/pts/6

## Planned Features

    I2C Bus Scanner

    I2C Read/Write tools

    SPI register tool

    UART protocol analyzer

    Logging system

    Config loader (JSON/TOML)

    Device discovery

    Remote SSH UI

## Why DuyControl?

    Clean architecture

    Hardware abstraction

    Educational value

    Real-world applicability

    Easy to expand into full industrial control tools

    Suitable for Raspberry Pi, STM32, ESP32, Linux

    Fully testable without physical devices

# Author
    Nguyen Khanh Duy
    Enthusiast in Embedded Linux, STM32, Raspberry Pi, and System Design.