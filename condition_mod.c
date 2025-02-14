#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/string.h>
#include <linux/random.h>

#define BUF_SIZE 256
#define IOCTL_GET_LIVES _IOR('L', 1, int)
#define IOCTL_RESET_GAME _IO('L', 2)

static char result_buffer[BUF_SIZE];
static int major;
static int lives = 6;

static ssize_t condition_read(struct file *file, char *user_buf, size_t count, loff_t *pos) {
    if (count > BUF_SIZE) count = BUF_SIZE;
    if (copy_to_user(user_buf, result_buffer, count)) return -1;
    memset(result_buffer, 0, BUF_SIZE);
    return count;
}

static ssize_t condition_write(struct file *file, const char *user_buf, size_t count, loff_t *pos) {
    if (count > BUF_SIZE) count = BUF_SIZE;
    if (copy_from_user(result_buffer, user_buf, count)) return -1;
    return count;
}

static long condition_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    switch (cmd) {
        case IOCTL_GET_LIVES:
            if (copy_to_user((int *)arg, &lives, sizeof(int))) return -1;
            break;
        case IOCTL_RESET_GAME:
            lives = 6;
            break;
        default:
            return -1;
    }
    return 0;
}

static struct file_operations fops = {
    .read = condition_read,
    .write = condition_write,
    .unlocked_ioctl = condition_ioctl
};

static int __init condition_init(void) {
    major = register_chrdev(0, "condition_mod", &fops);
    if (major < 0) return major;
    printk(KERN_INFO "ConditionMod: Registered with major number %d\n", major);
    return 0;
}

static void __exit condition_exit(void) {
    unregister_chrdev(major, "condition_mod");
    printk(KERN_INFO "ConditionMod: Unregistered\n");
}

module_init(condition_init);
module_exit(condition_exit);
MODULE_LICENSE("GPL");
