# _DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY structure

## Description

Contains arguments for the [DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay) function.

## Members

### `ContextCount` [in]

The number of contexts in the array that the **Context** member specifies.

### `Context` [in]

An array of handles to the contexts that contributed to a display operation.

### `Flags` [in]

A [DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags) structure that identifies the type of display operation to perform.

### `VidPnSourceId`

An integer that identifies a video present source on the display adapter.

### `PlaneCount`

The number of overlay planes that the hardware supports.

### `pPlanes`

A pointer to a [DXGK_MULTIPLANE_OVERLAY_PLANE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_multiplane_overlay_plane) structure that specifies the first overlay plane to display.

### `Duration`

The length of time, in units of 100 nanoseconds, between when the current present operation flips to the screen and the next vertical blanking interrupt occurs.

If zero, the refresh rate should be the default rate based on the current mode.

Must be supported by WDDM 1.3 and later drivers. Available starting with Windows 8.1.

## See also

[DXGK_SETVIDPNSOURCEADDRESS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_setvidpnsourceaddress_flags)

[DxgkDdiSetVidPnSourceAddressWithMultiPlaneOverlay](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourceaddresswithmultiplaneoverlay)