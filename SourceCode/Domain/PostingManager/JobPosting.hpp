#pragma once

#include "Domain/PostingManager/PostingManagerHandler.hpp"

#include <string>
#include <vector>

namespace Domain::PostingManager
{
    
    class JobPosting
    {
        public:
            //Operations
            //To Do: create methods/functions
            
        
        protected:
            //Copy assignment operators, protected to prevent mix derived-type assignments
            JobPosting & operator=( const JobPosting & rhs ) = default; // copy assignment
            JobPosting & operator=( const JobPosting && rhs) = default; // move assignment

            //TODO: 


        
    };

    /*****************************************************************************
    ** Inline implementations
    ******************************************************************************/
    inline PostingManagerHandler::~PostingManagerHandler() noexcept = default;













}