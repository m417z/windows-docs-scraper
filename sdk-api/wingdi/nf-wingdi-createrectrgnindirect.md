# CreateRectRgnIndirect function

## Description

The **CreateRectRgnIndirect** function creates a rectangular region.

## Parameters

### `lprect` [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the coordinates of the upper-left and lower-right corners of the rectangle that defines the region in logical units.

## Return value

If the function succeeds, the return value is the handle to the region.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the **HRGN** object, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

Region coordinates are represented as 27-bit signed integers.

The region will be exclusive of the bottom and right edges.

## See also

[CreatePolyPolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolypolygonrgn)

[CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[CreateRoundRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createroundrectrgn)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[ExtCreateRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreateregion)

[GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)