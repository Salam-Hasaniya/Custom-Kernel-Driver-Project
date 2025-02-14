 # Custom-Kernel-Driver-Project
This project implements a **custom Linux kernel driver** with basic operations such as **read, write**, and an additional operation using **ioctl**. The driver is designed to handle controlled commands from a **user-space application**, allowing interaction with the kernel beyond standard read/write calls.

## **How It Works**
1. **The kernel module (`condition_mod.c`)** registers as a character device.
2. **User-space application (`condition_app.c`)** communicates with the driver via:
   - **Read & Write** operations for basic data transfer.
   - **Ioctl** calls for special control commands.
3. The driver interacts with a **buffer**, processes commands, and maintains state.

## **Code Structure**

| File              | Description                                  |
|------------------|----------------------------------------------|
| `condition_mod.c` | The main kernel module (driver)             |
| `condition_app.c` | The user-space application                  |
| `Makefile`       | Automates compilation of the module          |
| `run.sh`        | Loads the module and sets up the device file  |
| `cleanup.sh`    | Unloads the module and removes the device file |
| `README.md`     | Documentation                                 |

---

## **IOCTL Commands**

| IOCTL Command      | Purpose                                     |
|-------------------|---------------------------------------------|
| `IOCTL_GET_LIVES` | Retrieves the number of lives (example operation) |
| `IOCTL_RESET_GAME` | Resets the game state (example operation)   |
