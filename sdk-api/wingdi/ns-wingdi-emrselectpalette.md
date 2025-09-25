# EMRSELECTPALETTE structure

## Description

The **EMRSELECTPALETTE** structure contains members for the [SelectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectpalette) enhanced metafile record. Note that the *bForceBackground* parameter in **SelectPalette** is always recorded as **TRUE**, which causes the palette to be realized as a background palette.

## Members

### `emr`

The base structure for all record types.

### `ihPal`

Index to logical palette in the handle table.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[SelectPalette](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectpalette)