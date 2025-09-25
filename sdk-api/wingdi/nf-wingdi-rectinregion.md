# RectInRegion function

## Description

The **RectInRegion** function determines whether any part of the specified rectangle is within the boundaries of a region.

## Parameters

### `hrgn` [in]

Handle to the region.

### `lprect` [in]

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure containing the coordinates of the rectangle in logical units. The lower and right edges of the rectangle are not included.

## Return value

If any part of the specified rectangle lies within the boundaries of the region, the return value is nonzero.

If no part of the specified rectangle lies within the boundaries of the region, the return value is zero.

## See also

[PtInRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-ptinregion)

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)