
#pragma once

#include <AzCore/Component/Component.h>

#include <plainTesting/plainTestingBus.h>

namespace plainTesting
{
    class plainTestingSystemComponent
        : public AZ::Component
        , protected plainTestingRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(plainTestingSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        plainTestingSystemComponent();
        ~plainTestingSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // plainTestingRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
