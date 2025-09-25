## Description

Configures a domain for use. All DMA blocked until the domain is configured.

## Parameters

### `Domain` [_In_]

A pointer to the handle to the domain.

### `Configuration` [_In_]

A pointer to a [**DOMAIN_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_domain_configuration) structure that contains the new configuration for the domain.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS values error code. For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

If the domain being configured is OS managed (via [**IOMMU_DOMAIN_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create)) or is not of type DomainTypeUnmanaged (via [IOMMU_DOMAIN_CREATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex)) then it cannot be configured and the function will return STATUS_INVALID_PARAMETER_1

## See also

[**IOMMU_DOMAIN_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create)

[**IOMMU_DOMAIN_CREATE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex)

[**DOMAIN_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_domain_configuration)