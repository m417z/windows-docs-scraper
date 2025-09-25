# CreatePolyPolygonRgn function

## Description

The **CreatePolyPolygonRgn** function creates a region consisting of a series of polygons. The polygons can overlap.

## Parameters

### `pptl` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that define the vertices of the polygons in logical units. The polygons are specified consecutively. Each polygon is presumed closed and each vertex is specified only once.

### `pc` [in]

A pointer to an array of integers, each of which specifies the number of points in one of the polygons in the array pointed to by *lppt*.

### `cPoly` [in]

The total number of integers in the array pointed to by *lpPolyCounts*.

### `iMode` [in]

The fill mode used to determine which pixels are in the region. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ALTERNATE** | Selects alternate mode (fills area between odd-numbered and even-numbered polygon sides on each scan line). |
| **WINDING** | Selects winding mode (fills any region with a nonzero winding value). |

For more information about these modes, see the [SetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpolyfillmode) function.

## Return value

If the function succeeds, the return value is the handle to the region.

If the function fails, the return value is zero.

## Remarks

When you no longer need the **HRGN** object, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

Region coordinates are represented as 27-bit signed integers.

## See also

[CreatePolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolygonrgn)

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect)

[CreateRoundRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createroundrectrgn)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[ExtCreateRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreateregion)

[GetRegionData](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getregiondata)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)

[SetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpolyfillmode)