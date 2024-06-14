
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "plainTestingSystemComponent.h"

#include <plainTesting/plainTestingTypeIds.h>

namespace plainTesting
{
    class plainTestingModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(plainTestingModule, plainTestingModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(plainTestingModule, AZ::SystemAllocator);

        plainTestingModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                plainTestingSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<plainTestingSystemComponent>(),
            };
        }
    };
}// namespace plainTesting

AZ_DECLARE_MODULE_CLASS(Gem_plainTesting, plainTesting::plainTestingModule)
