## Description

Preallocates logical address space that can be used for future mappings. This grants a driver the ability to ensure forward progress for future map/unmap calls.

## Parameters

### `Domain` [in]

A pointer to the **IOMMU_DMA_DOMAIN** that the reserved logical address will belong to. The domain must be of type *DomainTypeTranslate*. For more information about domain types, see [IOMMU_DMA_DOMAIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_domain_type).

### `Size` [in]

The size, in bytes, of the logical address range to reserve. This value must represent a whole number of pages.

### `ExplicitLogicalAddress` [in, optional]

The domain logical address that should be reserved. If the domain was not created with a registered logical allocator, then this field is required. If the domain was created with a registered logical allocator that does not support explicit logical address allocation, then this field must be *NULL*.

### `MinLogicalAddress` [in, optional]

The minimum (inclusive) allowable logical address that can be reserved. If the domain was not created with a registered logical allocator, then this field will be ignored.

### `MaxLogicalAddress` [in, optional]

The maximum (inclusive) allowable logical address that can be reserved. If the domain was not created with a registered logical allocator, then this field will be ignored.

### `LogicalAddressToken` [out]

Returns a [**IOMMU_DMA_LOGICAL_ADDRESS_TOKEN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token) representing the reserved logical address range.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| STATUS_INVALID_PARAMETER_1 | The domain provided is not of type *DomainTypeTranslate*. |
| STATUS_INVALID_PARAMETER_2 | The size provided is not a multiple of PAGE_SIZE. |
| STATUS_INVALID_PARAMETER_3 | The ExplicitLogicalAddress provided is not page-aligned. |
| STATUS_INVALID_PARAMETER_MIX | The min and max logical addresses provided could not be satisfied. |
| STATUS_IN_USE | The ExplicitLogicalAddress is already mapped or partially mapped. |
| STATUS_NOT_SUPPORTED | An ExplicitLogicalAddress was provided for a domain with a logical allocator that does not allow explicit logical address allocation. Or an ExplicitLogicalAddress was not provided for a domain with no logical allocator. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

Logical Address tokens can be freed via [IOMMU_FREE_RESERVED_LOGICAL_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_free_reserved_logical_address_range).

Logical Address tokens should have portions of their logical address ranges mapped to and unmapped from physical addresses via [IOMMU_MAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range) and [IOMMU_UNMAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range).

## See also

[IOMMU_DMA_LOGICAL_ADDRESS_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token)

[IOMMU_FREE_RESERVED_LOGICAL_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_free_reserved_logical_address_range)

[IOMMU_MAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range)

[IOMMU_UNMAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range)