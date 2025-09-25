# WindowFromPoint function

## Description

Retrieves a handle to the window that contains the specified point.

## Parameters

### `Point` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The point to be checked.

## Return value

Type: **HWND**

The return value is a handle to the window that contains the point. If no window exists at the given point, the return value is **NULL**. If the point is over a static text control, the return value is a handle to the window under the static text control.

## Remarks

The **WindowFromPoint** function does not retrieve a handle to a hidden or disabled window, even if the point is within the window. An application should use the [ChildWindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-childwindowfrompoint) function for a nonrestrictive search.

#### Examples

For an example, see "Interface from Running Object Table" in [About Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/about-text-object-model).

## See also

[ChildWindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-childwindowfrompoint)

**Conceptual**

**Other Resources**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**

[WindowFromDC](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-windowfromdc)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)