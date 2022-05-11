#pragma once

#include <string>
#include <vector>

namespace Domain::PostingManager
{
    
    class JobPosting
    {
        public:
            JobPosting * (std::string jobexperience);

            //Operations
            //To Do: create methods/functions
            
        
        protected:
            std::string jobTitle;
            std::string jobExperience;
            std::string jobType;
            std::string deadline;
            std::string location;
            int salary;
             
            //Copy assignment operators, protected to prevent mix derived-type assignments
            JobPosting & operator=( const JobPosting & rhs ) = default; // copy assignment
            JobPosting & operator=(       JobPosting && rhs) = default; // move assignment

            //TODO: create class attributes 


        
    };

    /*****************************************************************************
    ** Inline implementations
    ******************************************************************************/
    inline JobPosting::~JobPosting(){}













}