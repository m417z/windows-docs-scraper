## Description

The **IOMMU_DMA_LOGICAL_ALLOCATOR_CONFIG** structure contains information required to configure a logical allocator.

This structure is used by [*IOMMU_DOMAIN_CREATE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex) to create a logical allocator attached to the created [**IOMMU_DMA_DOMAIN**].

## Members

### `LogicalAllocatorType`

An [**IOMMU_DMA_LOGICAL_ALLOCATOR_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_logical_allocator_type) value that indicates the type of logical allocator to be created.

### `BuddyAllocatorConfig`

Provides configuration information specific to the HAL Buddy Allocator.

### `BuddyAllocatorConfig.AddressWidth`

Provides the address width for the allocator to be created. 32-bit operating systems are limited to a width of 32 bits, while 64-bit operating systems are limited to a width of 63 bits. When creating a domain, the address width should correspond to the maximum address width for the device(s) expected to be attached.

## Remarks

With [*IOMMU_DOMAIN_CREATE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex), a caller may opt to attach a logical allocator to the domain being created.

When interacting with such a domain, a caller does not need to keep track of previous mappings. Instead, the logical allocator takes responsibility for determining the logical address to be used when mapping physical pages to the owning domain. The logical allocator is also responsible for maintaining state to ensure that logical address collisions do not occur.

Currently the only logical allocator type available is the Buddy Allocator. This allocator favors low logical addresses and will allocate logical addresses on power of two boundaries at or above 4KB. The allocator is also augmented with a cache of free logical address values to improve the performance of free address lookup.

The Buddy Allocator does not allow for explicit address allocation. Calling [*IOMMU_MAP_IDENTITY_RANGE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_identity_range_ex) or [*IOMMU_MAP_LOGICAL_RANGE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_map_logical_range_ex) with an explicit address provided on an [*IOMMU_DMA_DOMAIN** created with a BuddyAllocator will fail.

## See also

[IOMMU_DOMAIN_CREATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex)

[IOMMU_DMA_LOGICAL_ALLOCATOR_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-iommu_dma_logical_allocator_type)