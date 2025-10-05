# MONITORENUMPROC callback function

## Description

An application-defined callback function used with the [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) function. The **MONITORENUMPROC** type defines a pointer to this callback function. _MonitorEnumProc_ is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Type: **HMONITOR**

A handle to the display monitor. This value will always be non-**NULL**. This parameter is typically named _hMonitor_.

### `unnamedParam2`

Type: **HDC**

A handle to a device context. This parameter is typically named _hdcMonitor_.

The device context has color attributes that are appropriate for the display monitor identified by _hMonitor_. The clipping area of the device context is set to the intersection of the visible region of the device context identified by the _hdc_ parameter of [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors), the rectangle pointed to by the _lprcClip_ parameter of **EnumDisplayMonitors**, and the display monitor rectangle.

This value is **NULL** if the _hdc_ parameter of [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) was **NULL**.

### `unnamedParam3`

Type: **LPRECT**

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure. This parameter is typically named _lprcMonitor_.

If _hdcMonitor_ is non-**NULL**, this rectangle is the intersection of the clipping area of the device context identified by _hdcMonitor_ and the display monitor rectangle. The rectangle coordinates are device-context coordinates.

If _hdcMonitor_ is **NULL**, this rectangle is the display monitor rectangle. The rectangle coordinates are virtual-screen coordinates.

### `unnamedParam4`

Type: **LPARAM**

Application-defined data that [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) passes directly to the enumeration function. This parameter is typically named _dwData_.

## Return value

Type: **BOOL**

To continue the enumeration, return **TRUE**.

To stop the enumeration, return **FALSE**.

## Remarks

> [!NOTE]
> The parameters are defined in the header with no names: `typedef BOOL (CALLBACK* MONITORENUMPROC)(HMONITOR, HDC, LPRECT, LPARAM);`. Therefore, the syntax block lists them as `unnamedParam1` - `unnamedParam4`. You can name these parameters anything in your app. However, they are usually named as shown in the parameter descriptions.

You can use the [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) function to enumerate the set of display monitors that intersect the visible region of a specified device context and, optionally, a clipping rectangle. To do this, set the _hdc_ parameter to a non-**NULL** value, and set the _lprcClip_ parameter as needed.

You can also use the [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) function to enumerate one or more of the display monitors on the desktop, without supplying a device context. To do this, set the _hdc_ parameter of **EnumDisplayMonitors** to **NULL** and set the _lprcClip_ parameter as needed.

In all cases, [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) calls a specified _MonitorEnumProc_ function once for each display monitor in the calculated enumeration set. The _MonitorEnumProc_ function always receives a handle to the display monitor.

If the _hdc_ parameter of [EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors) is non-**NULL**, the _MonitorEnumProc_ function also receives a handle to a device context whose color format is appropriate for the display monitor. You can then paint into the device context in a manner that is optimal for the display monitor.

## See also

[EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors)

[Multiple Display Monitors Functions](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-functions)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)