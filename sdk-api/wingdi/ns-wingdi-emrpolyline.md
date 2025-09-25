# EMRPOLYLINE structure

## Description

The **EMRPOLYLINE,** **EMRPOLYBEZIER,** **EMRPOLYGON,** **EMRPOLYBEZIERTO,**  and **EMRPOLYLINETO** structures contain members for the [Polyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline), [PolyBezier](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezier), [Polygon](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polygon), [PolyBezierTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezierto), and [PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto) enhanced metafile records.

## Members

### `emr`

Base structure for all record types.

### `rclBounds`

Bounding rectangle, in device units.

### `cptl`

Number of points array.

### `aptl`

Array of 32-bit points, in logical units.

## See also

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)