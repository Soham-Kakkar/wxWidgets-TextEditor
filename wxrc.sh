#!/bin/bash

EXECUTABLE="MyWxApp"

SRC="./src"

cd $SRC

echo "Building UI binaries for $EXECUTABLE..."

for xrc_file in resources/*.xrc; do
    header_file="${xrc_file%.xrc}.hpp"    
    wxrc "$xrc_file" -c -o "$header_file"
done

echo "UI binaries built successfully!"
