# _DXGKARG_SETVIDPNSOURCEVISIBILITY structure

## Description

The DXGKARG_SETVIDPNSOURCEVISIBILITY structure contains arguments for the [DxgkDdiSetVidPnSourceVisibility](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourcevisibility) function.

## Members

### `VidPnSourceId`

An integer that identifies a video present source on the display adapter.

### `Visible`

A Boolean value that specifies whether the video output codec associated with the source must start scanning or stop scanning the source's primary surface. If **Visible** is **TRUE**, the codec must start scanning.

If **Visible** is **FALSE**, the codec must stop scanning. However, a VSync signal should be generated even if a call to the [DxgkDdiSetVidPnSourceVisibility](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourcevisibility) function sets **Visible** to **FALSE**.

## See also

[DxgkDdiSetVidPnSourceVisibility](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setvidpnsourcevisibility)