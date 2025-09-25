## Description

Unmaps a previously mapped reserved logical range. Unlike [**IOMMU_UNMAP_LOGICAL_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_logical_range), this is guaranteed not to delete any page table resources so that the logical address range can be reused without performing any memory allocations.

## Parameters

### `MappedSegment` [in, out]

The [**IOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token_mapped_segment) to be unmapped.

## Return value

**STATUS_SUCCESS** if the operation is successful.

**STATUS_INVALID_PARAMETER** if the mapped segment provided was not mapped.

## Remarks

## See also

[IOMMU_MAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range)

[IOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token_mapped_segment)