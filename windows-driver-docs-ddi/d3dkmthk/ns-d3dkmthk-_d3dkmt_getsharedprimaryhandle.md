# _D3DKMT_GETSHAREDPRIMARYHANDLE structure

## Description

The D3DKMT_GETSHAREDPRIMARYHANDLE structure describes the parameters that are required to retrieve the global shared handle for the primary surface.

## Members

### `hAdapter` [in]

A handle to the graphics adapter that the primary surface is associated with.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology that displays the primary surface.

### `hSharedPrimary` [out]

A handle to the global shared primary surface if a shared handle currently exists. The shared handle is returned from the call to the [D3DKMTGetSharedPrimaryHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetsharedprimaryhandle) function.

## See also

[D3DKMTGetSharedPrimaryHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtgetsharedprimaryhandle)