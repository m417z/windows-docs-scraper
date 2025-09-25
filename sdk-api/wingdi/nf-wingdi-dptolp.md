# DPtoLP function

## Description

The **DPtoLP** function converts device coordinates into logical coordinates. The conversion depends on the mapping mode of the device context, the settings of the origins and extents for the window and viewport, and the world transformation.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lppt` [in, out]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures. The x- and y-coordinates contained in each **POINT** structure will be transformed.

### `c` [in]

The number of points in the array.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **DPtoLP** function fails if the device coordinates exceed 27 bits, or if the converted logical coordinates exceed 32 bits. In the case of such an overflow, the results for all the points are undefined.

#### Examples

For an example, see [Using Coordinate Spaces and Transformations](https://learn.microsoft.com/windows/desktop/gdi/using-coordinate-spaces-and-transformations).

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[LPtoDP](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-lptodp)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)