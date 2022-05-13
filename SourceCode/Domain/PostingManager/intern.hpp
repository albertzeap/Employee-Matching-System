#pragma once

#include <string>
#include <vector>

namespace Domain::PostingManager
{
    
    class InternJobPosting //: public Domain::PostingManager::PostingHandler
    {
        public:
           
            // std::string getExperience() const override
            // {
            //     std::string experience = "Intern";
            //     return experience;
            // }

            //Operations
            //To Do: create methods/functions
            
        
        protected:
            std::string jobTitle;
            std::string jobExperience;
            std::string jobType;
            std::string deadline;
            std::string location;
            int salary;
             
           
        
    };

    /*****************************************************************************
    ** Inline implementations
    ******************************************************************************/
    inline InternJobPosting::~InternJobPosting(){}













}