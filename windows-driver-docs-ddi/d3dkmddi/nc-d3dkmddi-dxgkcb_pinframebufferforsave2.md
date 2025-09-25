## Description

A kernel-mode display miniport driver calls **DXGKCB_PINFRAMEBUFFERFORSAVE2** to pin an entire frame buffer at once.

## Parameters

### `hAdapter` [in]

A handle to a display adapter. The driver provides this handle for the main/lead device in the linked display adapter (LDA) chain.

### `pPinFrameBufferForSave2` [in/out]

Pointer to a [**DXGKARGCB_PINFRAMEBUFFERFORSAVE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_open_physical_memory_object) structure that contains information about the frame buffer to save.

## Return value

**DXGKCB_PINFRAMEBUFFERFORSAVE2** returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate NTSTATUS error code.

## Remarks

The original [WDDM 2.4 IOMMU implementation](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-based-gpu-isolation) included a pair of callback functions to query memory needed to save the frame buffer. The frame buffer save area was created as a section object during initialization, and the driver used these callbacks to obtain an IOMMU mapped region when needed.

Drivers that use address descriptor lists (ADLs) to support logical DMA remapping implement **DXGKCB_PINFRAMEBUFFERFORSAVE2** instead of [**DXGKARGCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave).

The memory pinned using **DXGKCB_PINFRAMEBUFFERFORSAVE2** can be unpinned using the original [**DXGKCB_UNPINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unpinframebufferforsave) callback.

See [IOMMU DMA remapping](https://learn.microsoft.com/windows-hardware/drivers/display/iommu-dma-remapping) for more information.

*DXGKCB_XXX* functions are implemented by *Dxgkrnl*. To use this callback function, set the appropriate members of [**DXGKARGCB_PINFRAMEBUFFERFORSAVE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave2) and then call **DxgkCbPinFrameBufferForSave2** via the [**DXGKRNL_INTERFACE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface).

## See also

[**DXGKARGCB_PINFRAMEBUFFERFORSAVE2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgkargcb_open_physical_memory_object)

[**DXGKARGCB_PINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_pinframebufferforsave)

[**DXGKCB_UNPINFRAMEBUFFERFORSAVE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkcb_unpinframebufferforsave)