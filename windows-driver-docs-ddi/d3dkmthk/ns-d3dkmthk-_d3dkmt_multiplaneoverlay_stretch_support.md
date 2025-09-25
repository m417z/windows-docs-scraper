# D3DKMT_MULTIPLANEOVERLAY_STRETCH_SUPPORT structure

## Description

The **D3DKMT_MULTIPLANEOVERLAY_STRETCH_SUPPORT** structure describes the driver's multiplane overlay stretch support.

## Members

### `VidPnSourceId`

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the monitor is connected to.

### `Update`

Boolean value that indicates whether to update.

### `Supported`

Boolean value that indicates whether multiplane overlay stretch is supported.

## See also

[D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)