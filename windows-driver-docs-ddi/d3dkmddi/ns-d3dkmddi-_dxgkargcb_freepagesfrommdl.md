# DXGKARGCB_FREEPAGESFROMMDL structure

## Description

The **DXGKARGCB_FREEPAGESFROMMDL** structure contains the arguments used in the [**DXGKCB_FREEPAGESFROMMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freepagesfrommdl) callback function, to free a memory descriptor list's (MDL) pages that were previously allocated by [**DXGKCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_allocatepagesformdl).

## Members

### `hMemoryHandle` [in]

A *Dxgkrnl* tracking handle for the memory allocation.

## Remarks

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[DXGKCB_FREEPAGESFROMMDL](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_freepagesfrommdl)