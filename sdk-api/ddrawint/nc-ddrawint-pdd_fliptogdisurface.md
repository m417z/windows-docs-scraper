## Description

The *DdFlipToGDISurface* callback function notifies the driver when DirectDraw is flipping to or from a GDI surface.

## Parameters

### `unnamedParam1`

Points to a [DD_FLIPTOGDISURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_fliptogdisurfacedata) structure that contains the notification information.

## Return value

*DdFlipToGDISurface* returns one of the following callback codes:

## Remarks

*DdFlipToGDISurface* can be implemented in drivers with hardware that needs to be enabled or disabled, depending on whether a GDI surface is being flipped to.

## See also

[DD_FLIPTOGDISURFACEDATA](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_fliptogdisurfacedata)