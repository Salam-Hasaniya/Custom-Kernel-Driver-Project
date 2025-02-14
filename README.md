 # Custom-Kernel-Driver-Project
A custom Linux kernel module that implements a character device driver for a Hangman game. The module handles user interactions through read, write, and ioctl system calls, allowing a user-space application to play the game via the terminal.

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
