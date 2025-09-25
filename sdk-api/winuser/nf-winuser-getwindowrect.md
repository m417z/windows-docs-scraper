# GetWindowRect function

## Description

Retrieves the dimensions of the bounding rectangle of the specified window. The dimensions are given in screen coordinates that are relative to the upper-left corner of the screen.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window.

### `lpRect` [out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the screen coordinates of the upper-left and lower-right corners of the window.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

In conformance with conventions for the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure, the bottom-right coordinates of the returned rectangle are exclusive. In other words, the pixel at (**right**, **bottom**) lies immediately outside the rectangle.

GetWindowRect is virtualized for DPI.

In Windows Vista and later, the Window Rect now may include invisible resize borders.

To get the visible window bounds, not including the invisible resize borders,
use [DwmGetWindowAttribute](https://learn.microsoft.com/windows/win32/api/dwmapi/nf-dwmapi-dwmgetwindowattribute),
specifying **DWMWA_EXTENDED_FRAME_BOUNDS**. Note that unlike the Window Rect,
the DWM Extended Frame Bounds are not adjusted for DPI.

#### Examples

For an example, see [Initializing a Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

**Conceptual**

[GetClientRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getclientrect)

**Reference**

[ScreenToClient](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-screentoclient)

[SetWindowPos](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowpos)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)