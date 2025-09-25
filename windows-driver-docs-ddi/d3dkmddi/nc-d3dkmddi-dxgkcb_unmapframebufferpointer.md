# DXGKCB_UNMAPFRAMEBUFFERPOINTER callback function

## Description

**DXGKCB_UNMAPFRAMEBUFFERPOINTER** releases the mapping that was set by [**DXGKCB_MAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapframebufferpointer).

## Parameters

### `hAdapter` [in]

A handle to a display adapter. The driver provides this handle for the master/lead device in the LDA chain.

### `pUnmapFrameBufferPointer` [in]

A pointer to the [**DXGKARGCB_UNMAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_unmapframebufferpointer) structure that contains a handle to the memory to be unmapped.

## Return value

**DXGKCB_UNMAPFRAMEBUFFERPOINTER** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_UNMAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_unmapframebufferpointer) and then call **DXGKCB_UNMAPFRAMEBUFFERPOINTER** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_UNMAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_unmapframebufferpointer)

[**DXGKCB_MAPFRAMEBUFFERPOINTER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_mapframebufferpointer)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)