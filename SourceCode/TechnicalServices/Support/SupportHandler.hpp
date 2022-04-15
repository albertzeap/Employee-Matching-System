#pragma once

#include <string>

namespace TechnicalServices::Support
{
    // Support Handler Package within the Technical Services Layer Abstract class
    class SupportHandler
    {
        public:
            //Operations
            virtual void requestSupportTicket()        = 0;
            virtual std::string resolveSupportTicket() = 0;

            //Destructor
            virtual ~SupportHandler() noexcept = 0;
        
        protected:
            //Copy assignment operators, protected to prevent mix derived-type assignments
            SupportHandler & operator=( const SupportHandler & rhs ) = default; // copy assignment
            SupportHandler & operator=( const SupportHandler && rhs) = default; // move assignment

        
    };

    /*****************************************************************************
    ** Inline implementations
    ******************************************************************************/
    inline SupportHandler::~SupportHandler() noexcept = default;

}
