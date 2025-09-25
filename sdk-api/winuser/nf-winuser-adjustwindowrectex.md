# AdjustWindowRectEx function

## Description

Calculates the required size of the window rectangle, based on the desired size of the client rectangle. The window rectangle can then be passed to the [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function to create a window whose client area is the desired size.

## Parameters

### `lpRect` [in, out]

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the coordinates of the top-left and bottom-right corners of the desired client area. When the function returns, the structure contains the coordinates of the top-left and bottom-right corners of the window to accommodate the desired client area.

### `dwStyle` [in]

Type: **DWORD**

The [window style](https://learn.microsoft.com/windows/desktop/winmsg/window-styles) of the window whose required size is to be calculated. Note that you cannot specify the **WS_OVERLAPPED** style.

### `bMenu` [in]

Type: **BOOL**

Indicates whether the window has a menu.

### `dwExStyle` [in]

Type: **DWORD**

The [extended window style](https://learn.microsoft.com/windows/desktop/winmsg/extended-window-styles) of the window whose required size is to be calculated.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A client rectangle is the smallest rectangle that completely encloses a client area. A window rectangle is the smallest rectangle that completely encloses the window, which includes the client area and the nonclient area.

The **AdjustWindowRectEx** function does not add extra space when a menu bar wraps to two or more rows.

The **AdjustWindowRectEx** function does not take the **WS_VSCROLL** or **WS_HSCROLL** styles into account. To account for the scroll bars, call the [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function with **SM_CXVSCROLL** or **SM_CYHSCROLL**.

This API is not DPI aware, and should not be used if the calling thread is per-monitor DPI aware. For the DPI-aware version of this API, see [AdjustWindowsRectExForDPI](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-adjustwindowrectexfordpi). For more information on DPI awareness, see [the Windows High DPI documentation.](https://learn.microsoft.com/windows/desktop/hidpi/high-dpi-desktop-application-development-on-windows)

## See also

[AdjustWindowsRectExForDPI](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-adjustwindowrectexfordpi)

**Conceptual**

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

**Other Resources**

[RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)