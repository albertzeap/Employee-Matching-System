#pragma once

#include <fstream>
#include <vector>
#include <memory>

namespace Domain::ProfileManager
{
    // Profile Manager Package within the Domain Layer Abstract class
    class ProfileManagerHandler
    {
        public:
           
            // JOB OPERATIONS

            // User applies to a job by adding their profile object. 
            // Profile object should include their first name, last name, job field, resume, and references.
            virtual bool applyForJob(std::string profileID) = 0; 

            // PROFILE OPERATIONS

            // User is able to create a profile using their full name and their role (i.e. jobseeker, career specialist, recruiter, IT support) 
            virtual std::string createProfile(std::string name, std::string role)  = 0;
            // Lets the user delete the profile by passing in their profile object. 
            virtual bool    deleteProfile(std::string * profileID               )  = 0;

            // RESUME OPERATIONS

            // User obtains a list of resumes
            virtual std::vector<std::string> requestResumes();
            // User uploads their resume into the system as a file. Returns true if successful, false if not. Only for jobseeker. 
            virtual bool uploadResume(std::string filename) = 0;
            // User deletes their resume. Only for jobseeker. 
            virtual bool deleteResume(std::string filename) = 0;
            
            // RESUME FEEDBACK OPERATIONS

            // User is able to submit their resume file to received feedback from a career specialist. 
            // The feedback should be in the form of a text file. Only for jobseeker. 
            virtual bool getFeedback (std::string filename) = 0; 
            // User is able to view the feedback they received in the form of a text file. Only for jobseeker. 
            virtual bool viewFeedback(std::string filename) = 0; 
            // This function should only be available to the career specialist. It lets them send the text file after receiving the resume to evaluate as a parameter. 
            virtual bool sendFeedback(std::string filename) = 0; 

            // REFERENCE OPERATIONS

            // User is able to add a reference to their account by passing in the name, workplace, role, and relation. Should be for jobseeker only. 
            virtual bool addReference   (std::string name) = 0; 
            // User is able to delete a reference from their profile by passing in a reference object. Should be for jobseeker only. 
            virtual bool deleteReference(std::string * referenceID) = 0; 

            // Factory pattern function within class 
            static std::unique_ptr<ProfileManagerHandler> createProfileHandler();
            
            
            //Destructor
            virtual ~ProfileManagerHandler() noexcept = 0;
        
        protected:
            //Copy assignment operators, protected to prevent mix derived-type assignments
            ProfileManagerHandler & operator=( const ProfileManagerHandler & rhs ) = default; // copy assignment
            ProfileManagerHandler & operator=(       ProfileManagerHandler && rhs) = default; // move assignment


        
    };

    /*****************************************************************************
    ** Inline implementations
    ******************************************************************************/
    inline ProfileManagerHandler::~ProfileManagerHandler() noexcept = default;













}