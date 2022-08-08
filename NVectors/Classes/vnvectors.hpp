/*
    File that contains the vector container for the new vector class and its
    functions.
*/
#pragma once

//##############################################################################
// Imports
//##############################################################################


// General.
#include <iomanip>
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
         * @param value The NVector to be added.
         * 
         * @param vector The basis vector of NVectors to be added.
         *  
         * @return A copy of the vector of NVectors with the value added to each
         * of its entries.
        */
        friend VNVectors<T> operator + (
            NVector::NVector<T> value, VNVectors<T> vector
        )
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
            ValidationGeneral::validateDimensions(vsize, vector.size(), true);

            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i) 
                vector[i] = vector[i] + container[i];

            return vector;
        }


        /**
         * Division operator overload. To divide each entry of the vector of
         * NVectors by the given scalar quantity.
         * 
         * @param vector The vector of NVectors to be divided.
         * 
         * @param value The value by which each vector will be divided.
         *  
         * @return A copy of the vector of NVectors with each of its entries
         * divided by the given value.
        */
        friend VNVectors<T> operator / (VNVectors<T> vector, T value)
        { 
            // Divide each entry.
            for(size_t i = 0; i < vector.size(); ++i) vector[i] /= value;

            return vector;
        }


        /**
         * Multiplication operator overload. To multiply each entry of the
         * vector of NVectors by the given scalar quantity.
         * 
         * @param vector The vector of NVectors to be multiplied.
         * 
         * @param value The value by which each entry will be multiplied.
         *  
         * @return A copy of the vector of NVectors with each of its entries 
         * multiplied by the given value.
        */
        friend VNVectors<T> operator * (VNVectors<T> vector, T value)
        {
            // Multiply each entry.
            for(size_t i = 0; i < vector.size(); ++i) vector[i] *= value;

            return vector;
        }


        /**
         * Multiplication operator overload. To multiply each entry of the
         * vector of NVectors by the given scalar quantity.
         * 
         * @param value The value by which each entry will be multiplied.
         * 
         * @param vector The vector of NVectors to be multiplied.
         * 
         * @return A copy of the vector of NVectors with each of its entries 
         * multiplied by the given value.
        */
        friend VNVectors<T> operator * (T value, VNVectors<T> vector)
        {
            // Multiply each entry.
            for(size_t i = 0; i < vector.size(); ++i) vector[i] *= value;

            return vector;
        }


        /**
         * Subtraction operator overload. To subtract a scalar quantity from the
         * current vector of NVectors.
         * 
         * @param vector The vector of NVectors from which the value will be
         * subtracted.
         * 
         * @param value The value to be subtracted.
        */
        friend VNVectors<T> operator - (VNVectors<T> vector, const T value)
        {           
            // Subtract from each vector component.
            for(size_t i = 0; i < vector.size(); ++i) vector[i] -= value;

            return vector;
        }


        /**
         * Subtraction operator overload. To subtract a scalar quantity from the
         * current vector of NVectors and make it negative.
         * 
         * @param value The value to be subtracted. 
         * 
         * @param vector The vector of NVectors from which the value will be
         * subtracted.
        */
        friend VNVectors<T> operator - (const T value, VNVectors<T> vector)
        {            
            // Subtract from each vector entry.
            for(size_t i = 0; i < vector.size(); ++i)
                vector[i] = value - vector[i];

            return vector;
        }


        /**
         * Subtraction operator overload. To subtract an NVector from the 
         * current NVectors in the VNVector.
         * 
         * @param vector The basis vector of NVectors from which the NVector
         * will be subtracted.
         * 
         * @param value The NVector to be added.
         *  
         * @return A copy of the vector of NVectors with the value subtracted
         * from each of its entries.
        */
        friend VNVectors<T> operator - (
            VNVectors<T> vector, NVector::NVector<T> value
        )
        {
            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i) 
                vector[i] = vector[i] - value;

            return vector;
        }


        /**
         * Subtraction operator overload. To subtract an NVector from the 
         * current NVectors in the VNVector, and then made negative.
         * 
         * @param value The NVector to be subtracted.
         * 
         * @param vector The basis vector of NVectors from which the NVector
         * will be subtracted.
         *  
         * @return A copy of the vector of NVectors with the value subtracted
         * from each of its entries and then made negative.
        */
        friend VNVectors<T> operator - (
            NVector::NVector<T> value, VNVectors<T> vector
        )
        {
            // Add the value to the vector.
            for(size_t i = 0; i < vector.size(); ++i) 
                vector[i] = value - vector[i];

            return vector;
        }


        /**
         * Subtraction operator overload. To subtract another vector of NVectors
         * from the current vector of VNVector.
         * 
         * @param vector The vector to be added to the current vector.
         * 
         * @return A copy of the vector with the value added to each of its
         * entries.
        */
        VNVectors<T> operator - (VNVectors<T> vector)
        {
            // Validate the dimensionality of the vector to be added.
            ValidationGeneral::validateDimensions(vsize, vector.size(), true);
            
            // Subtract each value.
            for(size_t i = 0; i < container.size(); ++i)
                vector[i] = container[i] - vector[i];

            return vector;
        }


        ////////////////////////////////////////////////////////////////////////
        // Other Functionality
        ////////////////////////////////////////////////////////////////////////


        /**
         * Comparison operator. To be able to access the indexes of the
         * vectors of NVectors for comparison.
         * 
         * @param vector A reference to the vectors being compared.
        */
        friend bool operator == (VNVectors<T>& vector_1, VNVectors<T>& vector_2)
        {   
            // Auxiliary variables.
            bool valid = ValidationGeneral::validateDimensions(
                vector_1.size(), vector_2.size(), false
            );

            valid = valid && ValidationGeneral::validateDimensions(
                vector_1[0].size(), vector_2[0].size(), false
            );

            // Check item by item.
            for(size_t i = 0; valid && i < vector_1.size(); ++i)
                valid = valid && vector_1[i] == vector_2[i];
                
            return valid;
        }


        /**
         * Outstream string to be print the vector of NVectors. To be able to
         * view the contents of the vector of NVectors.
         * 
         * @param out A reference to the ostream operator.
         * 
         * @param vect A reference to the vector of NVectors to be printed.
        */
        friend std::ostream& operator << (std::ostream& out, VNVectors<T> vect)
        {   
            // Print the content.
            for(size_t i = 0; i < vect.size(); ++i)
                out << std::setprecision(7) << vect[i] << std::endl;
                
            return out;
        }


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
            return vsize;
        }


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