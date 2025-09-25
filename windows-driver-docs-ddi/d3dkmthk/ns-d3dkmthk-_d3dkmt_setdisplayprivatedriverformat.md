# _D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT structure

## Description

The D3DKMT_SETDISPLAYPRIVATEDRIVERFORMAT structure describes the private-format attribute to set for a video present source.

## Members

### `hDevice` [in]

A handle to the device that requests to change the private-format attribute of a video present source.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology to set a private-format attribute on (that is, the identifier of the primary surface to set a private-format attribute on).

### `PrivateDriverFormatAttribute` [in]

A UINT value that specifies the private-format attribute to set for the video present source that the **VidPnSourceId** member specifies.

## See also

[D3DKMTSetDisplayPrivateDriverFormat](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetdisplayprivatedriverformat)