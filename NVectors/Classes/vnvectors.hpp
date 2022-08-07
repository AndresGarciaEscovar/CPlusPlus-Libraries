/*
    File that contains the vector container for the new vector class and its
    functions.
*/
#pragma once

//##############################################################################
// Imports
//##############################################################################


// General.
#include <iostream>
#include <ostream>
#include <vector>


// User defined.
#include "./Headers/Validation/validationGeneral.hpp"
#include "./Headers/Validation/validationNumerical.hpp"
#include "./nvectors.hpp"


//##############################################################################
// Namespaces
//##############################################################################


namespace VNVectors
{
    //##########################################################################
    // Classes
    //##########################################################################


    template <typename T>
    class VNVectors
    {
        public:
        //######################################################################
        // Operator Overloads
        //######################################################################


        ////////////////////////////////////////////////////////////////////////
        // Arithmetic
        ////////////////////////////////////////////////////////////////////////


        /**
         * Addition operator overload. To add a scalar quantity to the current
         * NVector.
         * 
         * @param vector The basis vector to be added.
         * 
         * @param value The value to be added.
         *  
         * @return A copy of the vector with the value added to each of its 
         * entries.
        */
        friend NVector<T> operator + (VNVector<T> vector, T value)
        {
            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i) vector[i] += value;

            return vector;
        }

        //######################################################################
        // Constructor(s) and Destructor(s)
        //######################################################################


        /**
         * Constructs a new vector of NVectors. All Nvector elements will be
         * initialized such that all of its entries are set to zero.
         * 
         * @param dimensions The number of entries the NVectors in the
         * VNVectors will have; the dimension must be greater than zero.
         * 
         * @param quantity The number of NVectors in the vector of NVectors;
         * the size cannot be changed, must be greater than zero.
        */
        VNVectors(size_t dimensions, size_t size) :
        dimension{dimensions},
        vsize{size}
        {
            // Validate the quantities.
            ValidationNumerical::rangeGreater<size_t>(0, vsize, true);
            ValidationNumerical::isFloating<T>((T) 1, true);

            // Initialize the vector with the given number of NVectors.
            container = std::vector<NVector::NVector<T>>(
                vsize, NVector::NVector<T>(dimension)
            );
            container.shrink_to_fit();
        }

        /**
         * Destructs the given object pointer.
        */
        ~VNVectors(){}


        //######################################################################
        // Functions
        //######################################################################
        
        private:
        //######################################################################
        // Variables
        //######################################################################


        // Vector that contains the variables.
        std::vector<NVector::NVector<T>> container;


        // Size of the NVectors in the vector.
        size_t dimension{0};


        // Size of the vector of NVectors.
        size_t vsize{0};
    };
}