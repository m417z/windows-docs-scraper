# EMRPOLYDRAW16 structure

## Description

The **EMRPOLYDRAW16** structure contains members for the [PolyDraw](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polydraw) enhanced metafile record.

## Members

### `emr`

The base structure for all record types.

### `rclBounds`

The bounding rectangle, in device units.

### `cpts`

The number of points.

### `apts`

An array of [POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points) structures, representing the data points in logical units.

### `abTypes`

An array of values that specifies how each point in the **apts** array is used. Each element can be one of the following values: PT_MOVETO, PT_LINETO, or PT_BEZIERTO. The PT_LINETO or PT_BEZIERTO value can be combined with the PT_CLOSEFIGURE value using the bitwise-OR operator.

## See also

[EMR](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-emr)

[Metafile Structures](https://learn.microsoft.com/windows/desktop/gdi/metafile-structures)

[Metafiles Overview](https://learn.microsoft.com/windows/desktop/gdi/metafiles)

[POINTS](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-points)

[PolyDraw](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polydraw)

[RECTL](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-rectl)