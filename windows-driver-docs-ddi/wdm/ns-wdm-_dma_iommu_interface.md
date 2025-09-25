## Description

An extended version of the **INTERFACE** structure that allows device drivers to invoke the callback functions that perform device domain operations.

> [!CAUTION]
> `DMA_IOMMU_INTERFACE` has been deprecated in Windows 10, version 2103 and has been replaced by [**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex).

## Members

### `Version`

The driver-defined interface version.

### `CreateDomain`

A pointer to the [**IOMMU_DOMAIN_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create) callback function that creates a DMA remapping device domain.

### `DeleteDomain`

A pointer to the [**IOMMU_DOMAIN_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_delete) callback function that deletes a device domain.

### `AttachDevice`

A pointer to the [**IOMMU_DOMAIN_ATTACH_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device) callback function that attaches a device to a domain.

### `DetachDevice`

A pointer to the [**IOMMU_DOMAIN_DETACH_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device) callback function that detaches a device from a domain.

### `ConfigureDomain`

A pointer to the [**IOMMU_DOMAIN_CONFIGURE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_configure) callback function that configures a domain for use.

### `FlushDomain`

A pointer to the [**IOMMU_FLUSH_DOMAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_flush_domain) callback function that flushes the TLB for all entries which match this domain.

### `FlushDomainByVaList`

A pointer to the [**IOMMU_FLUSH_DOMAIN_VA_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_flush_domain_va_list) callback function that flushes the TLB for all entries that match the specified domain's ASID and one of the addresses in the provided list.

### `QueryInputMappings`

A pointer to the [**IOMMU_QUERY_INPUT_MAPPINGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_query_input_mappings) callback function that attempts to find input mapping IDs which are valid for the given device and populate the provided buffer with those IDs.

### `MapLogicalRange`

A pointer to the [**IOMMU_MAP_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range) callback function that maps a range of pages into the address space of the specified domain.

### `UnmapLogicalRange`

A pointer to the [**IOMMU_UNMAP_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_logical_range) callback function that unmaps a range of pages.

### `MapIdentityRange`

A pointer to the [**IOMMU_MAP_IDENTITY_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range) callback function that creates an identity mapping for the provided MDL in the specified domain.

### `UnmapIdentityRange`

A pointer to the [**IOMMU_UNMAP_IDENTITY_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_identity_range) callback function that deletes an identity mapping.

### `SetDeviceFaultReporting`

A pointer to the [**IOMMU_SET_DEVICE_FAULT_REPORTING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_set_device_fault_reporting) callback function that sets the device fault reporting state to device already attached to a domain.

## Remarks

## See also