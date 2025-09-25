# PolyBezier function

## Description

The **PolyBezier** function draws one or more Bézier curves.

## Parameters

### `hdc` [in]

A handle to a device context.

### `apt` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that contain the endpoints and control points of the curve(s), in logical units.

### `cpt` [in]

The number of points in the *lppt* array. This value must be one more than three times the number of curves to be drawn, because each Bézier curve requires two control points and an endpoint, and the initial curve requires an additional starting point.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **PolyBezier** function draws cubic Bézier curves by using the endpoints and control points specified by the *lppt* parameter. The first curve is drawn from the first point to the fourth point by using the second and third points as control points. Each subsequent curve in the sequence needs exactly three more points: the ending point of the previous curve is used as the starting point, the next two points in the sequence are control points, and the third is the ending point.

The current position is neither used nor updated by the **PolyBezier** function. The figure is not filled.

This function draws lines by using the current pen.

#### Examples

For an example, see [Redrawing in the Update Region](https://learn.microsoft.com/windows/desktop/gdi/redrawing-in-the-update-region).

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[PolyBezierTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezierto)