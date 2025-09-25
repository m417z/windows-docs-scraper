# _D3DKMT_INVALIDATEACTIVEVIDPN structure

## Description

The D3DKMT_INVALIDATEACTIVEVIDPN structure describes parameters that invalidate the active video present network (VidPN) currently in use.

## Members

### `hAdapter` [in]

A handle to the graphics adapter that the VidPN exists on.

### `pPrivateDriverData` [in]

A pointer to a buffer that contains the display mode (for example, clone-view mode) that the OpenGL installable client driver (ICD) requests for the new VidPN.

### `PrivateDriverDataSize` [in]

The size, in bytes, of the buffer that **pPrivateDriverData** points to.

## See also

[D3DKMTInvalidateActiveVidPn](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtinvalidateactivevidpn)