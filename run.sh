#!/bin/bash
make
sudo insmod condition_mod.ko
sudo mknod /dev/condition_mod c 240 0
sudo chmod 777 /dev/condition_mod
gcc condition_app.c -o condition_app
