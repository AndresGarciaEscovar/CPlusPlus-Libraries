#!/bin/bash

# Compile and link.
c++ -std=c++17 -o nvectors nvectors.cpp \
    ./Implementations/Validation/validationGeneral.cpp

# Run the progam.
./nvectors

# Remove the executable.
rm nvectors