#!/bin/bash

# Compile and link.
c++ -std=c++17 -o main main.cpp \
    ./Implementations/Validation/validationGeneral.cpp

# Run the progam.
./main

# Remove the executable.
rm main
