# ExtCreateRegion function

## Description

The **ExtCreateRegion** function creates a region from the specified region and transformation data.

## Parameters

### `lpx` [in]

A pointer to an [XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform) structure that defines the transformation to be performed on the region. If this pointer is **NULL**, the identity transformation is used.

### `nCount` [in]

The number of bytes pointed to by *lpRgnData*.

### `lpData` [in]

A pointer to a [RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata) structure that contains the region data in logical units.

## Return value

If the function succeeds, the return value is the value of the region.

If the function fails, the return value is **NULL**.

## Remarks

Region coordinates are represented as 27-bit signed integers.

An application can retrieve data for a region by calling the [GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata) function.

## See also

[CreatePolyPolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolypolygonrgn)

[CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect)

[CreateRoundRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createroundrectrgn)

[GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata)

[RGNDATA](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-rgndata)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)

[XFORM](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-xform)