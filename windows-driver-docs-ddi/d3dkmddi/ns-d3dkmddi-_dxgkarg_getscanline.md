# _DXGKARG_GETSCANLINE structure

## Description

The DXGKARG_GETSCANLINE structure contains information about a video present target's vertical blanking status.

## Members

### `VidPnTargetId` [in]

The identifier of a display adapter's video present target.

### `InVerticalBlank` [out]

A Boolean variable that receives **TRUE** if the video present target is in vertical blanking mode and **FALSE** if the video present target is not in vertical blanking mode.

### `ScanLine` [out]

The video present target's current scan line.

## Remarks

A video present path represents a connection between a video present source (view) and a video present target (output) on a display adapter. For more information about video present networks, paths, sources, and targets, see [Introduction to Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-video-present-networks).

## See also

[DxgkDdiGetScanLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_getscanline)