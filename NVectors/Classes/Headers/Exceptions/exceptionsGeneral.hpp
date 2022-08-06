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
     * Class that builds the exceptions when the number of requested dimensions
     * doesn't match the number of expected dimensions.
    */
    class Dimensions : virtual public std::exception
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
         * 
         * @param expected The expected number of dimensions.
         * 
         * @param requested The requested number of dimensions.
        */
        Dimensions(size_t expected, size_t requested)
        {
            // Create the message.
            message = "The requested number of dimensions doesn't match the "
            "expected number of dimensions.\n" 
            "\n\tExpected: " + std::to_string(expected) + "" 
            "\n\tRequested: " + std::to_string(requested) + "\n";
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

    /**
     * Class that builds the exceptions when an index is out of range.
    */
    class IndexOutOfRange : virtual public std::exception
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
         * 
         * @param expectedl The expected lower bound.
         * 
         * @param expectedh The expected higher bound.
         * 
         * @param requested The requested number.
        */
        IndexOutOfRange(size_t expectedl, size_t expectedh, size_t requested)
        {
            // Create the message.
            message = "The requested number is out of bounds, i.e., it is not "
            "in the given range.\n\tRange, including both ends: [" +
            std::to_string(expectedl) + ", " + std::to_string(expectedh) + ""
            "]\n\tRequested: " + std::to_string(requested) + "\n";
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