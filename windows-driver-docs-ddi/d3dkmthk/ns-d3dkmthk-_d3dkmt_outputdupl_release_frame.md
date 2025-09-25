# _D3DKMT_OUTPUTDUPL_RELEASE_FRAME structure

## Description

Defines the duplicated desktop image that is to be released in a call to the [D3DKMTOutputDuplReleaseFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtoutputduplreleaseframe) function.

## Members

### `hAdapter` [in]

A handle of type **D3DKMT_HANDLE** that represents a kernel-mode handle to the graphics adapter that contains the duplicated desktop image.

### `VidPnSourceId` [in]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology.

### `NextKeyMutexIdx`

## See also

[D3DKMTOutputDuplReleaseFrame](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtoutputduplreleaseframe)