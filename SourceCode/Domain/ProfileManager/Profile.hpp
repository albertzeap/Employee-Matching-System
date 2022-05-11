#pragma once

#include "Domain/ProfileManager/ProfileManagerHandler.hpp"
#include <string>

namespace Domain::ProfileManager
{
  class Profile : public Domain::ProfileManager::ProfileManagerHandler
  {
    public:
      // Constructors
      using ProfileManagerHandler::ProfileManagerHandler;  // inherit constructors

      // Operations
      

     ~Profile() noexcept override;

     protected:
      std::string firstName;
      std::string lastName;
      std::string jobField;

      // Resume and Reference class still needs to be implemented 
      // Resume resume;
      // References references;
      
  }; // class Profile


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Profile::~Profile() noexcept
  {}


}  


