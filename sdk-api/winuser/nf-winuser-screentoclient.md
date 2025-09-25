# ScreenToClient function

## Description

The **ScreenToClient** function converts the screen coordinates of a specified point on the screen to client-area coordinates.

## Parameters

### `hWnd` [in]

A handle to the window whose client area will be used for the conversion.

### `lpPoint`

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that specifies the screen coordinates to be converted.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

The function uses the window identified by the *hWnd* parameter and the screen coordinates given in the [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure to compute client coordinates. It then replaces the screen coordinates with the client coordinates. The new coordinates are relative to the upper-left corner of the specified window's client area.

The **ScreenToClient** function assumes the specified point is in screen coordinates.

All coordinates are in device units.

Do not use **ScreenToClient** when in a mirroring situation, that is, when changing from left-to-right layout to right-to-left layout. Instead, use [MapWindowPoints](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapwindowpoints). For more information, see "Window Layout and Mirroring" in [Window Features](https://learn.microsoft.com/windows/desktop/winmsg/window-features).

## See also

[ClientToScreen](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-clienttoscreen)

[Coordinate Space and Transformation Functions](https://learn.microsoft.com/windows/desktop/gdi/coordinate-space-and-transformation-functions)

[Coordinate Spaces and Transformations Overview](https://learn.microsoft.com/windows/desktop/gdi/coordinate-spaces-and-transformations)

[MapWindowPoints](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-mapwindowpoints)

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)