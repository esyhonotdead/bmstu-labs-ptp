#!/bin/bash

SCRIPT_DIR=$(dirname "$(readlink -f "$0")")

files_to_check=(
    "build_debug.sh"
    "build_release.sh"
    "build_debug_asan.sh"
    "build_debug_msan.sh"
    "build_debug_ubsan.sh"
    "func_tests/scripts/comparator.sh"
    "func_tests/scripts/func_tests.sh"
    "func_tests/scripts/neg_case.sh"
    "func_tests/scripts/pos_case.sh"
)

for file in "${files_to_check[@]}"; do
    full_path="$SCRIPT_DIR/$file"
    echo "Checking $full_path"
    shellcheck "$full_path"
done