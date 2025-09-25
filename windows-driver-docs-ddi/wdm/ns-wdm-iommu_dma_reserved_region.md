## Description

The **IOMMU_DMA_RESERVED_REGION** structure describes a region of memory that needs to be marked as reserved during domain creation. This structure is used by [*IOMMU_DOMAIN_CREATE_EX*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex).

## Members

### `RegionNext`

Provides a pointer to the next reserved region.

### `Base`

Provides the base address of the region to be reserved. Must be page-aligned.

### `NumberOfPages`

Provides the number of pages to be reserved.

### `ShouldMap`

Provides whether the reserved region should be identity mapped. If not, the region will not be mapped into the domain's page table at all.

## Remarks

If the domain being created has a logical allocator, the logical address range will be marked as reserved within the logical allocator as well.

## See also

[IOMMU_DOMAIN_CREATE_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex)