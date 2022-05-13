#pragma once

#include "Domain/ProfileManager/Profile.hpp"
#include <string>

namespace Domain::ProfileManager
{
  class Reference : public Domain::ProfileManager::ProfileManagerHandler
  {
    public:
      // TODO: Constructors
      

      // TODO: Operations
      

     ~Reference() noexcept override;

     protected:
     //TODO: Attributes
      std::string name;
     

     
  }; 


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline Reference::~Reference() noexcept
  {}


}  