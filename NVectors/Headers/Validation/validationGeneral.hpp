/*
    File that contains the validation functions for general purposes.
*/
#pragma once

//##############################################################################
// Imports
//##############################################################################

// General.
#include <typeinfo>

// User defined.
#include "../Exceptions/exceptionsGeneral.hpp"

//##############################################################################
// Namespaces
//##############################################################################

namespace ValidationGeneral
{
    //##########################################################################
    // Function Specification
    //##########################################################################

    ////////////////////////////////////////////////////////////////////////////
    // Template
    ////////////////////////////////////////////////////////////////////////////
    
    //--------------------------------------------------------------------------
    // Is Functions
    //--------------------------------------------------------------------------

    // Determines if the given variable is of a standard numerical type.
    template <typename T>
    bool isNumber(T variable, bool exception);

    ////////////////////////////////////////////////////////////////////////////
    // Non-Template
    ////////////////////////////////////////////////////////////////////////////

    //--------------------------------------------------------------------------
    // Validation Functions
    //--------------------------------------------------------------------------

    // Validates consistency of number of dimensions.
    bool validateDimensions(size_t expected, size_t requested, bool exception);

    // Validates if the number is in the given range.
    bool validateInRange(
        size_t expectedl, size_t expectedh, size_t requested, bool exception
    );

    //##########################################################################
    // Functions
    //##########################################################################

    //--------------------------------------------------------------------------
    // Is Functions
    //--------------------------------------------------------------------------

    /**
     * Determines if the given variable is of a standard numerical type.
     * 
     * @param variable The variable whose nature is to be determined.
     * 
     * @param exception A boolean flag that indicates if an exception must be
     * thrown if validation fails. True, if an exception must be thrown if 
     * validation fails; False, otherwise.
     * 
     * @return True, if the variable is of a standard numerical type. False,
     * otherwise.
     * 
     * @throw ExceptionsGeneral::Numerical, if the variable being checked is not
     * of a numerical type.
    */ 
    template <typename T>
    bool isNumber(T variable, bool exception)
    {   
        // Initialize the variable
        bool valid = true;
        
        // Compare with all the known numerical types.
        valid = valid || typeid(variable) == typeid(size_t);

        valid = valid || typeid(variable) == typeid(int8_t);
        valid = valid || typeid(variable) == typeid(int16_t);
        valid = valid || typeid(variable) == typeid(int32_t);
        valid = valid || typeid(variable) == typeid(int64_t);
        
        valid = valid || typeid(variable) == typeid(uint8_t);
        valid = valid || typeid(variable) == typeid(uint16_t);
        valid = valid || typeid(variable) == typeid(uint32_t);
        valid = valid || typeid(variable) == typeid(uint64_t);
        
        valid = valid || typeid(variable) == typeid(short int);
        valid = valid || typeid(variable) == typeid(int);
        valid = valid || typeid(variable) == typeid(long int);

        valid = valid || typeid(variable) == typeid(unsigned short int);
        valid = valid || typeid(variable) == typeid(unsigned int);
        valid = valid || typeid(variable) == typeid(unsigned long int);

        valid = valid || typeid(variable) == typeid(float);
        valid = valid || typeid(variable) == typeid(double);
        valid = valid || typeid(variable) == typeid(long double);

        valid = valid && typeid(variable) != typeid(bool);
        valid = valid && typeid(variable) != typeid(char);

        // Throw an exception if needed.
        if(!valid && exception) throw ExceptionsGeneral::Numerical();

        return valid;
    }
}