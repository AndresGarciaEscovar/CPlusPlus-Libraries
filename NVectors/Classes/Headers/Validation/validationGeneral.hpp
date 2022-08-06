/*
    File that contains the validation functions for general purposes.
*/
#pragma once


//##############################################################################
// Imports
//##############################################################################


// General.
#include <cmath>


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

    
    // Determines if the given number is NOT dividing by zero.
    template <typename T>
    bool isNotDivingByZero(T variable, bool exception);


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
        size_t requested, size_t expectedl, size_t expectedh,  bool exception
    );


    //##########################################################################
    // Functions
    //##########################################################################


    //--------------------------------------------------------------------------
    // Is Functions
    //--------------------------------------------------------------------------


    /**
     * Determines if the given variable is NOT dividing by zero.
     * 
     * @param variable The variable whose division value is to be determined.
     * 
     * @param exception A boolean flag that indicates if an exception must be
     * thrown if validation fails. True, if an exception must be thrown if 
     * validation fails; False, otherwise.
     * 
     * @return True, if the variable is not dividing by zero, i.e., has a finite
     * division type. False, otherwise.
     * 
     * @throw ExceptionsGeneral::DivisionByZero, if the variable being checked 
     * when dividing a finite quanity is infinite or undetermined.
    */ 
    template <typename T>
    bool isNotDivingByZero(T variable, bool exception)
    {   
        // Initialize the variables.
        T var = (T) 1 / variable; 
        bool valid = !(std::isnan(var) || std::isinf(var));

        // Throw an exception if needed.
        if(!valid && exception) ExceptionsGeneral::DivisionByZero();

        return valid;
    }
}