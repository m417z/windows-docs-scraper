# MONITORENUMPROC callback function

## Description

A **MonitorEnumProc** function is an application-defined callback function that is called by the [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) function.

A value of type **MONITORENUMPROC** is a pointer to a **MonitorEnumProc** function.

## Parameters

### `unnamedParam1`

A handle to the display monitor. This value will always be non-**NULL**.

### `unnamedParam2`

A handle to a device context.

The device context has color attributes that are appropriate for the display monitor identified by *hMonitor*. The clipping area of the device context is set to the intersection of the visible region of the device context identified by the *hdc* parameter of [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors), the rectangle pointed to by the *lprcClip* parameter of **EnumDisplayMonitors**, and the display monitor rectangle.

This value is **NULL** if the *hdc* parameter of [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) was **NULL**.

### `unnamedParam3`

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure.

If *hdcMonitor* is non-**NULL**, this rectangle is the intersection of the clipping area of the device context identified by *hdcMonitor* and the display monitor rectangle. The rectangle coordinates are device-context coordinates.

If *hdcMonitor* is **NULL**, this rectangle is the display monitor rectangle. The rectangle coordinates are virtual-screen coordinates.

### `unnamedParam4`

Application-defined data that [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) passes directly to the enumeration function.

## Return value

To continue the enumeration, return **TRUE**.

To stop the enumeration, return **FALSE**.

## Remarks

You can use the [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) function to enumerate the set of display monitors that intersect the visible region of a specified device context and, optionally, a clipping rectangle. To do this, set the *hdc* parameter to a non-**NULL** value, and set the *lprcClip* parameter as needed.

You can also use the [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) function to enumerate one or more of the display monitors on the desktop, without supplying a device context. To do this, set the *hdc* parameter of **EnumDisplayMonitors** to **NULL** and set the *lprcClip* parameter as needed.

In all cases, [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) calls a specified **MonitorEnumProc** function once for each display monitor in the calculated enumeration set. The **MonitorEnumProc** function always receives a handle to the display monitor.

If the *hdc* parameter of [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) is non-**NULL**, the **MonitorEnumProc** function also receives a handle to a device context whose color format is appropriate for the display monitor. You can then paint into the device context in a manner that is optimal for the display monitor.

## See also

[EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors)

[Multiple Display Monitors Functions](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-functions)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)