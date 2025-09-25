# OffsetViewportOrgEx function

## Description

The **OffsetViewportOrgEx** function modifies the viewport origin for a device context using the specified horizontal and vertical offsets.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The horizontal offset, in device units.

### `y` [in]

The vertical offset, in device units.

### `lppt` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure. The previous viewport origin, in device units, is placed in this structure. If *lpPoint* is **NULL**, the previous viewport origin is not returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The new origin is the sum of the current origin and the horizontal and vertical offsets.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getviewportorgex)

[OffsetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-offsetwindoworgex)

[SetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportorgex)