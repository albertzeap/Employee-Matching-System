#pragma once

#include "Domain/ProfileManager/ProfileManagerHandler.hpp"
#include "Domain/ProfileManager/Profile.hpp"

#include <string>

namespace Domain::ProfileManager
{
  class ProfileHandler : public Domain::ProfileManager::ProfileManagerHandler
  {
    public:
        // Constructors
        // using ProfileManagerHandler::ProfileManagerHandler;  // inherit constructors
        ProfileHandler();

        // JOB OPERATIONS

        // User applies to a job by adding their profile object. 
        // Profile object should include their first name, last name, job field, resume, and references.
        bool applyForJob(std::string profileID) override; 

        // PROFILE OPERATIONS

        // User is able to create a profile using their full name and their role (i.e. jobseeker, career specialist, recruiter, IT support) 
        std::string createProfile(std::string name, std::string role)  override;
        // Lets the user delete the profile by passing in their profile object. 
        bool    deleteProfile(std::string * profileID               )  override;

        // RESUME OPERATIONS

        // User obtains a list of resumes
        std::vector<std::string> requestResumes() override;
        // User uploads their resume into the system as a file. Returns true if successful, false if not. Only for jobseeker. 
        bool uploadResume(std::string filename)   override;
        // User deletes their resume. Only for jobseeker. 
        bool deleteResume(std::string filename)   override;

        // RESUME FEEDBACK OPERATIONS

        // User is able to submit their resume file to received feedback from a career specialist. 
        // The feedback should be in the form of a text file. Only for jobseeker. 
        bool getFeedback (std::string filename) override; 
        // User is able to view the feedback they received in the form of a text file. Only for jobseeker. 
        bool viewFeedback(std::string filename) override; 
        // This function should only be available to the career specialist. It lets them send the text file after receiving the resume to evaluate as a parameter. 
        bool sendFeedback(std::string filename) override; 

        // REFERENCE OPERATIONS

        // User is able to add a reference to their account by passing in the name, workplace, role, and relation. Should be for jobseeker only. 
        bool addReference   (std::string name         ) override; 
        // User is able to delete a reference from their profile by passing in a reference object. Should be for jobseeker only. 
        bool deleteReference(std::string * referenceID) override; 

        ~ProfileHandler() noexcept override = 0;

     protected:
      
  }; // class Profile


  


}  



