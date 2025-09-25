## Description

The *DxFlipVideoPort* callback function is called when a client of the video miniport driver wants to flip the [video port extensions (VPE)](https://learn.microsoft.com/windows-hardware/drivers/) object or when autoflipping is enabled.

## Parameters

### `unnamedParam1`

Points to the miniport driver's device extension.

### `unnamedParam2`

Points to the [DDFLIPVIDEOPORTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddflipvideoportinfo) structure that contains the flip information for the surface and VPE object.

### `unnamedParam3`

Reserved for system use.

## Return value

*DxFlipVideoPort* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

The **dwFlipVPFlags** member of the DDFLIPVIDEOPORTINFO structure at *FlipVideoPortInfo* uses the DDVPFLIP_VIDEO or DDVPFLIP_VBI flag to indicate whether the surfaces represent VBI surfaces or regular surfaces.

## See also

[DDFLIPVIDEOPORTINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddflipvideoportinfo)