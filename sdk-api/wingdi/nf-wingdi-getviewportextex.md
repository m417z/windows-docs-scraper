# GetViewportExtEx function

## Description

The **GetViewportExtEx** function retrieves the x-extent and y-extent of the current viewport for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lpsize` [out]

A pointer to a [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure that receives the x- and y-extents, in device units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwindowextex)

[SetViewportExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportextex)

[SetWindowExtEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindowextex)