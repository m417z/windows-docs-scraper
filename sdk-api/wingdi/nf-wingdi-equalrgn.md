# EqualRgn function

## Description

The **EqualRgn** function checks the two specified regions to determine whether they are identical. The function considers two regions identical if they are equal in size and shape.

## Parameters

### `hrgn1` [in]

Handle to a region.

### `hrgn2` [in]

Handle to a region.

## Return value

If the two regions are equal, the return value is nonzero.

If the two regions are not equal, the return value is zero. A return value of ERROR means at least one of the region handles is invalid.

## See also

[CreateRectRgn](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgn)

[CreateRectRgnIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createrectrgnindirect)

[Region Functions](https://learn.microsoft.com/windows/desktop/gdi/region-functions)

[Regions Overview](https://learn.microsoft.com/windows/desktop/gdi/regions)