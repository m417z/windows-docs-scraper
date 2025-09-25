# PtInRegion function

## Description

The **PtInRegion** function determines whether the specified point is inside the specified region.

## Parameters

### `hrgn` [in]

Handle to the region to be examined.

### `x` [in]

Specifies the x-coordinate of the point in logical units.

### `y` [in]

Specifies the y-coordinate of the point in logical units.

## Return value

If the specified point is in the region, the return value is nonzero.

If the specified point is not in the region, the return value is zero.

## See also

[RectInRegion](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-rectinregion)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)