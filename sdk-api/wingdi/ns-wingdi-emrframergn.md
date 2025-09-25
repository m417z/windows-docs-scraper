# EMRFRAMERGN structure

## Description

The **EMRFRAMERGN** structure contains members for the [FrameRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-framergn) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `cbRgnData`

Size of region data, in bytes.

### `ihBrush`

Index of brush, in handle table.

### `szlStroke`

Width and height of region frame, in logical units.

### `RgnData`

Buffer containing [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) structure.

## See also

[FrameRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-framergn)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata)