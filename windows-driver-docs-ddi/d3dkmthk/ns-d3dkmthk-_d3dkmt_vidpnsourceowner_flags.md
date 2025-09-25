# _D3DKMT_VIDPNSOURCEOWNER_FLAGS structure

## Description

Specifies output duplication options for use with the [D3DKMTSetVidPnSourceOwner1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetvidpnsourceowner1) function.

## Members

### `AllowOutputDuplication`

If a value of one, the video present network (VidPN) explicitly allows output duplication. Otherwise output duplication is not allowed.

### `DisableDWMVirtualMode`

### `UseNtHandles`

### `Reserved`

Reserved for internal use.

### `Value`

Specifies the number of output duplication paths on the VidPN.

## See also

[D3DKMTSetVidPnSourceOwner1](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtsetvidpnsourceowner1)