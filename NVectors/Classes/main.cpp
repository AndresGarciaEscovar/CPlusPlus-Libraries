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
#include "./vnvectors.hpp"


//##############################################################################
// Main Function
//##############################################################################


int main()
{
    // Auxiliary variables.
    int i = 1;
    VNVectors::VNVectors<double> vtemp0 = VNVectors::VNVectors<double>(3, 5);

    // NVectors.
    NVector::NVector<double> temp0 = NVector::NVector<double>(3, 1);
    NVector::NVector<double> temp1 = NVector::NVector<double>(3, 7);
    NVector::NVector<double> temp2 = NVector::NVector<double>(3, 8);
    
    std::cout << "Equal to itself? " << (temp0 == temp0) << std::endl;
    std::cout << "Dot product: " << temp0.dotProduct(temp1) << std::endl;
    std::cout << "Norm squared: " << temp0.normSquared() << std::endl;
    std::cout << "Normalized: " << temp0.normalizeIP() << std::endl;
    std::cout << "Norm: " << temp0.norm() << std::endl;
    
    // Test the projection.
    temp0[0] = 3.0; temp0[1] = 3.0; temp0[2] = 3.0;
    temp1[0] = 1.0; temp1[1] = 1.0; temp1[2] = 1.0;
    
    std::cout << "Before normalize: " << temp1 << std::endl;
    std::cout << "Projection: " << temp0.projection(temp1, false) << std::endl;
    std::cout << "After Projection: " << temp1 << std::endl;

    // Test the cross product.
    temp0[0] = 1.0; temp0[1] = 1.0; temp0[2] = 1.0;
    temp1[0] = 1.0; temp1[1] = 1.0; temp1[2] = 2.0;
    std::cout << "Cross Product: " << temp0.crossProduct(temp1) << std::endl;

    return 0;
}
