
# Compile the program.
g++ -std=c++17 nvectors.cpp `
    ./Implementations/Validation/validationGeneral.cpp

# Execute the program.
./a.exe

# Remove the executable.
Remove-Item a.exe