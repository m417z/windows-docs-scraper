# GetMonitorInfoA function

## Description

The **GetMonitorInfo** function retrieves information about a display monitor.

## Parameters

### `hMonitor` [in]

A handle to the display monitor of interest.

### `lpmi` [out]

A pointer to a [MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) or [MONITORINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfoexa) structure that receives information about the specified display monitor.

You must set the **cbSize** member of the structure to sizeof(MONITORINFO) or sizeof(MONITORINFOEX) before calling the **GetMonitorInfo** function. Doing so lets the function determine the type of structure you are passing to it.

The [MONITORINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfoexa) structure is a superset of the [MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo) structure. It has one additional member: a string that contains a name for the display monitor. Most applications have no use for a display monitor name, and so can save some bytes by using a **MONITORINFO** structure.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## See also

[MONITORINFO](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfo)

[MONITORINFOEX](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-monitorinfoexa)

[Multiple Display Monitors Functions](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-functions)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)

## Remarks

> [!NOTE]
> The winuser.h header defines GetMonitorInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).