#!/bin/bash

SCRIPT_DIR=$(dirname "$(readlink -f "$0")")
"$SCRIPT_DIR"/build_debug.sh
"$SCRIPT_DIR"/func_tests/scripts/func_tests.sh -v
"$SCRIPT_DIR"/clean.sh