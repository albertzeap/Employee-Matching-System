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
      using ProfileManagerHandler::ProfileManagerHandler;  // inherit constructors

      // Operations
      

     ~ProfileHandler() noexcept override;

     protected:
      
  }; // class Profile


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline ProfileHandler::~ProfileHandler() noexcept
  {}


}  