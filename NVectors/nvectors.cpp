/*
    File that contains the new vector class and its functions.
*/

//##############################################################################
// Imports
//##############################################################################

// General.
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <vector>

// User defined.
#include "./nvectors.hpp"

//##############################################################################
// Main Function
//##############################################################################

int main()
{
    int i = 1;
    NVector::NVector<int> temp = NVector::NVector<int>(3, 9),
        temp1 = NVector::NVector<int>(3, 7);
    
    temp = 1 + temp;

    std::cout << temp[0] << ", " << temp[1] << ", " << temp[2] << std::endl;

    return 0;
}
