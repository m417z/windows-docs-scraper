# Polyline function

## Description

The **Polyline** function draws a series of line segments by connecting the points in the specified array.

## Parameters

### `hdc` [in]

A handle to a device context.

### `apt` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures, in logical units.

### `cpt` [in]

The number of points in the array. This number must be greater than or equal to two.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The lines are drawn from the first point through subsequent points by using the current pen. Unlike the [LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto) or [PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto) functions, the **Polyline** function neither uses nor updates the current position.

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[PolyPolyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolyline)

[PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto)