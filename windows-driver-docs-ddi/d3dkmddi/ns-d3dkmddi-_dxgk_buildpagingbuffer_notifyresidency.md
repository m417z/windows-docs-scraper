# _DXGK_BUILDPAGINGBUFFER_NOTIFYRESIDENCY structure

## Description

 **DXGK_BUILDPAGINGBUFFER_NOTIFYRESIDENCY** describes a residency allocation change operation.

## Members

### `hAllocation`

The kernel mode driver handle returned from [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation).

### `PhysicalAddress`

The physical address of the allocation. The physical address (0, 0) is invalid and is used when the allocation is being evicted.

### `Resident`

Set to 0 when the allocation is evicted and set to 1 when the allocation is committed.

### `Reserved`

This member is not used and should be set to zero.

## Remarks

The paging operations is issued only for allocations, for which the kernel mode driver sets the [DXGK_ALLOCATIONINFOFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfoflags)::**ExplicitResidencyNotification** and **AccessedPhysically** flags.

The operation is issued after *FillVirtual* or *TransferVirtual* operations when the allocation is committed to a memory segment (**Resident** == 1). Note that the previous paging operations might not yet be finished by graphics processing unit (GPU).

The operation is issued before *TransferVirtual* operation when the allocation is evicted (**Resident** == 0) from a memory segment.

Note that the *NotifyResidency* operation will be issued only once during allocation eviction/commitment, while there might be several *TransferVirtual*/*FillVirtual* operations for a single allocation.

## See also

[DXGKARG_BUILDPAGINGBUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_buildpagingbuffer)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)