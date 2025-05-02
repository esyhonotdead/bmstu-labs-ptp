#!/bin/bash

# поменять номер сишного файлы для компиляции (мне лень скрипт нормальный писать)

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -Wvla -c -O0 -g3 ./task_01.c
gcc -o app.exe task_01.o -lm
