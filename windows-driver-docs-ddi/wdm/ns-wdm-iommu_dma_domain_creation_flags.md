## Description

The **IOMMU_DMA_DOMAIN_CREATION_FLAGS** structure defines configuration flags for a domain being created by [**IOMMU_DOMAIN_CREATE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex).

## Members

### `Reserved`

All flags are currently reserved. This field must be zero.

### `AsUlonglong`

Represents all flags as a single **ULONGLONG**.

## Remarks

Currently the flags are unused and must be all zero when passed in to [**IOMMU_DOMAIN_CREATE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex).

## See also

[**IOMMU_DOMAIN_CREATE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_create_ex)