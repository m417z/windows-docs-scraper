# EMRLINETO structure

## Description

The **EMRLINETO** and **EMRMOVETOEX** structures contains members for the [LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto) and [MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex) enhanced metafile records.

## Members

### `emr`

Base structure for all record types.

### `ptl`

Coordinates of the line's ending point for the [LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto) function or coordinates of the new current position for the [MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex) function in logical units.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)