# LPtoDP function

## Description

The **LPtoDP** function converts logical coordinates into device coordinates. The conversion depends on the mapping mode of the device context, the settings of the origins and extents for the window and viewport, and the world transformation.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lppt` [in, out]

A pointer to an array of [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structures. The x-coordinates and y-coordinates contained in each of the **POINT** structures will be transformed.

### `c` [in]

The number of points in the array.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **LPtoDP** function fails if the logical coordinates exceed 32 bits, or if the converted device coordinates exceed 27 bits. In the case of such an overflow, the results for all the points are undefined.

**LPtoDP** calculates complex floating-point arithmetic, and it has a caching system for efficiency. Therefore, the conversion result of an initial call to **LPtoDP** might not exactly match the conversion result of a later call to **LPtoDP**. We recommend not to write code that relies on the exact match of the conversion results from multiple calls to **LPtoDP** even if the parameters that are passed to each call are identical.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[DPtoLP](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-dptolp)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)