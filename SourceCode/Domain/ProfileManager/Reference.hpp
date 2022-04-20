#pragma once

#include "Domain/ProfileManager/ProfileManagerHandler.hpp"
#include <string>

namespace Domain::ProfileManager
{
  class Reference : public Domain::ProfileManager::ProfileManagerHandler
  {
    public:
      // Constructors
      using ProfileManagerHandler::ProfileManagerHandler;  // inherit constructors

      // Operations
      

     ~Reference() noexcept override;

     protected:
      std::string name;
     

     
  }; 


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Reference::~Reference() noexcept
  {}


}  