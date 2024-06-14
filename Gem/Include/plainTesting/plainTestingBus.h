
#pragma once

#include <plainTesting/plainTestingTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace plainTesting
{
    class plainTestingRequests
    {
    public:
        AZ_RTTI(plainTestingRequests, plainTestingRequestsTypeId);
        virtual ~plainTestingRequests() = default;
        // Put your public methods here
    };

    class plainTestingBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using plainTestingRequestBus = AZ::EBus<plainTestingRequests, plainTestingBusTraits>;
    using plainTestingInterface = AZ::Interface<plainTestingRequests>;

} // namespace plainTesting
