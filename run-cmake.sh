#!/usr/bin/bash

# Change directory to this script's directory
cd "$(dirname "$0")"

rm -rf build
cmake -S . -G "Unix Makefiles" -B build

