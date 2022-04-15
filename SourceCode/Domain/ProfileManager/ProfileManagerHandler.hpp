#pragma once

namespace Domain::ProfileManager
{
    // Profile Manager Package within the Domain Layer Abstract class
    class ProfileManagerHandler
    {
        public:
            //Operations
            virtual void manageResume() = 0;
            virtual bool uploadResume() = 0;

            //Destructor
            virtual ~ProfileManagerHandler() noexcept = 0;
        
        protected:
            //Copy assignment operators, protected to prevent mix derived-type assignments
            ProfileManagerHandler & operator=( const ProfileManagerHandler & rhs ) = default; // copy assignment
            ProfileManagerHandler & operator=( const ProfileManagerHandler && rhs) = default; // move assignment


        
    };

    /*****************************************************************************
    ** Inline implementations
    ******************************************************************************/
    inline ProfileManagerHandler::~ProfileManagerHandler() noexcept = default;













}