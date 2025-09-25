# ChildWindowFromPoint function

## Description

Determines which, if any,
of the child windows belonging to a parent window contains the specified point.
The search is restricted to immediate child windows. Grandchildren, and deeper
descendant windows are not searched.

To skip certain child windows, use the [ChildWindowFromPointEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-childwindowfrompointex) function.

## Parameters

### `hWndParent` [in]

Type: **HWND**

A handle to the parent window.

### `Point` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A structure that defines the client
coordinates, relative to *hWndParent*,
of the point to be checked.

## Return value

Type: **HWND**

The return value is a handle to the child window that contains the point,
even if the child window is hidden or disabled. If the point lies outside the
parent window, the return value is **NULL**. If the point is within
the parent window but not within any child window, the return value is a handle
to the parent window.

## Remarks

The system maintains an internal list, containing the handles of the child windows
associated with a parent window. The order of the handles in the list depends on the Z
order of the child windows. If more than one child window contains the specified point,
the system returns a handle to the first window in the list that contains the point.

**ChildWindowFromPoint** treats an **HTTRANSPARENT** area of a standard
control the same as other parts of the control. In contrast,
[RealChildWindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-realchildwindowfrompoint) treats an **HTTRANSPARENT** area differently;
it returns the child window behind a transparent area of a control. For example, if the
point is in a transparent area of a groupbox, **ChildWindowFromPoint**
returns the groupbox while **RealChildWindowFromPoint** returns the
child window behind the groupbox. However, both APIs return
a static field, even though it, too, returns **HTTRANSPARENT**.

#### Examples

For an example, see "Creating a Combo Box Toolbar" in [Using Combo Boxes](https://learn.microsoft.com/windows/desktop/Controls/using-combo-boxes).

## See also

[ChildWindowFromPointEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-childwindowfrompointex)

**Conceptual**

**Other Resources**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

[RealChildWindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-realchildwindowfrompoint)

**Reference**

[WindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-windowfrompoint)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)