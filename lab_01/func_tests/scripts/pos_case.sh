#!/bin/bash

SCRIPT_DIR=$(dirname "$(readlink -f "$0")")

for file in "$1" "$2"; do
    if [ ! -f "$file" ]; then
        echo "File '$file' does not exist" >&2
        exit 2
    fi
done

filein="$1"
file_out_expect="$2"
app_path="$SCRIPT_DIR/../../app.exe"
comparator_path="$SCRIPT_DIR/comparator.sh"

check_file_exists() {
    if [ ! -f "$1" ]; then
        echo "$2 not found at $1" >&2
        exit 2
    fi
}

check_file_exists "$app_path" "app.exe"
check_file_exists "$comparator_path" "comparator.sh"

if ! "$app_path" < "$filein" > current.txt; then
    exit 1
fi

if ! "$comparator_path" "$file_out_expect" "current.txt"; then
    exit 1
fi

exit 0