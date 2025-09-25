# _DOMAIN_CONFIGURATION structure

## Description

Contains information required to configure a domain. This structure is used by the [_IOMMU_DOMAIN_CONFIGURE_](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_configure) callback function.

## Members

### `Type`

A [**DOMAIN_CONFIGURATION_ARCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_domain_configuration_arch)-type value that indicates the domain architecture.

### `Arm64`

A [**DOMAIN_CONFIGURATION_ARM64**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_domain_configuration_arm64) structure that contains the domain configuration information for an ARM64 system.

### `X64`

A [**DOMAIN_CONFIGURATION_X64**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-domain_configuration_x64) structure that contains the domain configuration information for an X64 system. Reserved for system use only.

## Remarks

The X64 configurations are reserved for system use only. Calling [IommuDomainConfigure](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_configure) with this configuration will result in a return of STATUS_NOT_SUPPORTED.

## See also

[IOMMU_DOMAIN_CONFIGURE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_configure)