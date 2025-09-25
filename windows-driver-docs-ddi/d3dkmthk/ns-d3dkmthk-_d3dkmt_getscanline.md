# _D3DKMT_GETSCANLINE structure

## Description

The D3DKMT_GETSCANLINE structure contains information about a video present source's vertical blanking status.

## Members

### `hAdapter` [in]

A handle to a graphics adapter.

### `VidPnSourceId` [in]

The identifier of a graphics adapter's video present source.

### `InVerticalBlank` [out]

A Boolean variable that receives **TRUE** if the video present source is in vertical blanking mode and **FALSE** if the video present source is not in vertical blanking mode.

### `ScanLine` [out]

The video present source's current scan line.

## Remarks

A video present path represents a connection between a video present source (view) and a video present target (output) on a graphics adapter. For more information about video present networks, paths, sources, and targets, see [Introduction to Video Present Networks](https://learn.microsoft.com/windows-hardware/drivers/display/introduction-to-video-present-networks).

## See also

[D3DKMTGetScanLine](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetscanline)