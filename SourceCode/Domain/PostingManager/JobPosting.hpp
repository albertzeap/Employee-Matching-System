#pragma once

#include "Domain/PostingManager/PostingHandler.hpp"

#include <string>
#include <vector>
#include <set>

namespace Domain::PostingManager
{
    
    class JobPosting : public Domain::PostingManager::PostingHandler
    {
        public:
            JobPosting();

            virtual std::vector<std::vector<std::string>>  getJobs( const std::vector<std::string> & args ) = 0;

            virtual ~JobPosting() noexcept;
        protected:
           
            //Copy assignment operators, protected to prevent mix derived-type assignments
            JobPosting & operator=( const JobPosting & rhs ) = default; // copy assignment
            JobPosting & operator=(       JobPosting && rhs) = default; // move assignment

           
        
    };

    inline JobPosting::~JobPosting() noexcept = default;


    









}