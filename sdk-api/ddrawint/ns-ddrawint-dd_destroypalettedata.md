# DD_DESTROYPALETTEDATA structure

## Description

The DD_DESTROYPALETTEDATA structure contains information necessary to destroy the specified palette.

## Members

### `lpDD`

Points to the [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDPalette`

Points to the [DD_PALETTE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palette_global) structure representing the palette object to be destroyed.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdDestroyPalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_palcb_destroypalette) callback. A return code of DD_OK indicates success. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `DestroyPalette`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[DdDestroyPalette](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_palcb_destroypalette)