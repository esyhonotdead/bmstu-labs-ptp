#!/bin/bash

SCRIPT_DIR=$(dirname "$(readlink -f "$0")")
"$SCRIPT_DIR"/build_gcov.sh
"$SCRIPT_DIR"/func_tests/scripts/func_tests.sh

gcov main.c

"$SCRIPT_DIR"/clean.sh