# GetViewportOrgEx function

## Description

The **GetViewportOrgEx** function retrieves the x-coordinates and y-coordinates of the viewport origin for the specified device context.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lppoint` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the coordinates of the origin, in device units.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[GetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getwindoworgex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[SetViewportOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setviewportorgex)

[SetWindowOrgEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setwindoworgex)