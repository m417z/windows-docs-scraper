# CreateRectRgn function

## Description

The **CreateRectRgn** function creates a rectangular region.

## Parameters

### `x1` [in]

Specifies the x-coordinate of the upper-left corner of the region in logical units.

### `y1` [in]

Specifies the y-coordinate of the upper-left corner of the region in logical units.

### `x2` [in]

Specifies the x-coordinate of the lower-right corner of the region in logical units.

### `y2` [in]

Specifies the y-coordinate of the lower-right corner of the region in logical units.

## Return value

If the function succeeds, the return value is the handle to the region.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the **HRGN** object, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

Region coordinates are represented as 27-bit signed integers.

Regions created by the Create<shape>Rgn methods (such as **CreateRectRgn** and [CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)) only include the interior of the shape; the shape's outline is excluded from the region. This means that any point on a line between two sequential vertices is not included in the region. If you were to call [PtInRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-ptinregion) for such a point, it would return zero as the result.

#### Examples

For an example, see [Drawing Markers.](https://learn.microsoft.com/windows/desktop/gdi/drawing-markers)

## See also

[CreatePolyPolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolypolygonrgn)

[CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)

[CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect)

[CreateRoundRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createroundrectrgn)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[ExtCreateRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreateregion)

[GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)