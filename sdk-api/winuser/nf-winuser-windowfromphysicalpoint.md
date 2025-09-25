# WindowFromPhysicalPoint function

## Description

Retrieves a handle to the window that contains the specified physical point.

## Parameters

### `Point` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The physical coordinates of the point.

## Return value

Type: **HWND**

A handle to the window that contains the given physical point. If no window exists at the point, this value is **NULL**.

## Remarks

The **WindowFromPhysicalPoint** function does not retrieve a handle to a hidden or disabled window, even if the point is within the window.

## See also

[ChildWindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-childwindowfrompoint)

**Conceptual**

**Other Resources**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**

[WindowFromDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-windowfromdc)

[WindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-windowfrompoint)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)