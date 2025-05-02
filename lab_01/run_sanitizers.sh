#!/bin/bash

SCRIPT_DIR=$(dirname "$(readlink -f "$0")")


echo "========================================================="
echo "ADRESS SANITIZER"
echo "========================================================="


"$SCRIPT_DIR"/build_debug_asan.sh
"$SCRIPT_DIR"/func_tests/scripts/func_tests.sh -v
"$SCRIPT_DIR"/clean.sh

echo "========================================================="
echo "MEMORY SANITIZER"
echo "========================================================="

"$SCRIPT_DIR"/build_debug_msan.sh
"$SCRIPT_DIR"/func_tests/scripts/func_tests.sh -v
"$SCRIPT_DIR"/clean.sh


echo "========================================================="
echo "UNDEFINED BEHAVIOR SANITIZER"
echo "========================================================="


"$SCRIPT_DIR"/build_debug_ubsan.sh
"$SCRIPT_DIR"/func_tests/scripts/func_tests.sh -v
"$SCRIPT_DIR"/clean.sh