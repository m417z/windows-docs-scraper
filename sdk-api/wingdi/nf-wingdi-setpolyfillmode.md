# SetPolyFillMode function

## Description

The **SetPolyFillMode** function sets the polygon fill mode for functions that fill polygons.

## Parameters

### `hdc` [in]

A handle to the device context.

### `mode` [in]

The new fill mode. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ALTERNATE** | Selects alternate mode (fills the area between odd-numbered and even-numbered polygon sides on each scan line). |
| **WINDING** | Selects winding mode (fills any region with a nonzero winding value). |

## Return value

The return value specifies the previous filling mode. If an error occurs, the return value is zero.

## Remarks

In general, the modes differ only in cases where a complex, overlapping polygon must be filled (for example, a five-sided polygon that forms a five-pointed star with a pentagon in the center). In such cases, ALTERNATE mode fills every other enclosed region within the polygon (that is, the points of the star), but WINDING mode fills all regions (that is, the points and the pentagon).

When the fill mode is ALTERNATE, GDI fills the area between odd-numbered and even-numbered polygon sides on each scan line. That is, GDI fills the area between the first and second side, between the third and fourth side, and so on.

When the fill mode is WINDING, GDI fills any region that has a nonzero winding value. This value is defined as the number of times a pen used to draw the polygon would go around the region. The direction of each edge of the polygon is important.

## See also

[GetPolyFillMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getpolyfillmode)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)