/*
    File that contains the headers/templates for the basic functions for general
    exceptions.
*/
#pragma once

//##############################################################################
// Imports.
//##############################################################################

// General.
#include <exception>
#include <string>

//##############################################################################
// Namespaces.
//##############################################################################


namespace ExceptionsGeneral
{
    //##########################################################################
    // Exception Classes.
    //##########################################################################

    /**
     * Class that builds the exceptions when an index is out of bounds.
    */
    class Numerical : virtual public std::exception
    {
        //######################################################################
        // Public Interface.
        //######################################################################

        public:

        //----------------------------------------------------------------------
        // Constructor.
        //----------------------------------------------------------------------

        /**
         * Constructor for the exception, customizes the exception message.
        */
        Numerical()
        {
            // Create the message.
            message = "The requested variable is not of numerical type.";
        }

        /**
         * Throws the exception.
        */
        virtual const char * what() const throw()
        {   
            // Set the custom message.
            return message.c_str();
        }

        //######################################################################
        // Private Interface.
        //######################################################################

        private:

        //----------------------------------------------------------------------
        // Variables.
        //----------------------------------------------------------------------

        // String that contains the exception message.
        std::string message{};
    };
}