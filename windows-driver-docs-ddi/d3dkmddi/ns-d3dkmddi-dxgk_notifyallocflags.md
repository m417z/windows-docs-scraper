## Description

The **DXGK_NOTIFYALLOCFLAGS** structure specifies flags related to allocation notifications for paging operations.

## Members

### `Eviction`

The allocation is about to be evicted.

### `IoMmuUnmap`

The allocation is about to be unmapped from the IOMMU.

### `Reserved`

Reserved for future use; set to zero.

### `Value`

Union member that allows access to all flags in the structure.

## Remarks

The **Eviction** and **IoMmuUnmap** flags can't be set together.

A kernel-mode driver (KMD) *Dxgkrnl* uses these flags to notify the kernel-mode driver (KMD) that specific actions before an allocation is either evicted or unmapped from the IOMMU.

For more information, see [Allocation Notification](https://learn.microsoft.com/windows-hardware/drivers/display/allocation-notification).

## See also

[**DXGK_BUILDPAGINGBUFFER_NOTIFYALLOC**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_buildpagingbuffer_notifyalloc)

[**DxgkDdiCreateAllocation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)