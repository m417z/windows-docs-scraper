# SetPaletteEntries function

## Description

The **SetPaletteEntries** function sets RGB (red, green, blue) color values and flags in a range of entries in a logical palette.

## Parameters

### `hpal` [in]

A handle to the logical palette.

### `iStart` [in]

The first logical-palette entry to be set.

### `cEntries` [in]

The number of logical-palette entries to be set.

### `pPalEntries` [in]

A pointer to the first member of an array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures containing the RGB values and flags.

## Return value

If the function succeeds, the return value is the number of entries that were set in the logical palette.

If the function fails, the return value is zero.

## Remarks

An application can determine whether a device supports palette operations by calling the [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) function and specifying the RASTERCAPS constant.

Even if a logical palette has been selected and realized, changes to the palette do not affect the physical palette in the surface. [RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette) must be called again to set the new logical palette into the surface.

## See also

[Color Functions](https://learn.microsoft.com/windows/desktop/gdi/color-functions)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps)

[GetPaletteEntries](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpaletteentries)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))

[RealizePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-realizepalette)