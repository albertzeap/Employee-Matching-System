#pragma once

#include "Domain/ProfileManager/ProfileManagerHandler.hpp"

namespace Domain::ProfileManager
{
  class Profile : public Domain::ProfileManager::ProfileManagerHandler
  {
    public:
      // Constructors
      using ProfileManagerHandler::ProfileManagerHandler;  // inherit constructors

      // Operations

     ~Profile() noexcept override;
  }; // class Profile


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Profile::~Profile() noexcept
  {}


}  