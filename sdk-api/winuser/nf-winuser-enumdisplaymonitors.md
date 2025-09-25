# EnumDisplayMonitors function

## Description

The **EnumDisplayMonitors** function enumerates display monitors (including invisible pseudo-monitors associated with the mirroring drivers) that intersect a region formed by the intersection of a specified clipping rectangle and the visible region of a device context. **EnumDisplayMonitors** calls an application-defined [MonitorEnumProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-monitorenumproc) callback function once for each monitor that is enumerated. Note that [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) (SM_CMONITORS) counts only the display monitors.

## Parameters

### `hdc` [in]

A handle to a display device context that defines the visible region of interest.

If this parameter is **NULL**, the *hdcMonitor* parameter passed to the callback function will be **NULL**, and the visible region of interest is the virtual screen that encompasses all the displays on the desktop.

### `lprcClip` [in]

A pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that specifies a clipping rectangle. The region of interest is the intersection of the clipping rectangle with the visible region specified by *hdc*.

If *hdc* is non-**NULL**, the coordinates of the clipping rectangle are relative to the origin of the *hdc*. If *hdc* is **NULL**, the coordinates are virtual-screen coordinates.

This parameter can be **NULL** if you don't want to clip the region specified by *hdc*.

### `lpfnEnum` [in]

A pointer to a [MonitorEnumProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-monitorenumproc) application-defined callback function.

### `dwData` [in]

Application-defined data that **EnumDisplayMonitors** passes directly to the [MonitorEnumProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-monitorenumproc) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero.

## Remarks

There are two reasons to call the **EnumDisplayMonitors** function:

* You want to draw optimally into a device context that spans several display monitors, and the monitors have different color formats.
* You want to obtain a handle and position rectangle for one or more display monitors.

To determine whether all the display monitors in a system share the same color format, call [GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) (SM_SAMEDISPLAYFORMAT).

You do not need to use the **EnumDisplayMonitors** function when a window spans display monitors that have different color formats. You can continue to paint under the assumption that the entire screen has the color properties of the primary monitor. Your windows will look fine. **EnumDisplayMonitors** just lets you make them look better.

Setting the *hdc* parameter to **NULL** lets you use the **EnumDisplayMonitors** function to obtain a handle and position rectangle for one or more display monitors. The following table shows how the four combinations of **NULL** and non-**NULL***hdc* and *lprcClip* values affect the behavior of the **EnumDisplayMonitors** function.

| *hdc* | *lprcRect* | EnumDisplayMonitors behavior |
| --- | --- | --- |
| **NULL** | **NULL** | Enumerates all display monitors.The callback function receives a **NULL** HDC. |
| **NULL** | non-**NULL** | Enumerates all display monitors that intersect the clipping rectangle. Use virtual screen coordinates for the clipping rectangle.The callback function receives a **NULL** HDC. |
| non-**NULL** | **NULL** | Enumerates all display monitors that intersect the visible region of the device context.The callback function receives a handle to a DC for the specific display monitor. |
| non-**NULL** | non-**NULL** | Enumerates all display monitors that intersect the visible region of the device context and the clipping rectangle. Use device context coordinates for the clipping rectangle.The callback function receives a handle to a DC for the specific display monitor. |

#### Examples

To paint in response to a WM_PAINT message, using the capabilities of each monitor, you can use code like this in a window procedure:

```

case WM_PAINT:
  hdc = BeginPaint(hwnd, &ps);
  EnumDisplayMonitors(hdc, NULL, MyPaintEnumProc, 0);
  EndPaint(hwnd, &ps);

```

To paint the top half of a window using the capabilities of each monitor, you can use code like this:

```

GetClientRect(hwnd, &rc);
rc.bottom = (rc.bottom - rc.top) / 2;
hdc = GetDC(hwnd);
EnumDisplayMonitors(hdc, &rc, MyPaintEnumProc, 0);
ReleaseDC(hwnd, hdc);

```

To paint the entire virtual screen optimally for each display monitor, you can use code like this:

```

hdc = GetDC(NULL);
EnumDisplayMonitors(hdc, NULL, MyPaintScreenEnumProc, 0);
ReleaseDC(NULL, hdc);

```

To retrieve information about all of the display monitors, use code like this:

```

EnumDisplayMonitors(NULL, NULL, MyInfoEnumProc, 0);

```

## See also

[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics)

[MonitorEnumProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-monitorenumproc)

[Multiple Display Monitors Functions](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors-functions)

[Multiple Display Monitors Overview](https://learn.microsoft.com/windows/desktop/gdi/multiple-display-monitors)