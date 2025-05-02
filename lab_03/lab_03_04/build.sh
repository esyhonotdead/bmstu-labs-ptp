#!/bin/bash

gcc -std=c99 -Wall -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla -c -O0 -g3 union.c
gcc -o app.exe union.o -lm
