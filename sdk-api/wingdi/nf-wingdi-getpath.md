# GetPath function

## Description

The **GetPath** function retrieves the coordinates defining the endpoints of lines and the control points of curves found in the path that is selected into the specified device context.

## Parameters

### `hdc` [in]

A handle to a device context that contains a closed path.

### `apt` [out]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that receives the line endpoints and curve control points, in logical coordinates.

### `aj` [out]

A pointer to an array of bytes that receives the vertex types. This parameter can be one of the following values.

| Type | Description |
| --- | --- |
| **PT_MOVETO** | Specifies that the corresponding point in the *lpPoints* parameter starts a disjoint figure. |
| **PT_LINETO** | Specifies that the previous point and the corresponding point in *lpPoints* are the endpoints of a line. |
| **PT_BEZIERTO** | Specifies that the corresponding point in *lpPoints* is a control point or ending point for a Bézier curve.<br><br>PT_BEZIERTO values always occur in sets of three. The point in the path immediately preceding them defines the starting point for the Bézier curve. The first two PT_BEZIERTO points are the control points, and the third PT_BEZIERTO point is the ending (if hard-coded) point. |

A PT_LINETO or PT_BEZIERTO value may be combined with the following value (by using the bitwise operator OR) to indicate that the corresponding point is the last point in a figure and the figure should be closed.

| Flag | Description |
| --- | --- |
| **PT_CLOSEFIGURE** | Specifies that the figure is automatically closed after the corresponding line or curve is drawn. The figure is closed by drawing a line from the line or curve endpoint to the point corresponding to the last PT_MOVETO. |

### `cpt` [in]

The total number of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that can be stored in the array pointed to by *lpPoints*. This value must be the same as the number of bytes that can be placed in the array pointed to by *lpTypes*.

## Return value

If the *nSize* parameter is nonzero, the return value is the number of points enumerated. If *nSize* is 0, the return value is the total number of points in the path (and **GetPath** writes nothing to the buffers). If *nSize* is nonzero and is less than the number of points in the path, the return value is 1.

## Remarks

The device context identified by the *hdc* parameter must contain a closed path.

The points of the path are returned in logical coordinates. Points are stored in the path in device coordinates, so **GetPath** changes the points from device coordinates to logical coordinates by using the inverse of the current transformation.

The [FlattenPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-flattenpath) function may be called before **GetPath** to convert all curves in the path into line segments.

## See also

[FlattenPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-flattenpath)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[Path Functions](https://learn.microsoft.com/windows/desktop/gdi/path-functions)

[Paths Overview](https://learn.microsoft.com/windows/desktop/gdi/paths)

[PolyDraw](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-polydraw)

[WidenPath](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-widenpath)