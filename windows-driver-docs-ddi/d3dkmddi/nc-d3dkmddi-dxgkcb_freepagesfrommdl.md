# DXGKCB_FREEPAGESFROMMDL callback function

## Description

**DXGKCB_FREEPAGESFROMMDL** frees all the physical pages described by a memory descriptor list (MDL) and allocated by the [**DXGKCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatepagesformdl) routine.

## Parameters

### `hAdapter` [in]

Handle to a display adapter.

### `pFreePagesFromMdl` [in]

Pointer to a [**DXGKARGCB_FREEPAGESFROMMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_freepagesfrommdl) structure that contains a handle to the pages for the MDL.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS error code.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_FREEPAGESFROMMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_freepagesfrommdl) and then calls **DxgkCbFreePagesFromMdl** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_FREEPAGESFROMMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_freepagesfrommdl)

[**DXGKCB_ALLOCATEPAGESFORMDL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_allocatepagesformdl)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)