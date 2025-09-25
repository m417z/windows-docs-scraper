# MONITORINFO structure

## Description

The **MONITORINFO** structure contains information about a display monitor.

The
GetMonitorInfo function stores information in a
**MONITORINFO** structure or a
[MONITORINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfoexa) structure.

The
**MONITORINFO** structure is a subset of the
[MONITORINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfoexa) structure. The
**MONITORINFOEX** structure adds a string member to contain a name for the display monitor.

## Members

### `cbSize`

The size of the structure, in bytes.

Set this member to `sizeof ( MONITORINFO )` before calling the [GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa) function. Doing so lets the function determine the type of structure you are passing to it.

### `rcMonitor`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the display monitor rectangle, expressed in virtual-screen coordinates. Note that if the monitor is not the primary display monitor, some of the rectangle's coordinates may be negative values.

### `rcWork`

A [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies the work area rectangle of the display monitor, expressed in virtual-screen coordinates. Note that if the monitor is not the primary display monitor, some of the rectangle's coordinates may be negative values.

### `dwFlags`

A set of flags that represent attributes of the display monitor.

The following flag is defined.

| Value | Meaning |
| --- | --- |
| MONITORINFOF_PRIMARY | This is the primary display monitor. |

## See also

[GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa)

[MONITORINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfoexa)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)

[Multiple Display Monitors Structures](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-structures)