# _DXGKARG_CREATEALLOCATION structure

## Description

The DXGKARG_CREATEALLOCATION structure describes how the display miniport driver should create allocations.

## Members

### `pPrivateDriverData` [in]

A pointer to a block of private data that is passed from the user-mode display driver to the display miniport driver. This member is typically used to provide data for a group of allocations. Note that this member is distinct from the **pPrivateDriverData** members of the [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structures in the array that **pAllocationInfo** specifies. You can set private data for this member in addition to private data for each allocation.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the private data that **pPrivateDriverData** points to.

### `NumAllocations` [in]

The number of elements in the array that **pAllocationInfo** specifies, which represents the number of allocations to create.

### `pAllocationInfo` [in/out]

An array of [DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo) structures that describe the allocations to create.

### `hResource` [in/out]

A handle to a resource. The display miniport driver can set this handle to a value that the Microsoft DirectX graphics kernel subsystem can subsequently pass in driver calls and that refers to information for the allocations. If the resource was already created by a previous [DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation) call, this member contains the handle that the driver previously returned.

### `Flags` [in]

A [DXGK_CREATEALLOCATIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createallocationflags) structure that identifies how to create allocations. Setting all of the bit-field flags to 0 indicates that allocations belong to the device and not to a particular resource.

## See also

[DXGK_ALLOCATIONINFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_allocationinfo)

[DXGK_CREATEALLOCATIONFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_createallocationflags)

[DxgkDdiCreateAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createallocation)