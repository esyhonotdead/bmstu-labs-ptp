#!/bin/bash

file1="$1"
file2="$2"

for file in "$file1" "$file2"; do
    if [ ! -f "$file" ]; then
        exit 1
    fi
done

extract_num() {
    local file="$1"
    grep -oE '[-+]?[0-9]+(\.[0-9]+)?([eE][-+]?[0-9]+)?' "$file"
}

floats_f1=$(extract_num "$file1")
floats_f2=$(extract_num "$file2")

if [ "$floats_f1" = "$floats_f2" ]; then
    exit 0
else
    exit 1
fi
