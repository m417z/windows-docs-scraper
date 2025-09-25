# GetClientRect function

## Description

Retrieves the coordinates of a window's client area. The client coordinates specify the upper-left and lower-right corners of the client area. Because client coordinates are relative to the upper-left corner of a window's client area, the coordinates of the upper-left corner are (0,0).

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window whose client coordinates are to be retrieved.

### `lpRect` [out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that receives the client coordinates. The **left** and **top** members are zero. The **right** and **bottom** members contain the width and height of the window.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

In conformance with conventions for the [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure, the bottom-right coordinates of the returned rectangle are exclusive. In other words, the pixel at (**right**, **bottom**) lies immediately outside the rectangle.

#### Examples

For example, see [Creating, Enumerating, and Sizing Child Windows](https://learn.microsoft.com/windows/desktop/winmsg/using-windows).

## See also

**Conceptual**

[GetWindowRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowrect)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)