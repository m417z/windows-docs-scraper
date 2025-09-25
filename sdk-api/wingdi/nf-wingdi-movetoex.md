# MoveToEx function

## Description

The **MoveToEx** function updates the current position to the specified point and optionally returns the previous position.

## Parameters

### `hdc` [in]

Handle to a device context.

### `x` [in]

Specifies the x-coordinate, in logical units, of the new position, in logical units.

### `y` [in]

Specifies the y-coordinate, in logical units, of the new position, in logical units.

### `lppt` [out]

Pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the previous current position. If this parameter is a **NULL** pointer, the previous position is not returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **MoveToEx** function affects all drawing functions.

#### Examples

For an example, see [Drawing Markers](https://learn.microsoft.com/windows/desktop/gdi/drawing-markers).

## See also

[AngleArc](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-anglearc)

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[PolyBezierTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezierto)

[PolylineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polylineto)