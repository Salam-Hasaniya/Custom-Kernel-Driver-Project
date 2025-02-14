#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define IOCTL_GET_LIVES _IOR('L', 1, int)
#define IOCTL_RESET_GAME _IO('L', 2)
#define BUF_SIZE 256

int main() {
    char input[BUF_SIZE];
    char output[BUF_SIZE];
    int fd = open("/dev/condition_mod", O_RDWR);
    if (fd == -1) {
        perror("Failed to open device");
        return -1;
    }

    printf("Enter text to write to the driver: ");
    fgets(input, BUF_SIZE, stdin);
    write(fd, input, sizeof(input));

    read(fd, output, BUF_SIZE);
    printf("Driver response: %s\n", output);

    int lives;
    if (ioctl(fd, IOCTL_GET_LIVES, &lives) == 0) {
        printf("Lives from driver: %d\n", lives);
    }

    ioctl(fd, IOCTL_RESET_GAME);
    printf("Game reset via ioctl.\n");

    close(fd);
    return 0;
}
