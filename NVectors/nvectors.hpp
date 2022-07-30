/*
    File that contains the new vector class and its functions.
*/
#pragma once

//##############################################################################
// Imports
//##############################################################################

// General.
#include <iostream>
#include <stdexcept>
#include <typeinfo>
#include <vector>

// User defined.
#include "./Headers/Validation/validationGeneral.hpp"

namespace NVector
{
    //##########################################################################
    // Classes
    //##########################################################################

    template <class T>
    class NVector
    {
        public:
        //######################################################################
        // Function Specifications
        //######################################################################
        
        ////////////////////////////////////////////////////////////////////////
        // Non-Template Functions
        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // Template Functions
        ////////////////////////////////////////////////////////////////////////
        
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
         * @param value The value to be added.
        */
        NVector<T> operator + (const T value) const
        {
            // Create a new vector.
            NVector<T> vector0 = NVector(dimension);
            
            // Add the value.
            for(size_t i = 0; i < container.size(); ++i)
                vector0[i] = container[i] + value;

            return vector0;
        }

        /**
         * Addition operator overload. To add another NVector to the current
         * NVector.
         * 
         * @param vector The vector to be added.
        */
        NVector<T> operator + (NVector<T>& vector) const
        {
            // Create a new vector.
            NVector<T> vector0 = NVector(dimension);
            
            // Add the value.
            for(size_t i = 0; i < container.size(); ++i)
                vector0[i] = container[i] + vector[i];

            return vector0;
        }

        /**
         * Subtraction operator overload. To subtract a scalar quantity from the
         * current NVector.
         * 
         * @param vector The vector itself.
         * 
         * @param value The value to be subtracted.
        */
        NVector<T> operator - (const T value) const
        {
            // Create a new vector.
            NVector<T> vector0 = NVector(dimension);
            
            // Add the value.
            for(size_t i = 0; i < container.size(); ++i)
                vector0[i] = container[i] - value;

            return vector0;
        }

        /**
         * Subtraction operator overload. To subtract another NVector from the
         * current NVector.
         * 
         * @param vector The vector to be subtracted.
        */
        NVector<T> operator - (NVector<T>& vector) const
        {
            // Create a new vector.
            NVector<T> vector0 = NVector(dimension);
            
            // Add the value.
            for(size_t i = 0; i < container.size(); ++i)
                vector0[i] = container[i] - vector[i];

            return vector0;
        }

        ////////////////////////////////////////////////////////////////////////
        // Other Functionality
        ////////////////////////////////////////////////////////////////////////

        /**
         * Index operator overload. To be able to access the indexes of the
         * vector.
         * 
         * @param index The requested index to be accessed.
        */
        T& operator [] (size_t index)
        {
            // Exception is thrown if needed.
            ValidationGeneral::validateInRange(0, dimension - 1, index, true);

            return container[index];
        }

        //######################################################################
        // Constructor(s) and Destructor(s)
        //######################################################################

        /**
         * Constructs a new vector type. Will be initialized with the zero
         * element.
         * 
         * @param dimensions The number of entries the vector has; must be 
         * greater than zero.
        */
        NVector(size_t dimensions) :
        dimension{dimensions}
        {
            // Validate that it's a numerical type.
            T i;
            ValidationGeneral::isNumber<T>(i, true);
            container = std::vector<T>(dimension, (T) 0);
        }

        /**
         * Constructs a new vector type.
         * 
         * @param dimensions The number of entries the vector has; must be 
         * greater than zero.
         * 
         * @param value The value with which the entries will be initialized.
        */
        NVector(size_t dimensions, T value) :
        dimension{dimensions}
        {   
            // Validate that it's of a numerical type.
            ValidationGeneral::isNumber<T>(value, true);
            container = std::vector<T>(dimension, value);
        }

        /**
         * Destructs the given object pointer.
        */
        ~NVector(){}

        private:
        //######################################################################
        // Variables
        //######################################################################

        // Vector that contains the variables.
        std::vector<T> container{0};

        // Size of the vector to be constructed.
        size_t dimension{0};
    };
}
