#!/usr/bin/env bash

g++ -std=c++23 -flto -ftree-vectorize -funroll-loops -floop-strip-mine -o3 \
    -fstrict-aliasing -fomit-frame-pointer -march=native -mtune=native -oz \
    -fno-exceptions -fno-rtti -fdata-sections -ffunction-sections -Wl,--gc-sections \
    -I ./include src/main.cpp \
    -g include/functions/donut.cpp include/functions/kbInput.cpp \
    -o Thalia
\

# Echo stuff
echo "compilation completed"
sleep 3
./Thalia
