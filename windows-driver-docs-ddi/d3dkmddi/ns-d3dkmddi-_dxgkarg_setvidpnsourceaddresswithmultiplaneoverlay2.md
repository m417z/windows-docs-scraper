# _DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2 structure

## Description

**DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2** is passed to the [DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay2) function to change the overlay configuration being displayed.

## Members

### `ContextCount`

The number of contexts in the array that the **Context** member specifies.

### `Context`

An array of handles to the contexts that contributed to a display operation.

### `Flags`

A [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure that identifies the type of display operation to perform.

### `VidPnSourceId`

An integer that identifies a video present source on the display adapter.

### `PlaneCount`

The number of overlay planes in the **pPlanes** list.

### `pPlanes`

An array of [DXGK_MULTIPLANE_OVERLAY_PLANE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane2) structures that specify the overlay planes to display.

### `Duration`

The length of time, in 100 nanoseconds units, between when the current present operation flips to the screen and the next vertical blanking interrupt occurs.

If zero, the refresh rate should be the default rate based on the current mode.

## See also

[DXGK_MULTIPLANE_OVERLAY_PLANE2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane2)

[DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags)

[DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay2)