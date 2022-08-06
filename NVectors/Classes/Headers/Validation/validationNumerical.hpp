/*
    File that contains the validation functions of numerical quantities.
*/
#pragma once


//##############################################################################
// Imports
//##############################################################################


// General.
#include <cmath>
#include <typeinfo>


// User defined.
#include "../Exceptions/exceptionsNumerical.hpp"


//##############################################################################
// Namespaces
//##############################################################################


namespace ValidationNumerical
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


    // Determines if the given variable is of a floting point numerical type.
    template <typename T>
    bool isFloating(T variable, bool exception);


    // Determines if the given variable is of a signed or unsigned integer type.
    template <typename T>
    bool isInteger(T variable, bool exception);


    // Determines if the given variable is of a signed integer type.
    template <typename T>
    bool isIntegerSigned(T variable, bool exception);


    // Determines if the given variable is of an unsigned integer type.
    template <typename T>
    bool isIntegerUnsigned(T variable, bool exception);


    // Determines if the given variable is of a standard numerical type.
    template <typename T>
    bool isNumber(T variable, bool exception);


    //##########################################################################
    // Functions
    //##########################################################################


    //--------------------------------------------------------------------------
    // Is Functions
    //--------------------------------------------------------------------------


    /**
     * Determines if the given variable is a floating point number type.
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
     * @throw ExceptionsNumerical::Numerical, if the variable being checked is
     * not of a numerical type.
    */ 
    template <typename T>
    bool isFloating(T variable, bool exception)
    {   
        // Initialize the variable
        bool valid{false};

        valid = valid || typeid(variable) == typeid(float);
        valid = valid || typeid(variable) == typeid(double);
        valid = valid || typeid(variable) == typeid(long double);

        // Throw an exception if needed.
        if(!valid && exception) throw ExceptionsNumerical::Numerical();

        return valid;
    }


    /**
     * Determines if the given variable is a signed or unsigned integer.
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
     * @throw ExceptionsNumerical::Numerical, if the variable being checked is
     * not of a numerical type.
    */ 
    template <typename T>
    bool isInteger(T variable, bool exception)
    {   
        // Initialize the variable
        bool valid{false};

        // Validate for floating and integer.
        valid = valid || isIntegerSigned(variable, false);
        valid = valid || isIntegerUnsigned(variable, false);

        // Throw an exception if needed.
        if(!valid && exception) throw ExceptionsNumerical::Numerical();

        return valid;
    }


    /**
     * Determines if the given variable is a signed integer.
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
     * @throw ExceptionsNumerical::Numerical, if the variable being checked is
     * not of a numerical type.
    */ 
    template <typename T>
    bool isIntegerSigned(T variable, bool exception)
    {   
        // Initialize the variable
        bool valid{false};
        
        // Compare with all the known numerical signed integer types.
        valid = valid || typeid(variable) == typeid(int8_t);
        valid = valid || typeid(variable) == typeid(int16_t);
        valid = valid || typeid(variable) == typeid(int32_t);
        valid = valid || typeid(variable) == typeid(int64_t);
                
        valid = valid || typeid(variable) == typeid(short int);
        valid = valid || typeid(variable) == typeid(int);
        valid = valid || typeid(variable) == typeid(long int);

        valid = valid && typeid(variable) != typeid(bool);
        valid = valid && typeid(variable) != typeid(char);

        // Throw an exception if needed.
        if(!valid && exception) throw ExceptionsNumerical::Numerical();

        return valid;
    }


    /**
     * Determines if the given variable is an unsigned signed integer.
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
     * @throw ExceptionsNumerical::Numerical, if the variable being checked is
     * not of a numerical type.
    */ 
    template <typename T>
    bool isIntegerUnsigned(T variable, bool exception)
    {   
        // Initialize the variable
        bool valid{false};
        
        // Validate the simple known types.
        valid = valid || typeid(variable) == typeid(size_t);
        
        valid = valid || typeid(variable) == typeid(uint8_t);
        valid = valid || typeid(variable) == typeid(uint16_t);
        valid = valid || typeid(variable) == typeid(uint32_t);
        valid = valid || typeid(variable) == typeid(uint64_t);
        
        valid = valid || typeid(variable) == typeid(unsigned short int);
        valid = valid || typeid(variable) == typeid(unsigned int);
        valid = valid || typeid(variable) == typeid(unsigned long int);

        valid = valid && typeid(variable) != typeid(bool);
        valid = valid && typeid(variable) != typeid(char);

        // Throw an exception if needed.
        if(!valid && exception) throw ExceptionsNumerical::Numerical();

        return valid;
    }


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
     * @throw ExceptionsNumerical::Numerical, if the variable being checked is
     * not of a numerical type.
    */ 
    template <typename T>
    bool isNumber(T variable, bool exception)
    {   
        // Initialize the variable
        bool valid{false};
        
        // Compare with all the known numerical types.
        valid = valid || isInteger(variable, false);
        valid = valid || isFloating(variable, false);

        // Throw an exception if needed.
        if(!valid && exception) throw ExceptionsNumerical::Numerical();

        return valid;
    }
}