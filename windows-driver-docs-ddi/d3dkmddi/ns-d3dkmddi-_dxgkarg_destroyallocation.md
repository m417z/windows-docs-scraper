# _DXGKARG_DESTROYALLOCATION structure

## Description

The DXGKARG_DESTROYALLOCATION structure describes how the display miniport driver should release allocations.

## Members

### `NumAllocations` [in]

The number of elements in the array that **pAllocationList** specifies, which represents the number of allocations to release.

### `pAllocationList` [in]

An array of handles to the allocations to release.

### `hResource` [in/out]

A handle to a resource. The display miniport driver cleans up this handle if it must release the resource along with the allocations.

### `Flags` [in]

A [DXGK_DESTROYALLOCATIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_destroyallocationflags) structure that identifies how to release the allocations.

## Remarks

The handles in the array that the **pAllocationList** member specifies are handles to allocations that the driver's [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) function previously returned in the **hAllocation** members of [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structures, which are part of the [DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation) structure's **pAllocationInfo** member. Each allocation handle points to a buffer that contains private driver data for the allocation. The display miniport driver must release the memory for the allocations during the call to [DxgkDdiDestroyAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyallocation).

## See also

[DXGKARG_CREATEALLOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_createallocation)

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DXGK_DESTROYALLOCATIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_destroyallocationflags)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)

[DxgkDdiDestroyAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_destroyallocation)