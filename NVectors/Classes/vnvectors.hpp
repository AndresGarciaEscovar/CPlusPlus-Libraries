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
         * VNVector.
         * 
         * @param vector The basis vector of NVectors to be added.
         * 
         * @param value The value to be added.
         *  
         * @return A copy of the vector of NVectors with the value added to each
         * of its entries.
        */
        friend VNVectors<T> operator + (VNVectors<T> vector, T value)
        {
            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i) 
                vector[i] = vector[i] + value;

            return vector;
        }


        /**
         * Addition operator overload. To add a scalar quantity to the current
         * VNVector.
         * 
         * @param value The value to be added.
         * 
         * @param vector The basis vector of NVectors to be added.
         *  
         * @return A copy of the vector of NVectors with the value added to each
         * of its entries.
        */
        friend VNVectors<T> operator + (T value, VNVectors<T> vector)
        {
            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i) 
                vector[i] = vector[i] + value;

            return vector;
        }


        /**
         * Addition operator overload. To add an NVector to the current 
         * NVectors in the VNVector.
         * 
         * @param vector The basis vector of NVectors to be added.
         * 
         * @param value The NVector to be added.
         *  
         * @return A copy of the vector of NVectors with the value added to each
         * of its entries.
        */
        friend VNVectors<T> operator + (
            VNVectors<T> vector, NVector::NVector<T> value
        )
        {
            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i) 
                vector[i] = vector[i] + value;

            return vector;
        }


        /**
         * Addition operator overload. To add two VNVectors; they need to have
         * the same number of NVectors for this to happen.
         * 
         * @param vector The vector of NVectors to be added.
         *  
         * @return A copy of the vector of NVectors with the value added to each
         * of its entries.
        */
        VNVectors<T> operator + (VNVectors<T> vector)
        {
            // Validate the dimensionality of the vector to be added.
            ValidationGeneral::validateDimensions(
                vsize, vector.size(), true
            );

            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i) 
                vector[i] = vector[i] + container[i];

            return vector;
        }


        ////////////////////////////////////////////////////////////////////////
        // Other Functionality
        ////////////////////////////////////////////////////////////////////////


        /**
         * Index operator overload. To be able to access the indexes of the
         * vector of NVectors.
         * 
         * @param index The requested index to be accessed.
        */
        NVector::NVector<T>& operator [] (size_t index)
        {   
            // Auxiliary variables.
            size_t lower{0}, upper{dimension - 1};

            // Validate the index is in range.
            ValidationGeneral::validateInRange(index, lower, upper, true);

            return container[index];
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