# MonitorFromPoint function

## Description

The **MonitorFromPoint** function retrieves a handle to the display monitor that contains a specified point.

## Parameters

### `pt` [in]

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that specifies the point of interest in virtual-screen coordinates.

### `dwFlags` [in]

Determines the function's return value if the point is not contained within any display monitor.

This parameter can be one of the following values.

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| Value | Meaning || **MONITOR_DEFAULTTONULL**<br><br>0x00000000 | Returns **NULL**. |
| **MONITOR_DEFAULTTOPRIMARY**<br><br>0x00000001 | Returns a handle to the primary display monitor. |

| **MONITOR_DEFAULTTONEAREST**<br><br>0x00000002 | Returns a handle to the display monitor that is nearest to the point. |

## Return value

If the point is contained by a display monitor, the return value is an **HMONITOR** handle to that display monitor.

If the point is not contained by a display monitor, the return value depends on the value of *dwFlags*.

## See also

[MonitorFromRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfromrect)

[MonitorFromWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-monitorfromwindow)

[Multiple Display Monitors Functions](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-functions)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)