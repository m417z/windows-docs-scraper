## Description

Maps a reserved logical range.

Unlike [**IOMMU_MAP_LOGICAL_RANGE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range_ex), this is guaranteed not to perform any memory allocations as they are assumed to have already been performed earlier with [**IOMMU_RESERVE_LOGICAL_ADDRESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_reserve_logical_address_range).

## Parameters

### `LogicalAddressToken` [in, out]

The [**IOMMU_DMA_LOGICAL_ADDRESS_TOKEN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token) to be mapped to.

### `Offset` [in]

The offset, in bytes, into the logical address token, representing the base logical address to be mapped.

### `Permissions` [in]

A bit-field representing the permissions to be set for the range being mapped. See Remarks for the available permission bits.

### `PhysicalAddressToMap` [in]

The [**IOMMU_MAP_PHYSICAL_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address) that will be mapped to the domain.

### `MappedSegment` [out]

Returns the [**IOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token_mapped_segment) representing a segment of the logical address token that is now mapped.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return code | Description |
|--|--|
| STATUS_INVALID_PARAMETER_2 | The offset provided is not page aligned. |
| STATUS_INVALID_PARAMETER_4 | The physical address provided is not page aligned and/or is not a whole number of pages in size. |
| STATUS_RESOURCE_IN_USE | The logical address range represented in the logical address token is already completely or partially mapped. |
| STATUS_UNSUCCESSFUL | The logical address token is currently being deleted. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

A logical address token mapped segment can be unmapped via [**IOMMU_UNMAP_RESERVED_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range).

The permissions field is a bitfield that describes the access permissions for the pages to be mapped.

The bits are defined as follows:

`Bit 0 = Read Access`

`Bit 1 = Write Access`

`Bits 31-2 = Reserved (0)`

## See also

[IOMMU_UNMAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range)

[IOMMU_MAP_PHYSICAL_ADDRESS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_map_physical_address)

[IOMMU_DMA_LOGICAL_ADDRESS_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token)

[IOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token_mapped_segment)