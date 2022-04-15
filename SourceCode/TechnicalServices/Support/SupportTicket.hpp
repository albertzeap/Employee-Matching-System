#pragma once

#include "TechnicalServices/Support/SupportHandler.hpp"

namespace TechnicalServices::Support
{
  class SupportTicket : public TechnicalServices::Support::SupportHandler
  {
    public:
      // Constructors
      using SupportHandler::SupportHandler;  // inherit constructors

      // Operations

     ~SupportTicket() noexcept override;
  }; 


  /*****************************************************************************
  ** Inline implementations
  ******************************************************************************/
  inline SupportTicket::~SupportTicket() noexcept
  {}


}  // namespace Domain::Library
