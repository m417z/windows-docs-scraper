# _D3DKMT_CURRENTDISPLAYMODE structure

## Description

The D3DKMT_CURRENTDISPLAYMODE structure describes the current display mode of the specified video source.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that the display mode applies to.

### `DisplayMode` [out]

A [D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode) structure that represents the current display mode.

## See also

[D3DKMTQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtqueryadapterinfo)

[D3DKMT_DISPLAYMODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_displaymode)