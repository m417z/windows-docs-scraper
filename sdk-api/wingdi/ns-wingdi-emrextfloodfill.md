# EMREXTFLOODFILL structure

## Description

The **EMREXTFLOODFILL** structure contains members for the [ExtFloodFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extfloodfill) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `ptlStart`

Coordinates, in logical units, where filling begins.

### `crColor`

Color of fill. To make a [COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref) value, use the [RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb) macro.

### `iMode`

Type of fill operation to be performed. This member must be either the FLOODFILLBORDER or FLOODFILLSURFACE value.

## See also

[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)

[ExtFloodFill](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extfloodfill)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGB](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rgb)