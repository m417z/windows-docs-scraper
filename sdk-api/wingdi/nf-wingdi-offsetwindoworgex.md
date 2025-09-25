# OffsetWindowOrgEx function

## Description

The **OffsetWindowOrgEx** function modifies the window origin for a device context using the specified horizontal and vertical offsets.

## Parameters

### `hdc` [in]

A handle to the device context.

### `x` [in]

The horizontal offset, in logical units.

### `y` [in]

The vertical offset, in logical units.

### `lppt` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure. The logical coordinates of the previous window origin are placed in this structure. If *lpPoint* is **NULL**, the previous origin is not returned.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getviewportorgex)

[OffsetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-offsetviewportorgex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)