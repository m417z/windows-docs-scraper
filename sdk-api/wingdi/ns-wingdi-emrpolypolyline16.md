# EMRPOLYPOLYLINE16 structure

## Description

The **EMRPOLYPOLYLINE16** and **EMRPOLYPOLYGON16** structures contain members for the [PolyPolyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolyline) and [PolyPolygon](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolygon) enhanced metafile records.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

The bounding rectangle, in device units.

### `nPolys`

The number of polys.

### `cpts`

The total number of points in all polys.

### `aPolyCounts`

An array of point counts for each poly.

### `apts`

An array of [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structures, representing the points in logical units.

## See also

[EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)