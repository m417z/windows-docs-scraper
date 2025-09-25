## Description

A structure containing the set of IOMMU Version 1 (V1) functions.

## Members

### `CreateDomain`

A pointer to the [**IOMMU_DOMAIN_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create) function that creates a DMA remapping device domain.

### `DeleteDomain`

A pointer to the [**IOMMU_DOMAIN_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_delete) function that deletes a device domain.

### `AttachDevice`

A pointer to the [**IOMMU_DOMAIN_ATTACH_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device) function that attaches a device to a domain.

### `DetachDevice`

A pointer to the [**IOMMU_DOMAIN_ATTACH_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device) function that detaches a device from a domain.

### `FlushDomain`

A pointer to the [**IOMMU_FLUSH_DOMAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_flush_domain) function that flushes the TLB for all entries which match this domain.

### `FlushDomainByVaList`

A pointer to the [**IOMMU_FLUSH_DOMAIN_VA_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_flush_domain_va_list) function that flushes the TLB for all entries that match the specified domain's ASID and one of the addresses in the provided list.

### `QueryInputMappings`

A pointer to the [**IOMMU_QUERY_INPUT_MAPPINGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_query_input_mappings) function that attempts to find input mapping IDs which are valid for the given device and populate the provided buffer with those IDs.

### `MapLogicalRange`

A pointer to the [**IOMMU_MAP_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range) function that maps a range of pages into the address space of the specified domain.

### `UnmapLogicalRange`

A pointer to the [**IOMMU_UNMAP_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_logical_range) function that unmaps a range of pages.

### `MapIdentityRange`

A pointer to the [**IOMMU_MAP_IDENTITY_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range) function that creates an identity mapping for the provided MDL in the specified domain.

### `UnmapIdentityRange`

A pointer to the [**IOMMU_UNMAP_IDENTITY_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_identity_range) function that deletes an identity mapping.

### `SetDeviceFaultReporting`

A pointer to the [**IOMMU_SET_DEVICE_FAULT_REPORTING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_set_device_fault_reporting) function that sets the device fault reporting state to device already attached to a domain.

### `ConfigureDomain`

A pointer to the [**IOMMU_DOMAIN_CONFIGURE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_configure) function that configures a domain for use.

## Remarks

These function pointers are the same as those provided by the deprecated [**DMA_IOMMU_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_dma_iommu_interface) structure. For V1 functions, use the [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex) structure over the deprecated one.

## See also

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)