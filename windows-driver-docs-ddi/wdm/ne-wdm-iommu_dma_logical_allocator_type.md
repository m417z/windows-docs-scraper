## Description

The **IOMMU_DMA_LOGICAL_ALLOCATOR_TYPE** enum indicates the type of logical allocator described in an [**IOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_allocator_config) structure.

## Constants

### `IommuDmaLogicalAllocatorNone`

The logical allocator configuration does not describe any logical allocator type.

### `IommuDmaLogicalAllocatorBuddy`

The logical allocator configuration describes the system's Buddy Allocator.

### `IommuDmaLogicalAllocatorMax`

Invalid logical allocator type.

## Remarks

For more information about the different logical allocator types available, see the Remarks section of [**IOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_allocator_config).

## See also

[IOMMU_DOMAIN_CREATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex)

[IOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_logical_allocator_config)