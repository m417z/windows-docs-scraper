# ClientToScreen function

## Description

The **ClientToScreen** function converts the client-area coordinates of a specified point to screen coordinates.

## Parameters

### `hWnd` [in]

A handle to the window whose client area is used for the conversion.

### `lpPoint` [in, out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that contains the client coordinates to be converted. The new screen coordinates are copied into this structure if the function succeeds.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The **ClientToScreen** function replaces the client-area coordinates in the [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure with the screen coordinates. The screen coordinates are relative to the upper-left corner of the screen. Note, a screen-coordinate point that is above the window's client area has a negative y-coordinate. Similarly, a screen coordinate to the left of a client area has a negative x-coordinate.

All coordinates are device coordinates.

#### Examples

For an example, see "Drawing Lines with the Mouse" in [Using Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/using-mouse-input).

## See also

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[MapWindowPoints](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapwindowpoints)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[ScreenToClient](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-screentoclient)