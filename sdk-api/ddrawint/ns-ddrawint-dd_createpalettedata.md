# DD_CREATEPALETTEDATA structure

## Description

The DD_CREATEPALETTEDATA structure contains information necessary to create a DirectDrawPalette object for this Microsoft DirectDraw object.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDPalette`

Points to a [DD_PALETTE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palette_global) structure representing the DirectDrawPalette object.

### `lpColorTable`

Points to an array of 2, 4, 16, or 256 PALETTEENTRY structures used to initialize the colors for this DirectDrawPalette object. See the latest Microsoft DirectX SDK documentation for more information about PALETTEENTRY.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdCreatePalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createpalette) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `CreatePalette`

Used by the DirectDraw API and should not be filled in by the driver.

### `is_excl`

Specifies a BOOL value that is set to **TRUE** to indicate that this process has exclusive mode and **FALSE** otherwise.

## See also

[DdCreatePalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_createpalette)