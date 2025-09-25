# PolyDraw function

## Description

The **PolyDraw** function draws a set of line segments and Bézier curves.

## Parameters

### `hdc` [in]

A handle to a device context.

### `apt` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that contains the endpoints for each line segment and the endpoints and control points for each Bézier curve, in logical units.

### `aj` [in]

A pointer to an array that specifies how each point in the *lppt* array is used. This parameter can be one of the following values.

| Type | Meaning |
| --- | --- |
| **PT_MOVETO** | Specifies that this point starts a disjoint figure. This point becomes the new current position. |
| **PT_LINETO** | Specifies that a line is to be drawn from the current position to this point, which then becomes the new current position. |
| **PT_BEZIERTO** | Specifies that this point is a control point or ending point for a Bézier curve.<br><br>PT_BEZIERTO types always occur in sets of three. The current position defines the starting point for the Bézier curve. The first two PT_BEZIERTO points are the control points, and the third PT_BEZIERTO point is the ending point. The ending point becomes the new current position. If there are not three consecutive PT_BEZIERTO points, an error results. |

A PT_LINETO or PT_BEZIERTO type can be combined with the following value by using the bitwise operator OR to indicate that the corresponding point is the last point in a figure and the figure is closed.

| Value | Meaning |
| --- | --- |
| **PT_CLOSEFIGURE** | Specifies that the figure is automatically closed after the PT_LINETO or PT_BEZIERTO type for this point is done. A line is drawn from this point to the most recent PT_MOVETO or [MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex) point.<br><br>This value is combined with the PT_LINETO type for a line, or with the PT_BEZIERTO type of the ending point for a Bézier curve, by using the bitwise operator OR.<br><br>The current position is set to the ending point of the closing line. |

### `cpt` [in]

The total number of points in the *lppt* array, the same as the number of bytes in the *lpbTypes* array.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **PolyDraw** function can be used in place of consecutive calls to [MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex), [LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto), and [PolyBezierTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezierto) functions to draw disjoint figures. The lines and curves are drawn using the current pen and figures are not filled. If there is an active path started by calling [BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath), **PolyDraw** adds to the path.

The points contained in the *lppt* array and in the *lpbTypes* array indicate whether each point is part of a [MoveTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex), [LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto), or [PolyBezierTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezierto) operation. It is also possible to close figures.

This function updates the current position.

## See also

[BeginPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-beginpath)

[EndPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-endpath)

[Line and Curve Functions](https://learn.microsoft.com/windows/desktop/gdi/line-and-curve-functions)

[LineTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lineto)

[Lines and Curves Overview](https://learn.microsoft.com/windows/desktop/gdi/lines-and-curves)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[PolyBezierTo](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polybezierto)

[PolyLine](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polyline)