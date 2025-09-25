# _D3DDDICB_SETDISPLAYPRIVATEDRIVERFORMAT structure

## Description

The D3DDDICB_SETDISPLAYPRIVATEDRIVERFORMAT structure describes the private-format attribute to set for a video present source in a call to the [pfnSetDisplayPrivateDriverFormatCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplayprivatedriverformatcb) function.

## Members

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology to set a private-format attribute on (that is, the identifier of the primary surface to set a private-format attribute on).

### `PrivateDriverFormatAttribute` [in]

A UINT value that specifies the private-format attribute to set for the video present source that the **VidPnSourceId** member specifies.

## See also

[pfnSetDisplayPrivateDriverFormatCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_setdisplayprivatedriverformatcb)