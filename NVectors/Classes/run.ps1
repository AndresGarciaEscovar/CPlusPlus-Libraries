
# Compile the program.
g++ -std=c++17 -o main.exe main.cpp `
    ./Implementations/Validation/validationGeneral.cpp

# Execute the program.
./main.exe

# Remove the executable.
Remove-Item main.exe
