# PolyPolyline function

## Description

The **PolyPolyline** function draws multiple series of connected line segments.

## Parameters

### `hdc` [in]

A handle to the device context.

### `apt` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that contains the vertices of the polylines, in logical units. The polylines are specified consecutively.

### `asz` [in]

A pointer to an array of variables specifying the number of points in the *lppt* array for the corresponding polyline. Each entry must be greater than or equal to two.

### `csz` [in]

The total number of entries in the *lpdwPolyPoints* array.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The line segments are drawn by using the current pen. The figures formed by the segments are not filled.

The current position is neither used nor updated by this function.

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[Polyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline)

[PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto)