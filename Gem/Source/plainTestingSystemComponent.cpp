
#include <AzCore/Serialization/SerializeContext.h>

#include "plainTestingSystemComponent.h"

#include <plainTesting/plainTestingTypeIds.h>

namespace plainTesting
{
    AZ_COMPONENT_IMPL(plainTestingSystemComponent, "plainTestingSystemComponent",
        plainTestingSystemComponentTypeId);

    void plainTestingSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<plainTestingSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void plainTestingSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("plainTestingService"));
    }

    void plainTestingSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("plainTestingService"));
    }

    void plainTestingSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void plainTestingSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    plainTestingSystemComponent::plainTestingSystemComponent()
    {
        if (plainTestingInterface::Get() == nullptr)
        {
            plainTestingInterface::Register(this);
        }
    }

    plainTestingSystemComponent::~plainTestingSystemComponent()
    {
        if (plainTestingInterface::Get() == this)
        {
            plainTestingInterface::Unregister(this);
        }
    }

    void plainTestingSystemComponent::Init()
    {
    }

    void plainTestingSystemComponent::Activate()
    {
        plainTestingRequestBus::Handler::BusConnect();
    }

    void plainTestingSystemComponent::Deactivate()
    {
        plainTestingRequestBus::Handler::BusDisconnect();
    }
}
