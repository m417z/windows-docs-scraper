# DD_SETPALETTEDATA structure

## Description

The DD_SETPALETTEDATA structure contains information necessary to set a palette for a specific surface.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDSurface`

Points to a [DD_SURFACE_LOCAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_surface_local) structure that represents the DirectDrawSurface object.

### `lpDDPalette`

Points to a [DD_PALETTE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palette_global) structure that specifies the palette to set to the surface.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdSetPalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setpalette) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `SetPalette`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

### `Attach`

Indicates whether to attach this palette to the surface.

## See also

[DdSetPalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_surfcb_setpalette)