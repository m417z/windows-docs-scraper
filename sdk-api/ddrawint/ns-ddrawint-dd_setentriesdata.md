# DD_SETENTRIESDATA structure

## Description

The DD_SETENTRIESDATA structure contains information necessary to set palette entries.

## Members

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure that describes the driver's device.

### `lpDDPalette`

Points to a [DD_PALETTE_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_palette_global) structure that represents the DirectDrawPalette object.

### `dwBase`

Specifies a zero-based index into the color table of the first entry to be modified.

### `dwNumEntries`

Specifies the number of palette entries that the driver should update.

### `lpEntries`

Points to a PALETTEENTRY structure that specifies the color table. See the latest Microsoft DirectX SDK documentation for more information about PALETTEENTRY.

### `ddRVal`

Specifies the location in which the driver writes the return value of the [DdSetEntries](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_palcb_setentries) callback. For more information, see [Return Values for DirectDraw](https://learn.microsoft.com/windows-hardware/drivers/display/return-values-for-directdraw).

### `SetEntries`

Used by the Microsoft DirectDraw API and should not be filled in by the driver.

## See also

[DdSetEntries](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_palcb_setentries)