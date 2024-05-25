#!/usr/bin/bash

# Change directory to this script's directory
cd "$(dirname "$0")"

# rm -rf build
# cmake -S . -G "Unix Makefiles" -B build
cmake --build build
# cd build/test && ctest --output-on-failure

