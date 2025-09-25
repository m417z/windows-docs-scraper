# _D3DKMT_WAITFORVERTICALBLANKEVENT structure

## Description

The D3DKMT_WAITFORVERTICALBLANKEVENT structure describes parameters for waiting for the vertical blanking interval to occur.

## Members

### `hAdapter` [in]

A handle to the adapter.

### `hDevice` [in]

A handle to the display device. This member is optionally specified. However, if the OpenGL ICD specifies the display device, the kernel is given more optimization opportunities with regard to power usage.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology for the VidPN source.

## See also

[D3DKMTWaitForVerticalBlankEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtwaitforverticalblankevent)