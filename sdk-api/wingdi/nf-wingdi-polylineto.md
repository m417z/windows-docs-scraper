# PolylineTo function

## Description

The **PolylineTo** function draws one or more straight lines.

## Parameters

### `hdc` [in]

A handle to the device context.

### `apt` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that contains the vertices of the line, in logical units.

### `cpt` [in]

The number of points in the array.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

Unlike the [Polyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline) function, the **PolylineTo** function uses and updates the current position.

A line is drawn from the current position to the first point specified by the *lppt* parameter by using the current pen. For each additional line, the function draws from the ending point of the previous line to the next point specified by *lppt*.

**PolylineTo** moves the current position to the ending point of the last line.

If the line segments drawn by this function form a closed figure, the figure is not filled.

## See also

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[PolyPolyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polypolyline)

[Polyline](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline)