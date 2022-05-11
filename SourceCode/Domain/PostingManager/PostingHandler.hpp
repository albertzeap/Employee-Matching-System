#pragma once

#include "Domain/PostingManager/PostingManagerHandler.hpp"
#include "Domain/PostingManager/JobPosting.hpp"

#include <string>

namespace Domain::PostingManager
{
  class PostingHandler : public Domain::PostingManager::PostingManagerHandler
  {
    public:


        int              createJobPost (std::string jobTitle, int salary,           std::string jobExperience,
                                        std::string jobType , std::string deadline, std::string location ) override;
        bool             deleteJobPost (int jobID         ) override;
        std::vector<int> filterJob     (std::string filter) override; 
        
       

    
      
  }; // class PostingHandler


  


}  



