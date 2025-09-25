## Description

The **DXGKARG_CANCELFLIPS** structure contains parameters for the driver's [**DXGKDDI_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelflips) callback function.

## Members

### `VidPnSourceId`

[in] A **D3DDDI_VIDEO_PRESENT_SOURCE_ID** value that identifies the VidPn source ID of the flip queue.

### `PlaneCount`

[in] Number of planes with pending Presents to cancel; that is, the number of [**DXGK_CANCELFLIPS_PLANE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_cancelflips_plane) structures in the array that **ppPlanes** points to.

### `ppPlanes`

[in/out] Pointer to an array of [**DXGK_CANCELFLIPS_PLANE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_cancelflips_plane) structures, each containing a per plane cancel request.

## Remarks

Asynchronously cancelled PresentIds are reported via the [VSync interrupt mechanism](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#specifying-vsync-interrupt-behavior).

See [Cancelling interlocked flips on multiple planes](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue#cancelling-interlocked-flips-on-multiple-planes) for more information.

## See also

[**DXGK_CANCELFLIPS_PLANE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_cancelflips_plane)

[**DXGKDDI_CANCELFLIPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_cancelflips)