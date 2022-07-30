/*
    File that contains the headers/templates for the basic functions for new
    vector types exceptions.
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


namespace ExceptionsNVector
{
    //##########################################################################
    // Exception Classes.
    //##########################################################################

    /**
     * Class that builds the exceptions when an index is out of bounds.
    */
    class Index : virtual public std::exception
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
         * @param expected The maximum expected index value.
         * 
         * @param requested The requested index value.
        */
        Index(size_t expected, size_t requested)
        {
            // Create the message.
            message = "The requested index fall out of range.\nRange: [0," + 
            std::to_string(expected) + "]\nRequested: " +
            std::to_string(requested);
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