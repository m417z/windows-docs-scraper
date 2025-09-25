# ScaleViewportExtEx function

## Description

The **ScaleViewportExtEx** function modifies the viewport for a device context using the ratios formed by the specified multiplicands and divisors.

## Parameters

### `hdc` [in]

A handle to the device context.

### `xn` [in]

The amount by which to multiply the current horizontal extent.

### `dx` [in]

The amount by which to divide the current horizontal extent.

### `yn` [in]

The amount by which to multiply the current vertical extent.

### `yd` [in]

The amount by which to divide the current vertical extent.

### `lpsz` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the previous viewport extents, in device units. If *lpSize* is **NULL**, this parameter is not used.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The viewport extents are modified as follows:

```cpp

    xNewVE = (xOldVE * Xnum) / Xdenom
    yNewVE = (yOldVE * Ynum) / Ydenom

```

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getviewportextex)

[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)