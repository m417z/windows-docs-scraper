# DXGKCB_MAPFRAMEBUFFERPOINTER callback function

## Description

**DXGKCB_MAPFRAMEBUFFERPOINTER** obtains a pointer to a subregion of the section object that was created for each physical adapter.

## Parameters

### `hAdapter` [in]

A handle to a display adapter. The driver provides this handle for the master/lead device in the LDA chain.

### `pMapFrameBufferPointer` [in/out]

Pointer to [**DXGKARGCB_MAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_mapframebufferpointer) structure that contains a pointer to the subregion of the section object.

## Return value

**DXGKCB_MAPFRAMEBUFFERPOINTER** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_MAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_mapframebufferpointer) and then call **DxgkCbMapFrameBufferPointer** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKCB_UNMAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unmapframebufferpointer)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)