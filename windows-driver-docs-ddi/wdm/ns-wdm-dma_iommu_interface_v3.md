## Description

The **DMA_IOMMU_INTERFACE_V3** structure contains the set of IOMMU Version 3 (V3) functions.

## Members

### `CreateDomainEx`

A pointer to the [**IOMMU_DOMAIN_CREATE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex) function that creates a DMA remapping device domain.

### `DeleteDomain`

A pointer to the [**IOMMU_DOMAIN_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_delete) function that deletes a device domain.

### `AttachDeviceEx`

A pointer to the [**IOMMU_DOMAIN_ATTACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_device_ex) function that attaches a device to a domain.

### `DetachDeviceEx`

A pointer to the [**IOMMU_DOMAIN_DETACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device_ex) function that detaches a device from a domain.

### `FlushDomain`

A pointer to the [**IOMMU_FLUSH_DOMAIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_flush_domain) function that flushes the TLB for all entries which match this domain.

### `FlushDomainByVaList`

A pointer to the [**IOMMU_FLUSH_DOMAIN_VA_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_flush_domain_va_list) function that flushes the TLB for all entries that match the specified domain's ASID and one of the addresses in the provided list.

### `QueryInputMappings`

A pointer to the [**IOMMU_QUERY_INPUT_MAPPINGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_query_input_mappings) function that attempts to find input mapping IDs which are valid for the given device and populate the provided buffer with those IDs.

### `MapLogicalRangeEx`

A pointer to the [**IOMMU_MAP_LOGICAL_RANGE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range_ex) function that maps a range of pages into the address space of the specified domain.

### `UnmapLogicalRange`

A pointer to the [**IOMMU_UNMAP_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_logical_range) function that unmaps a range of pages.

### `MapIdentityRangeEx`

A pointer to the [**IOMMU_MAP_IDENTITY_RANGE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range_ex) function that creates an identity mapping for the provided physical address in the provided domain.

### `UnmapIdentityRangeEx`

A pointer to the [**IOMMU_UNMAP_IDENTITY_RANGE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_identity_range_ex) function that deletes an identity mapping for the specified physical address.

### `SetDeviceFaultReportingEx`

A pointer to the [**IOMMU_SET_DEVICE_FAULT_REPORTING_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_set_device_fault_reporting_ex) function that sets the device fault reporting state on a device already attached to a domain.

### `ConfigureDomain`

A pointer to the [**IOMMU_DOMAIN_CONFIGURE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_configure) function that configures a domain for use.

### `QueryAvailableDomainTypes`

A pointer to the [**IOMMU_DEVICE_QUERY_DOMAIN_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_query_domain_types) function that queries for the available types of domains that a device is allowed to attach to, depending on environment factors, such as platform and the DMA Guard policy.

### `RegisterInterfaceStateChangeCallback`

A pointer to the [**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback) function that allows the caller to register a callback to be invoked whenever any state change related to the IOMMU interface occurs.

### `UnregisterInterfaceStateChangeCallback`

A pointer to the [**IOMMU_UNREGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unregister_interface_state_change_callback) function that allows the caller to deregister a registered callback.

### `ReserveLogicalAddressRange`

A pointer to the [**IOMMU_RESERVE_LOGICAL_ADDRESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_reserve_logical_address_range) function that preallocates logical address space that can be used for future mappings.

### `FreeReservedLogicalAddressRange`

A pointer to the [**IOMMU_FREE_RESERVED_LOGICAL_ADDRESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_free_reserved_logical_address_range) function that frees a logical address token.

### `MapReservedLogicalRange`

A pointer to the [**IOMMU_MAP_RESERVED_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range) function that maps a reserved logical range.

### `UnmapReservedLogicalRange`

A pointer to the [**IOMMU_UNMAP_RESERVED_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range) function that unmaps a previously mapped reserved logical range.

### `CreateDevice`

A pointer to the [**IOMMU_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_create) function that takes a physical device object and creates an **IOMMU_DMA_DEVICE**.

### `DeleteDevice`

A pointer to the [**IOMMU_DEVICE_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_delete) function that deletes an **IOMMU_DMA_DEVICE**.

### `CreatePasidDevice`

A pointer to the [**IOMMU_PASID_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_create) function that creates a new sub-device with its own PASID from an IOMMU DMA device.

### `DeletePasidDevice`

A pointer to the [**IOMMU_PASID_DEVICE_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_delete) function that deletes a PASID sub-device and frees its ASID.

### `AttachPasidDevice`

A pointer to the [**IOMMU_DOMAIN_ATTACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_pasid_device) function that attaches a PASID sub-device to an existing memory domain.

### `DetachPasidDevice`

A pointer to the [**IOMMU_DOMAIN_DETACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_pasid_device) function that detaches a PASID sub-device from the domain it is currently attached to.

### `QueryDeviceInfo`

A pointer to the [**IOMMU_DEVICE_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_query_information) function that queries information about an IOMMU DMA device.

## Remarks

This structure extends [**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2) with additional PASID (Process Address Space Identifier) support functions. The V3 interface includes all the functions from V2 plus new capabilities for creating and managing PASID sub-devices and querying device information.

## See also

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)

[**IOMMU_PASID_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_create)

[**IOMMU_PASID_DEVICE_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_delete)

[**IOMMU_DOMAIN_ATTACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_pasid_device)

[**IOMMU_DOMAIN_DETACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_pasid_device)

[**IOMMU_DEVICE_QUERY_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_query_information)