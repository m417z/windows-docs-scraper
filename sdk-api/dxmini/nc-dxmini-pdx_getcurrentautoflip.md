## Description

The *DxGetCurrentAutoflip* callback function is called when the device is hardware autoflipping and a client of the video miniport driver wants to know which surface is receiving the current field of video data for capture purposes.

## Parameters

### `unnamedParam1`
Points to the miniport driver's device extension.

### `unnamedParam2`
Points to the [DDGETCURRENTAUTOFLIPININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetcurrentautoflipininfo) structure that contains the VPE object information.

### `unnamedParam3`
Points to the [DDGETCURRENTAUTOFLIPOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetcurrentautoflipoutinfo) structure that contains the surface information.

## Return value

*DxGetCurrentAutoflip* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

The *DxGetCurrentAutoflip* function returns the current index in the autoflip chain of the current surface in the **dwSurfaceIndex** member of the DDGETCURRENTAUTOFLIPOUTINFO structure at *GetCurrentAutoflipOutInfo*.

## See also

[DDGETCURRENTAUTOFLIPININFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetcurrentautoflipininfo)

[DDGETCURRENTAUTOFLIPOUTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddgetcurrentautoflipoutinfo)