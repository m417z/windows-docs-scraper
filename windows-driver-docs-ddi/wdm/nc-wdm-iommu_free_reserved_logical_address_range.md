## Description

Frees a logical address token created by [**IOMMU_RESERVE_LOGICAL_ADDRESS_RANGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_reserve_logical_address_range).

## Parameters

### `LogicalAddressToken` [in]

The [**IOMMU_DMA_LOGICAL_ADDRESS_TOKEN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token), representing the reserved logical address range, to be freed.

## Return value

**STATUS_SUCCESS** if the operation is successful.

**STATUS_RESOURCE_IN_USE** if the logical address range is currently mapped or partially mapped.

## Remarks

Before deleting an **IOMMU_DMA_DOMAIN**, all associated logical address tokens must be freed.

## See also

[IOMMU_DMA_LOGICAL_ADDRESS_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token)

[IOMMU_RESERVE_LOGICAL_ADDRESS_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_reserve_logical_address_range)

[IOMMU_MAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range)

[IOMMU_UNMAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range)