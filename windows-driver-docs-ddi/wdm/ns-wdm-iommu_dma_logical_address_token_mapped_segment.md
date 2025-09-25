## Description

The **IOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT** represents a mapped portion of an [**IOMMU_DMA_LOGICAL_ADDRESS_TOKEN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token).

## Members

### `OwningToken`

Provides a pointer to the logical address token that this mapped segment belongs to.

### `Offset`

The offset, in bytes, into the logical address token of the mapped region.

### `Size`

The size, in bytes, of the mapped region within the logical address token.

## Remarks

A **IOMMU_DMA_LOGICAL_ADDRESS_TOKEN_MAPPED_SEGMENT** is initialized when calling [IOMMU_MAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range) on an [IOMMU_DMA_LOGICAL_ADDRESS_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token). It is invalidated when calling [IOMMU_UNMAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range).

A segment must represent a 4KB page aligned range within an [IOMMU_DMA_LOGICAL_ADDRESS_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token).

It is possible to map multiple segments within an [IOMMU_DMA_LOGICAL_ADDRESS_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token) as long as the segments are not overlapping each other.

## See also

[IOMMU_DMA_LOGICAL_ADDRESS_TOKEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_address_token)

[IOMMU_MAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_reserved_logical_range)

[IOMMU_UNMAP_RESERVED_LOGICAL_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_unmap_reserved_logical_range)