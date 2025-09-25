# DXGKCB_PINFRAMEBUFFERFORSAVE callback function

## Description

A kernel-mode display miniport driver calls **DXGKCB_PINFRAMEBUFFERFORSAVE** to pin down the entire frame buffer at once.

## Parameters

### `hAdapter` [in]

A handle to a display adapter. The driver provides this handle for the master/lead device in the linked display adapter (LDA) chain.

### `pPinFrameBufferForSave` [in/out]

Pointer to a [**DXGKARGCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave) structure that contains information about the frame buffer to save.

## Return value

**DXGKCB_PINFRAMEBUFFERFORSAVE** returns STATUS_SUCCESS if the operation succeeds. Otherwise, it returns an appropriate NTSTATUS error code.

## Remarks

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave) and then call **DxgkCbPinFrameBufferForSave** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

See [IOMMU-based GPU isolation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) for more information.

## See also

[**DXGKARGCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave)

[**DXGKCB_UNPINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unpinframebufferforsave)

[**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface)