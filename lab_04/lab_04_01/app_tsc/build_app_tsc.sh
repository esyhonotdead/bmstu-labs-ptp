#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wfloat-equal -Wfloat-conversion -Wextra -c -O0 main.c ./*.c
gcc -o app_tsc.exe ./*.o -lm -lrt
