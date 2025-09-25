# DXGKCB_FREECONTIGUOUSMEMORY callback function

## Description

**DXGKCB_FREECONTIGUOUSMEMORY** frees a range of physically contiguous memory that was allocated by [**DXGKCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatecontiguousmemory).

## Parameters

### `hAdapter` [in]

Handle to a display adapter.

### `pFreeContiguousMemory` [in]

Pointer to a [**DXGKARGCB_FREECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_freecontiguousmemory) structure that contains a handle to the contiguous memory to be freed.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate NTSTATUS error code.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_FREECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_freecontiguousmemory) and then call **DxgkCbFreeContiguousMemory** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_FREECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_freecontiguousmemory)

[**DXGKCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatecontiguousmemory)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)