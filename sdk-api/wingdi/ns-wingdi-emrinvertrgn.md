# EMRINVERTRGN structure

## Description

The **EMRINVERTRGN** and **EMRPAINTRGN** structures
contain members for the [InvertRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-invertrgn) and [PaintRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-paintrgn) enhanced metafile records.

## Members

### `emr`

Base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `cbRgnData`

Size of region data, in bytes.

### `RgnData`

Buffer containing an [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) structure.

## See also

[InvertRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-invertrgn)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[PaintRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-paintrgn)