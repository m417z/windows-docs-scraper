# PolyBezierTo function

## Description

The **PolyBezierTo** function draws one or more Bézier curves.

## Parameters

### `hdc` [in]

A handle to a device context.

### `apt` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that contains the endpoints and control points, in logical units.

### `cpt` [in]

The number of points in the *lppt* array. This value must be three times the number of curves to be drawn because each Bézier curve requires two control points and an ending point.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

This function draws cubic Bézier curves by using the control points specified by the *lppt* parameter. The first curve is drawn from the current position to the third point by using the first two points as control points. For each subsequent curve, the function needs exactly three more points, and uses the ending point of the previous curve as the starting point for the next.

**PolyBezierTo** moves the current position to the ending point of the last Bézier curve. The figure is not filled.

This function draws lines by using the current pen.

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[PolyBezier](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezier)