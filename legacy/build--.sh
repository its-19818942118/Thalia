#!/bin/bash

# Create a build directory if it doesn't exist
mkdir -p build/objects/
mkdir -p build/bin/

# Compile the main file.
g++ -c src/main.cpp -o build/objects/main.o

# Check if the main.o was created successfully
if [ $? -ne 0 ]; then
    echo "Error: Compilation of main.cpp failed."
    exit 1
fi

# Compile donut.cpp into an object file
g++ -c include/functions/donut.cpp -o build/objects/donut.o

# Check if the donut.o was created successfully
if [ $? -ne 0 ]; then
    echo "Error: Compilation of donut.cpp failed."
    exit 1
fi

# Link the object files to create the final executable
g++ build/objects/donut.o build/objects/main.o -o build/bin/donut

# Check if the linking was successful
if [ $? -ne 0 ]; then
    echo "Error: Linking failed."
    exit 1
fi

echo "Compilation complete. Object files are in the 'build' directory."
