# DXGKCB_UNPINFRAMEBUFFERFORSAVE callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_UNPINFRAMEBUFFERFORSAVE** to release the mapping that was set in a prior call to [**DXGKCB_PINFRAMEBUFFERFORSAVE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave2) or [**DXGKCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave).

## Parameters

### `hAdapter` [in]

A handle to a display adapter. The driver provides this handle for the master/lead device in the LDA chain.

### `pUnpinFrameBufferForSave` [in]

A pointer to the [**DXGKARGCB_UNPINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkargcb_unpinframebufferforsave) structure that contains a handle to the memory to be unmapped.

## Return value

**DXGKCB_UNPINFRAMEBUFFERFORSAVE** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the members of [**DXGKARGCB_UNPINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unpinframebufferforsave) and then call **DxgkCbUnpinFrameBufferForSave** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_UNPINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unpinframebufferforsave)

[**DXGKCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave)

[**DXGKCB_PINFRAMEBUFFERFORSAVE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave2)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)