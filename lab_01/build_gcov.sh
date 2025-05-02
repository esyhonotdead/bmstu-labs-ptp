#!/bin/bash

gcc -std=c99 -coverage -Wall -Werror -Wpedantic -Wfloat-equal -Wfloat-conversion -Wextra -c -O0 -g3 main.c
gcc --coverage -o app.exe main.o -lm