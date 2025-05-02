#!/bin/bash

SCRIPT_DIR=$(dirname "$(readlink -f "$0")")

if [ ! -f "$1" ]; then
    echo "File '$1' does not exist" >&2
    exit 2
fi

app_path="$SCRIPT_DIR/../../app.exe"

if [ ! -f "$app_path" ]; then
    echo "app.exe not found at $app_path" >&2
    exit 2
fi

if "$app_path" < "$1" >/dev/null; then
    exit 1
else
    exit 0
fi