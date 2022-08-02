/*
    File that contains the new vector class and its functions.
*/
#pragma once

//##############################################################################
// Imports
//##############################################################################

// General.
#include <iostream>
#include <ostream>
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
        friend NVector<T> operator + (NVector<T> vector, T value)
        {
            // Create a new vector.
            NVector<T> vector0 = NVector<T>(vector.size());
            
            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i)
                vector0[i] = vector[i] + value;

            return vector0;
        }

        /**
         * Addition operator overload. To add a scalar quantity to the current
         * NVector.
         * 
         * @param value The value to be added.
         * 
         * @param vector The basis vector to be added.
         * 
         * @return A copy of the vector with the value added to each of its 
         * entries.
        */
        friend NVector<T> operator + (T value, NVector<T> vector)
        {
            // Create a new vector.
            NVector<T> vector0 = NVector<T>(vector.size());
            
            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i)
                vector0[i] = vector[i] + value;

            return vector0;
        }

        /**
         * Addition operator overload. To add another NVector to the current
         * NVector.
         * 
         * @param vector The vector to be added to the current vector.
         * 
         * @return A copy of the vector with the value added to each of its
         * entries.
        */
        NVector<T> operator + (NVector<T> vector)
        {
            // Validate the dimensionality of the vector to be added.
            ValidationGeneral::validateDimensions(
                dimension, vector.size(), true
            );

            // Create a new vector.
            NVector<T> vector0 = NVector<T>(dimension);
            
            // Add the value.
            for(size_t i = 0; i < container.size(); ++i)
                vector0[i] = container[i] + vector[i];

            return vector0;
        }

        /**
         * Division operator overload. To divide each entry of the vector by the
         * given scalar quantity.
         * 
         * @param vector The basis vector.
         * 
         * @param value The value by which each entry will be divided.
         *  
         * @return A copy of the vector with each of its entries divided by the
         * given value.
        */
        NVector<T> operator / (T value)
        {   
            // Validate finite division.
            ValidationGeneral::isNotDivingByZero(value, true);

            // Create a new vector.
            NVector<T> vector0 = NVector<T>(dimension);
            
            // Divide each entry.
            for(size_t i = 0; i < container.size(); ++i)
                vector0[i] = container[i] / value;

            return vector0;
        }

        /**
         * Multiplication operator overload. To multiply each entry of the
         * vector by the given scalar quantity.
         * 
         * @param vector The basis vector.
         * 
         * @param value The value by which each entry will be multiplied.
         *  
         * @return A copy of the vector with each of its entries multiplied by
         * the given value.
        */
        friend NVector<T> operator * (NVector<T> vector, T value)
        {
            // Create a new vector.
            NVector<T> vector0 = NVector<T>(vector.size());
            
            // Multiply each entry.
            for(size_t i = 0; i < vector.size(); ++i)
                vector0[i] = vector[i] * value;

            return vector0;
        }

        /**
         * Multiplication operator overload. To multiply each entry of the
         * vector by the given scalar quantity.
         * 
         * @param value The value by which each entry will be multiplied.
         * 
         * @param vector The basis vector.
         * 
         * @return A copy of the vector with each of its entries multiplied by
         * the given value.
        */
        friend NVector<T> operator * (T value, NVector<T> vector)
        {
            // Create a new vector.
            NVector<T> vector0 = NVector<T>(vector.size());
            
            // Multiply each entry.
            for(size_t i = 0; i < vector.size(); ++i)
                vector0[i] = value * vector[i];

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
        friend NVector<T> operator - (NVector<T> vector, const T value)
        {
            // Create a new vector.
            NVector<T> vector0 = NVector<T>(vector.size());
            
            // Add the value.
            for(size_t i = 0; i < vector.size(); ++i)
                vector0[i] = vector[i] - value;

            return vector0;
        }

        /**
         * Subtraction operator overload. To subtract another NVector from the
         * current NVector and make it negative.
         * 
         * @param value The value to be subtracted. 
         * 
         * @param vector The vector to be subtracted.
        */
        friend NVector<T> operator - (const T value, NVector<T> vector)
        {
            // Create a new vector.
            NVector<T> vector0 = NVector<T>(vector.size());
            
            // Add the value.
            for(size_t i = 0; i < vector.size(); ++i)
                vector0[i] = value - vector[i];

            return vector0;
        }

        /**
         * Subtraction operator overload. To subtract another NVector from the
         * current NVector.
         * 
         * @param vector The vector to be added to the current vector.
         * 
         * @return A copy of the vector with the value added to each of its
         * entries.
        */
        NVector<T> operator - (NVector<T> vector)
        {
            // Validate the dimensionality of the vector to be added.
            ValidationGeneral::validateDimensions(
                dimension, vector.size(), true
            );

            // Create a new vector.
            NVector<T> vector0 = NVector<T>(dimension);
            
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
         * @param out A reference to the ostream operator.
         * 
         * @param vector A reference to the vector to be printed.
        */
        friend std::ostream& operator << (std::ostream& out, NVector<T>& vector)
        {   
            // Open the vector.
            out << "(";

            // Print the content.
            for(size_t i = 0; i < vector.size(); ++i)
            {
                out << vector[i];
                if(i < vector.size() - 1) out << ", ";
            }

            // Close the vector.
            out << ")";

            return out;
        }

        /**
         * Index operator overload. To be able to access the indexes of the
         * vector.
         * 
         * @param index The requested index to be accessed.
        */
        T& operator [] (size_t index)
        {   
            // Auxiliary variables.
            size_t lower{0}, upper{dimension - 1};

            // Exception is thrown if needed.
            ValidationGeneral::validateInRange(index, lower, upper, true);

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
            container.shrink_to_fit();
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
            container.shrink_to_fit();
        }

        /**
         * Destructs the given object pointer.
        */
        ~NVector(){}

        //######################################################################
        // Functions
        //######################################################################

        ////////////////////////////////////////////////////////////////////////
        // Non-Template Functions
        ////////////////////////////////////////////////////////////////////////

        /**
         * Returns the current size of the container.
         * 
         * @return The current size of the container.
        */
        size_t size()
        {
            return container.size();
        }

        ////////////////////////////////////////////////////////////////////////
        // Template Functions
        ////////////////////////////////////////////////////////////////////////

        /**
         * Returns the dot product of an NVector with another NVector.
         * 
         * @param vector The vector with which the dot product will be taken.
         * 
         * @return The dot product of the vector itself with the given vector.
        */ 
        T dotProduct(NVector<T>& vector)
        {
            // Validate the sizes are the same.
            ValidationGeneral::validateDimensions(
                dimension, vector.size(), true
            );

            // Auxiliary variables.
            T accum = (T) 0;

            // Perform the dot product.
            for(size_t i = 0; i < dimension; ++i)
                accum += container[i] * vector[i];
            
            return accum;
        }

        /**
         * Returns the L2 norm of the vector.
         * 
         * @return The L2 norm of the vector.
        */ 
        T norm()
        {
            return std::sqrt(normSquared());
        }

        /**
         * Returns the L2 norm, squared, of the vector.
         * 
         * @return The L2 norm, squared, of the vector.
        */ 
        T normSquared()
        {
            return dotProduct(*this);
        }

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
