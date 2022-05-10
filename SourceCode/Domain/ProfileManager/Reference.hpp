#pragma once

#include "Domain/ProfileManager/Profile.hpp"
#include <string>

namespace Domain::ProfileManager
{
  class Reference : public Domain::ProfileManager::ProfileManagerHandler
  {
    public:
      // Constructors
      

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