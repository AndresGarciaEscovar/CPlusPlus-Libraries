/*
    File that contains the implementation functions for the validation of 
    general quantities.
*/


//##############################################################################
// Imports
//##############################################################################


#include "../../Headers/Validation/validationGeneral.hpp"


//##############################################################################
// Namespaces
//##############################################################################


namespace ValidationGeneral
{
    //##########################################################################
    // Functions
    //##########################################################################


    //--------------------------------------------------------------------------
    // Validation Functions
    //--------------------------------------------------------------------------


     /**
     * Determines if the requested number of dimensions is consistent.
     * 
     * @param expected The expected number of dimensions.
     * 
     * @param requested The requested number of dimensions.
     * 
     * @param exception A boolean flag that indicates if an exception must be
     * thrown if validation fails. True, if an exception must be thrown if 
     * validation fails; False, otherwise.
     * 
     * @return True, if the requested number of dimensions matches the expected
     * number of dimensions. False, otherwise.
     * 
     * @throw ExceptionsVector::Dimensional, if the requested number of
     * dimensions doesn't match the expected number of dimensions.
    */ 
    bool validateDimensions(size_t expected, size_t requested, bool exception)
    {   
        // Initialize the variable
        bool valid = expected == requested;

        // Throw an exception if needed.
        if(!valid && exception)
            throw ExceptionsGeneral::Dimensions(expected, requested);

        return valid;
    }


     /**
     * Determines if the requested number of dimensions is consistent.
     * 
     * @param expected The expected number of dimensions.
     * 
     * @param requested The requested number of dimensions.
     * 
     * @param exception A boolean flag that indicates if an exception must be
     * thrown if validation fails. True, if an exception must be thrown if 
     * validation fails; False, otherwise.
     * 
     * @return True, if the requested number of dimensions matches the expected
     * number of dimensions. False, otherwise.
     * 
     * @throw ExceptionsVector::Dimensional, if the requested number of
     * dimensions doesn't match the expected number of dimensions.
    */ 
    bool validateInRange(
        size_t requested, size_t expectedl, size_t expectedh,  bool exception
    )
    {   
        // Initialize the variable.
        bool valid = expectedl <= requested && requested <= expectedh;

        // Throw an exception if needed.
        if(!valid && exception)
            throw ExceptionsGeneral::IndexOutOfRange(
                expectedl, expectedh, requested
            );

        return valid;
    }
}