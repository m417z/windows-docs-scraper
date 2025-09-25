# SetRectRgn function

## Description

The **SetRectRgn** function converts a region into a rectangular region with the specified coordinates.

## Parameters

### `hrgn` [in]

Handle to the region.

### `left` [in]

Specifies the x-coordinate of the upper-left corner of the rectangular region in logical units.

### `top` [in]

Specifies the y-coordinate of the upper-left corner of the rectangular region in logical units.

### `right` [in]

Specifies the x-coordinate of the lower-right corner of the rectangular region in logical units.

### `bottom` [in]

Specifies the y-coordinate of the lower-right corner of the rectangular region in logical units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The region does not include the lower and right boundaries of the rectangle.

## See also

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)