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
#include "./Headers/Exceptions/exceptionsNVectors.hpp"
#include "./Headers/Validation/validationGeneral.hpp"

//##############################################################################
// Classes
//##############################################################################

template <class T>
class NVector
{
    public:
    //##########################################################################
    // Operator Overloads
    //##########################################################################

    /**
     * Index operator overload. To be able to access the indexes of the
     * vector.
     * 
     * @param index The requested index to be accessed.
    */
    T& operator [] (size_t index)
    {
        // Exception is thrown if needed.
        if(index >= dimension) throw ExceptionsNVector::Index(dimension, index);

        return container[index];
    }

    //##########################################################################
    // Constructor(s) and Destructor(s)
    //##########################################################################

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
        T i;
        std::cout << ValidationGeneral::isNumber<T>(i, false) << std::endl;
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
        std::cout << ValidationGeneral::isNumber<T>(value, false) << std::endl;
        container = std::vector<T>(dimension, value);
    }

    /**
     * Destructs the given object pointer.
    */
    ~NVector(){}

    private:
    //##########################################################################
    // Variables
    //##########################################################################

    // Vector that contains the variables.
    std::vector<T> container{0};

    // Size of the vector to be constructed.
    size_t dimension{0};
};


int main()
{
    NVector<int> temp = NVector<int>(3, 9.0);
    
    temp[2] = 324;

    std::cout << temp[0] << ", " << temp[1] << ", " << temp[2] << std::endl;

    return 0;
}
