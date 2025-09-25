# MONITORINFOEXW structure

## Description

The **MONITORINFOEX** structure contains information about a display monitor.

The
[GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa) function stores information into a
**MONITORINFOEX** structure or a
[MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) structure.

The
**MONITORINFOEX** structure is a superset of the
[MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) structure. The
**MONITORINFOEX** structure adds a string member to contain a name for the display monitor.

## Members

### `szDevice`

A string that specifies the device name of the monitor being used. Most applications have no use for a display monitor name, and so can save some bytes by using a [MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) structure.

### `tagMONITORINFO`

## See also

[GetMonitorInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getmonitorinfoa)

[MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)

[Multiple Display Monitors Structures](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-structures)

## Remarks

> [!NOTE]
> The winuser.h header defines MONITORINFOEX as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).