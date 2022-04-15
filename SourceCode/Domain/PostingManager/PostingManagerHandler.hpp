#pragma once

#include <string>
#include <vector>

namespace Domain::PostingManager
{
    // Profile Manager Package within the Domain Layer Abstract class
    class PostingManagerHandler
    {
        public:
            //Operations
            //To Do: Create Job class
            virtual Job createJobPost(std::string jobTitle, int salary,           std::string jobExperience,
                                      std::string jobType , std::string deadline, std::string location     ,
                                      int jobID                                                            ) = 0;
            virtual bool deleteJobPost(Job * job) = 0;
            virtual std::vector<Job> filterJob(std::string filter) = 0; 
              

            //Destructor
            virtual ~PostingManagerHandler() noexcept = 0;
        
        protected:
            //Copy assignment operators, protected to prevent mix derived-type assignments
            PostingManagerHandler & operator=( const PostingManagerHandler & rhs ) = default; // copy assignment
            PostingManagerHandler & operator=( const PostingManagerHandler && rhs) = default; // move assignment


        
    };

    /*****************************************************************************
    ** Inline implementations
    ******************************************************************************/
    inline PostingManagerHandler::~PostingManagerHandler() noexcept = default;













}