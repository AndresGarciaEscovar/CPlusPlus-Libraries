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
    NVector::NVector<double> temp = NVector::NVector<double>(3, 9),
        temp1 = NVector::NVector<double>(3, 7),
        temp2 = NVector::NVector<double>(3, 8);
     
    temp =  (temp1 + temp2) * 0.5;

    std::cout << (temp == temp) << std::endl;
    std::cout << "Dot product: " << temp.dotProduct(temp1) << std::endl;
    std::cout << temp.normSquared() << std::endl;

    return 0;
}
