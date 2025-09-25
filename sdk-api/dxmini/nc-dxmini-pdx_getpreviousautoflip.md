# PDX_GETPREVIOUSAUTOFLIP callback function

## Description

The *DxGetPreviousAutoflip* callback function is called when the device is hardware autoflipping and a client of the video miniport driver wants to know which surface received the previous field of video data for capture purposes.

## Parameters

### `unnamedParam1`
Points to the miniport driver's device extension.

### `unnamedParam2`
Points to a [DDGETPREVIOUSAUTOFLIPININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpreviousautoflipininfo) structure that contains the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object information.

### `unnamedParam3`
Points to a [DDGETPREVIOUSAUTOFLIPOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpreviousautoflipoutinfo) structure that contains the index of the autoflip chain.

## Return value

*DxGetPreviousAutoflip* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

If interleaving, the surface that received the previous field may be the same surface that is receiving the current field.

*DxGetPreviousAutoflip* returns the index in the autoflip chain of the correct surface in the **dwSurfaceIndex** member of the DDGETPREVIOUSAUTOFLIPOUTINFO structure at *GetPreviousAutoflipOutInfo*.

## See also

[DDGETPREVIOUSAUTOFLIPININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpreviousautoflipininfo)

[DDGETPREVIOUSAUTOFLIPOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetpreviousautoflipoutinfo)