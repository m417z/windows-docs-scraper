## Description

The **IOMMU_DMA_LOGICAL_ADDRESS_TOKEN** represents a reserved contiguous logical address range created by [IOMMU_RESERVE_LOGICAL_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_reserve_logical_address_range). Logical address tokens guarantee that the logical address represented has all of its associated page tables allocated ahead of time, ensuring that future mappings to this region will not fail due to low memory conditions.

## Members

### `LogicalAddressBase`

Represents the base address of the logical address range.

### `Size`

Represents the size, in bytes, of the logical address range.

## Remarks

Logical Address tokens can be created and freed via [IOMMU_RESERVE_LOGICAL_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_reserve_logical_address_range) and [IOMMU_FREE_RESERVED_LOGICAL_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_free_reserved_logical_address_range).

Logical Address tokens should have portions of their logical address ranges mapped to and unmapped from physical addresses via [IOMMU_MAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range) and [IOMMU_UNMAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range).

## See also

[IOMMU_RESERVE_LOGICAL_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_reserve_logical_address_range)

[IOMMU_FREE_RESERVED_LOGICAL_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_free_reserved_logical_address_range)

[IOMMU_MAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range)

[IOMMU_UNMAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range)

[IOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token_mapped_segment)