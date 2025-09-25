# EMRCREATEPALETTE structure

## Description

The **EMRCREATEPALETTE** structure contains members for the [CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `ihPal`

Index of palette in handle table.

### `lgpl`

A [LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette) structure that contains information about the palette. Note that **peFlags** members in the [PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85)) structures do not contain any flags.

## See also

[CreatePalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpalette)

[LOGPALETTE](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logpalette)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PALETTEENTRY](https://learn.microsoft.com/previous-versions/dd162769(v=vs.85))