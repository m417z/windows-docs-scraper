# RealChildWindowFromPoint function

## Description

Retrieves a handle to the child window at the specified point. The search is restricted to immediate child windows; grandchildren and deeper descendant windows are not searched.

## Parameters

### `hwndParent` [in]

Type: **HWND**

A handle to the window whose child is to be retrieved.

### `ptParentClientCoords` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that defines the client coordinates of the point to be checked.

## Return value

Type: **HWND**

The return value is a handle to the child window that contains the specified point.

## Remarks

**RealChildWindowFromPoint** treats **HTTRANSPARENT** areas of a standard control differently from other areas of the control; it returns the child window behind a transparent part of a control. In contrast, [ChildWindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-childwindowfrompoint) treats **HTTRANSPARENT** areas of a control the same as other areas. For example, if the point is in a transparent area of a groupbox, **RealChildWindowFromPoint** returns the child window behind a groupbox, whereas **ChildWindowFromPoint** returns the groupbox. However, both APIs return a static field, even though it, too, returns **HTTRANSPARENT**.

## See also

[ChildWindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-childwindowfrompoint)

**Conceptual**

**Other Resources**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)