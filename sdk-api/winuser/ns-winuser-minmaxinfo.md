# MINMAXINFO structure

## Description

Contains information about a window's maximized size and position and its minimum and maximum tracking size.

## Members

### `ptReserved`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

Reserved; do not use.

### `ptMaxSize`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The maximized width (**x** member) and the maximized height (**y** member) of the window. For top-level windows, this value is based on the width of the primary monitor.

### `ptMaxPosition`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The position of the left side of the maximized window (**x** member) and the position of the top of the maximized window (**y** member). For top-level windows, this value is based on the position of the primary monitor.

### `ptMinTrackSize`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The minimum tracking width (**x** member) and the minimum tracking height (**y** member) of the window. This value can be obtained programmatically from the system metrics **SM_CXMINTRACK** and **SM_CYMINTRACK** (see the [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function).

### `ptMaxTrackSize`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The maximum tracking width (**x** member) and the maximum tracking height (**y** member) of the window. This value is based on the size of the virtual screen and can be obtained programmatically from the system metrics **SM_CXMAXTRACK** and **SM_CYMAXTRACK** (see the [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function).

## Remarks

For systems with multiple monitors, the **ptMaxSize** and **ptMaxPosition** members describe the maximized size and position of the window on the primary monitor, even if the window ultimately maximizes onto a secondary monitor. In that case, the window manager adjusts these values to compensate for differences between the primary monitor and the monitor that displays the window. Thus, if the user leaves **ptMaxSize** untouched, a window on a monitor larger than the primary monitor maximizes to the size of the larger monitor.

## See also

**Conceptual**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**

[WM_GETMINMAXINFO](https://learn.microsoft.com/windows/desktop/winmsg/wm-getminmaxinfo)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)