# CreatePolygonRgn function

## Description

The **CreatePolygonRgn** function creates a polygonal region.

## Parameters

### `pptl` [in]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures that define the vertices of the polygon in logical units. The polygon is presumed closed. Each vertex can be specified only once.

### `cPoint` [in]

The number of points in the array.

### `iMode` [in]

The fill mode used to determine which pixels are in the region. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ALTERNATE** | Selects alternate mode (fills area between odd-numbered and even-numbered polygon sides on each scan line). |
| **WINDING** | Selects winding mode (fills any region with a nonzero winding value). |

For more information about these modes, see the [SetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setpolyfillmode) function.

## Return value

If the function succeeds, the return value is the handle to the region.

If the function fails, the return value is **NULL**.

## Remarks

When you no longer need the **HRGN** object, call the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function to delete it.

Region coordinates are represented as 27-bit signed integers.

Regions created by the Create<shape>Rgn methods (such as [CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn) and **CreatePolygonRgn**) only include the interior of the shape; the shape's outline is excluded from the region. This means that any point on a line between two sequential vertices is not included in the region. If you were to call [PtInRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-ptinregion) for such a point, it would return zero as the result.

## See also

[CreatePolyPolygonRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpolypolygonrgn)

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