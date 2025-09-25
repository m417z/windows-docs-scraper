# GetCurrentPositionEx function

## Description

The **GetCurrentPositionEx** function retrieves the current position in logical coordinates.

## Parameters

### `hdc` [in]

A handle to the device context.

### `lppt` [out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that receives the logical coordinates of the current position.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[MoveToEx](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-movetoex)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)