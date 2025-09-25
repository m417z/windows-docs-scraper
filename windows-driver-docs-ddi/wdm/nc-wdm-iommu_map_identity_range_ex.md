## Description

Creates an identity mapping for a provided physical address space in the provided domain.

## Parameters

### `Domain` [in]

A pointer to the **IOMMU_DMA_DOMAIN** that the identity mapped physical address will belong to. The domain must be of type *DomainTypeTranslate* or *DomainTypePassThrough*. For more information about domain types, see [IOMMU_DMA_DOMAIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type).

### `Permissions` [in]

A bit-field representing the permissions to be set for the range being mapped. See Remarks for the available permission bits.

### `PhysicalAddressToMap` [in]

The [**IOMMU_MAP_PHYSICAL_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address) that will be mapped to the domain.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| STATUS_INVALID_PARAMETER_1 | The domain provided is not of type *DomainTypeTranslate* or *DomainTypePassThrough*. |
| STATUS_INVALID_PARAMETER_3 | The [**IOMMU_MAP_PHYSICAL_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address) provided does not represent physical memory that is page-aligned and has a size that is a multiple of PAGE_SIZE. |
| STATUS_IN_USE | The identity range is already mapped or partially mapped. |
| STATUS_NOT_SUPPORTED | The provided domain contains a logical allocator that does not allow explicit logical address allocation. |

## Remarks

To unmap the logical address created by **IOMMU_MAP_IDENTITY_RANGE_EX**, use [*IOMMU_UNMAP_IDENTITY_RANGE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_identity_range_ex).

The permissions field is a bitfield that describes the access permissions for the pages to be mapped.

The bits are defined as follows:

`Bit 0 = Read Access`

`Bit 1 = Write Access`

`Bits 31-2 = Reserved (0)`

## See also

[**IOMMU_DMA_DOMAIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)

[**IOMMU_MAP_PHYSICAL_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address)