# _D3DKMT_CHECKVIDPNEXCLUSIVEOWNERSHIP structure

## Description

The D3DKMT_CHECKVIDPNEXCLUSIVEOWNERSHIP structure describes the parameters to determine the video present source in the path of a video present network (VidPN) topology that exclusively owns the VidPN.

## Members

### `hAdapter` [in]

A D3DKMT_HANDLE data type that represents a kernel-mode handle to the graphics adapter.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology to check about.

## See also

[D3DKMTCheckVidPnExclusiveOwnership](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcheckvidpnexclusiveownership)