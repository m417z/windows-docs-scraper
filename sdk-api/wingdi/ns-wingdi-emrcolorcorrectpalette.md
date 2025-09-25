# EMRCOLORCORRECTPALETTE structure

## Description

The **EMRCOLORCORRECTPALETTE** structure contains members for the [ColorCorrectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-colorcorrectpalette) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `ihPalette`

The index of the palette handle to color correct.

### `nFirstEntry`

The index of the first entry in the palette to color correct.

### `nPalEntries`

The number of palette entries to color correct.

### `nReserved`

Reserved.

## See also

[ColorCorrectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-colorcorrectpalette)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)