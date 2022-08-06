/*
    File that contains the headers/templates for the basic functions of
    basic numerical exceptions.
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


namespace ExceptionsNumerical
{
    //##########################################################################
    // Exception Classes.
    //##########################################################################


    /**
     * Class that builds the exceptions when a division by zero is attempted.
    */
    class DivisionByZero : virtual public std::exception
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
        DivisionByZero()
        {
            // Create the message.
            message = "A division by zero has been attempted, this is not "
            "possible.";
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