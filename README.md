 # Custom-Kernel-Driver-Project
A custom Linux kernel module with basic read, write, and ioctl operations for handling controlled commands in user-space applications.

# **Custom Kernel Driver - Seminar 4**

## **Overview**
This project implements a **custom Linux kernel driver** with basic operations such as **read, write**, and an additional operation using **ioctl**. The driver is designed to handle controlled commands from a **user-space application**, allowing interaction with the kernel beyond standard read/write calls.

## **How It Works**
1. **The kernel module (`condition_mod.c`)** registers as a character device.
2. **User-space application (`condition_app.c`)** communicates with the driver via:
   - **Read & Write** operations for basic data transfer.
   - **Ioctl** calls for special control commands.
3. The driver interacts with a **buffer**, processes commands, and maintains state.
