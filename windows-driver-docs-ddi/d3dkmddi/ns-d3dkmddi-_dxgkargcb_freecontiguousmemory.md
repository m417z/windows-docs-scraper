# DXGKARGCB_FREECONTIGUOUSMEMORY structure

## Description

The **DXGKARGCB_FREECONTIGUOUSMEMORY** structure contains the arguments used in the [**DXGKCB_FREECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freecontiguousmemory) callback function, to free the contiguous memory.

## Members

### `hMemoryHandle` [in]

A *Dxgkrnl* tracking handle for the memory allocation. *Dxgkrnl* returns this handle from [**DXGKCB_ALLOCATECONTIGUOUSMEMORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatecontiguousmemory)

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[DXGKCB_FREECONTIGUOUSMEMORY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freecontiguousmemory)