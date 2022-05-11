#include "Domain/ProfileManager/ProfileManagerHandler.hpp"
#include "Domain/ProfileManager/ProfileHandler.hpp"

#include <memory>    // unique_ptr


namespace Domain::ProfileManager
{
    ProfileManagerHandler::~ProfileManagerHandler() noexcept = default;

    std::unique_ptr<ProfileManagerHandler> ProfileManagerHandler::createProfileHandler()
    {
        return std::make_unique<ProfileManagerHandler>();

    }
}    // namespace Domain::ProfileHandler
