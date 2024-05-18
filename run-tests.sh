
# Change directory to the script's directory
cd "$(dirname "$0")"
cmake --build build
cd build/test && ctest --output-on-failure

