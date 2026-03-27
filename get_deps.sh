#!/bin/bash

EXECUTABLE="MyWxApp"

BUILD_DIR="./build/lib"

mkdir -p "$BUILD_DIR"

echo "Collecting dependencies for $EXECUTABLE..."

# Run ldd and extract the paths to `.so` files
ldd "./build/$EXECUTABLE" | grep "=> /" | awk '{print $3}' | while read lib; do
    if [[ "$lib" =~ \.so ]]; then
        cp "$lib" "$BUILD_DIR"
    fi
done

echo "All dependencies have been copied to $BUILD_DIR."
