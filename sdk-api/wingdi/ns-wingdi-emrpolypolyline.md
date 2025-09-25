# EMRPOLYPOLYLINE structure

## Description

The **EMRPOLYPOLYLINE** and **EMRPOLYPOLYGON** structures contain members for the [PolyPolyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolyline) and [PolyPolygon](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolygon) enhanced metafile records.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

The bounding rectangle, in device units.

### `nPolys`

The number of polys.

### `cptl`

The total number of points in all polys.

### `aPolyCounts`

An array of point counts for each poly.

### `aptl`

An array of [POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl) structures, representing the points in logical units.

## See also

[EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[POINTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-pointl)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)