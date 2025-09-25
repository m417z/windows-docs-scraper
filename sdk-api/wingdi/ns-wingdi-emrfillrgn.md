# EMRFILLRGN structure

## Description

The **EMRFILLRGN** structure contains members for the [FillRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-fillrgn) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `cbRgnData`

Size of region data, in bytes.

### `ihBrush`

Index of brush, in handle table.

### `RgnData`

Buffer containing [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) structure.

## See also

[FillRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-fillrgn)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata)