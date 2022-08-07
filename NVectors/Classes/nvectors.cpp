/*
    File that contains the new vector class and its functions.
*/


//##############################################################################
// Imports
//##############################################################################


// General.
#include <iostream>
#include <limits>
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
    // Auxiliary variables.
    int i = 1;
    NVector::NVector<double> temp0 = NVector::NVector<double>(1);
    NVector::NVector<double> temp1 = NVector::NVector<double>(3, 7);
    NVector::NVector<double> temp2 = NVector::NVector<double>(3, 8);
     
    temp0 =  (temp1 + temp2) * 0.5;

    std::cout << "Equal to itself? " << (temp0 == temp0) << std::endl;
    std::cout << "Dot product: " << temp0.dotProduct(temp1) << std::endl;
    std::cout << "Norm squared: " << temp0.normSquared() << std::endl;
    std::cout << "Normalized: " << temp0.normalizeIP() << std::endl;
    std::cout << "Norm: " << temp0.norm() << std::endl;
    
    // Test the projection.
    temp0[0] = 3.0; temp0[1] = 3.0; temp0[2] = 3.0;
    temp1[0] = 1.0; temp1[1] = 1.0; temp1[2] = 1.0;
    
    std::cout << "Before normalize: " << temp1 << std::endl;
    temp0.projection(temp1);
    std::cout << "After Projection: " << temp1 << std::endl;

    // Test the cross product.
    temp0[0] = 1.0; temp0[1] = 1.0; temp0[2] = 1.0;
    temp1[0] = 1.0; temp1[1] = 1.0; temp1[2] = 2.0;
    std::cout << "Cross Product: " << temp0.crossProduct(temp1) << std::endl;

    std::cout << std::numeric_limits<long double>::digits10 << std::endl;

    return 0;
}