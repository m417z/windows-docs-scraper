# MonitorFromRect function

## Description

The **MonitorFromRect** function retrieves a handle to the display monitor that has the largest area of intersection with a specified rectangle.

## Parameters

### `lprc` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the rectangle of interest in virtual-screen coordinates.

### `dwFlags` [in]

Determines the function's return value if the rectangle does not intersect any display monitor.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **MONITOR_DEFAULTTONEAREST** | Returns a handle to the display monitor that is nearest to the rectangle. |
| **MONITOR_DEFAULTTONULL** | Returns **NULL**. |
| **MONITOR_DEFAULTTOPRIMARY** | Returns a handle to the primary display monitor. |

## Return value

If the rectangle intersects one or more display monitor rectangles, the return value is an **HMONITOR** handle to the display monitor that has the largest area of intersection with the rectangle.

If the rectangle does not intersect a display monitor, the return value depends on the value of *dwFlags*.

## See also

[MonitorFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfrompoint)

[MonitorFromWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfromwindow)

[Multiple Display Monitors Functions](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-functions)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)