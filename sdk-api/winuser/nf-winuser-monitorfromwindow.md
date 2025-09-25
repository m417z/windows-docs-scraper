# MonitorFromWindow function

## Description

The **MonitorFromWindow** function retrieves a handle to the display monitor that has the largest area of intersection with the bounding rectangle of a specified window.

## Parameters

### `hwnd` [in]

A handle to the window of interest.

### `dwFlags` [in]

Determines the function's return value if the window does not intersect any display monitor.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MONITOR_DEFAULTTONEAREST** | Returns a handle to the display monitor that is nearest to the window. |
| **MONITOR_DEFAULTTONULL** | Returns **NULL**. |
| **MONITOR_DEFAULTTOPRIMARY** | Returns a handle to the primary display monitor. |

## Return value

If the window intersects one or more display monitor rectangles, the return value is an **HMONITOR** handle to the display monitor that has the largest area of intersection with the window.

If the window does not intersect a display monitor, the return value depends on the value of *dwFlags*.

## Remarks

If the window is currently minimized, **MonitorFromWindow** uses the rectangle of the window before it was minimized.

## See also

[MonitorFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfrompoint)

[MonitorFromRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfromrect)

[Multiple Display Monitors Functions](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-functions)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)