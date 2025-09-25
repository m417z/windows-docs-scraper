# CreateRoundRectRgn function

## Description

The **CreateRoundRectRgn** function creates a rectangular region with rounded corners.

## Parameters

### `x1` [in]

Specifies the x-coordinate of the upper-left corner of the region in device units.

### `y1` [in]

Specifies the y-coordinate of the upper-left corner of the region in device units.

### `x2` [in]

Specifies the x-coordinate of the lower-right corner of the region in device units.

### `y2` [in]

Specifies the y-coordinate of the lower-right corner of the region in device units.

### `w` [in]

Specifies the width of the ellipse used to create the rounded corners in device units.

### `h` [in]

Specifies the height of the ellipse used to create the rounded corners in device units.

## Return value

If the function succeeds, the return value is the handle to the region.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the **HRGN** object call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

Region coordinates are represented as 27-bit signed integers.

## See also

[CreatePolyPolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolypolygonrgn)

[CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[ExtCreateRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreateregion)

[GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)