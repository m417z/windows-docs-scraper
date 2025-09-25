# PhysicalToLogicalPointForPerMonitorDPI function

## Description

Converts a point in a window from physical coordinates into logical coordinates, regardless of the dots per inch (dpi) awareness of the caller. For more information about DPI awareness levels, see [PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness).

## Parameters

### `hWnd` [in]

A handle to the window whose transform is used for the conversion.

### `lpPoint` [in, out]

A pointer to a [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that specifies the physical/screen coordinates to be converted. The new logical coordinates are copied into this structure if the function succeeds.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise.

## Remarks

In Windows 8, system–DPI aware applications translate between physical and logical space using [PhysicalToLogicalPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-physicaltologicalpoint) and [LogicalToPhysicalPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-logicaltophysicalpoint). In Windows 8.1, the additional virtualization of the system and inter-process communications means that for the majority of applications, you do not need these APIs. As a result, in Windows 8.1, these APIs no longer transform points. The system returns all points to an application in its own coordinate space.
This behavior preserves functionality for the majority of applications, but there are some exceptions in which you must make changes to ensure that the application works as expected.

For example, an application might need to walk the entire window tree of another process and ask the system for DPI-dependent information about the window. By default, the system will return the information based on the DPI awareness of the caller. This is ideal for most applications. However, the caller might need the information based on the DPI awareness of the application associated with the window. This might be necessary because the two applications send DPI-dependent information between each other directly. In this case, the application can use [LogicalToPhysicalPointForPerMonitorDPI](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-logicaltophysicalpointforpermonitordpi) to get physical coordinates and then use **PhysicalToLogicalPointForPerMonitorDPI** to convert the physical coordinates into logical coordinates based on the DPI-awareness of the provided **HWND**.

Consider two applications, one has a [PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness) value of **PROCESS_DPI_UNAWARE** and the other has a value of **PROCESS_PER_MONITOR_AWARE**. The **PROCESS_PER_MONITOR_AWARE** app creates a window on a single monitor where the scale factor is 200% (192 DPI). If both apps call [GetWindowRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getwindowrect) on this window, they will receive different values. The **PROCESS_DPI_UNAWARE** app will receive a rect based on 96 DPI coordinates, while the **PROCESS_PER_MONITOR_AWARE** app will receive coordinates matching the actual DPI of the monitor. If the **PROCESS_DPI_UNAWARE** needs the rect that the system returned to the **PROCESS_PER_MONITOR_AWARE** app, it could call [LogicalToPhysicalPointForPerMonitorDPI](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-logicaltophysicalpointforpermonitordpi) for the corners of its rect and pass in a handle to the **PROCESS_PER_MONITOR_AWARE** app's window. This will return points based on the other app's awareness that can be used to create a rect. This works because since a **PROCESS_PER_MONITOR_AWARE** uses the actual DPI of the monitor, logical and physical coordinates are identical.

## See also

[LogicalToPhysicalPointForPerMonitorDPI](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-logicaltophysicalpointforpermonitordpi)

[PROCESS_DPI_AWARENESS](https://learn.microsoft.com/windows/desktop/api/shellscalingapi/ne-shellscalingapi-process_dpi_awareness)