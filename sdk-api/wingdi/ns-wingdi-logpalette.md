# LOGPALETTE structure

## Description

The **LOGPALETTE** structure defines a logical palette.

## Members

### `palVersion`

The version number of the system.

### `palNumEntries`

The number of entries in the logical palette.

### `palPalEntry`

Specifies an array of [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures that define the color and usage of each entry in the logical palette.

## Remarks

The colors in the palette-entry table should appear in order of importance because entries earlier in the logical palette are most likely to be placed in the system palette.

## See also

[Color Structures](https://learn.microsoft.com/windows/desktop/gdi/color-structures)

[Colors Overview](https://learn.microsoft.com/windows/desktop/gdi/colors)

[CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))