//TODO: Create Resume class
#pragma once

#include "Domain/ProfileManager/ProfileManagerHandler.hpp"
#include <string>

namespace Domain::ProfileManager
{
  class Resume : public Domain::ProfileManager::ProfileManagerHandler
  {
    public:
      

      // Operations
      

     ~Resume() noexcept override;

     protected:
      std::string filename;

      
      
  }; // class Profile


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Resume::~Resume() noexcept
  {}


}  