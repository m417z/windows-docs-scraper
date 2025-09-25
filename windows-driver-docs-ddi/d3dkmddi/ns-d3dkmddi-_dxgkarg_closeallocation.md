# _DXGKARG_CLOSEALLOCATION structure

## Description

The DXGKARG_CLOSEALLOCATION structure describes allocations that the display miniport driver should close.

## Members

### `NumAllocations` [in]

The number of elements in the array that **pOpenHandleList** specifies.

### `pOpenHandleList` [in]

An array of handles to device-specific allocations to close.

## See also

[DxgkDdiCloseAllocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_closeallocation)