## Description

The *DxFlipOverlay* callback function is called when a client of the video miniport driver wants to flip the overlay or when autoflipping is enabled.

## Parameters

### `unnamedParam1`

Points to the miniport driver's device extension.

### `unnamedParam2`

Points to the [DDFLIPOVERLAYINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddflipoverlayinfo) structure that contains the flip information for the surface.

### `unnamedParam3`

Reserved for system use.

## Return value

*DxFlipOverlay* returns DX_OK if it succeeds; otherwise, it returns one of the following error values:

## Remarks

If a hardware video port is not used and the client still wants the overlay to bob the data, the **dwFlags** member of the DDFLIPOVERLAYINFO structure at *FlipOverlayInfo* specifies the polarity of the data in the field being flipped (using the DDFLIP_EVEN or DDFLIP_ODD flags). These flags are not used when flipping a surface that is fed by a hardware video port.

## See also

[DDFLIPOVERLAYINFO](https://learn.microsoft.com/windows/desktop/api/dxmini/ns-dxmini-ddflipoverlayinfo)