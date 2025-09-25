# ChildWindowFromPointEx function

## Description

Determines which, if any,
of the child windows belonging to the specified parent window contains the specified point.
The function can ignore invisible, disabled, and transparent child windows. The search is
restricted to immediate child windows. Grandchildren and deeper descendants are not searched.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the parent window.

### `pt` [in]

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A structure that defines the
client coordinates (relative to *hwndParent*)
of the point to be checked.

### `flags` [in]

Type: **UINT**

The child windows to be skipped. This parameter can be one or more of the
following values.

| Value | Meaning |
| --- | --- |
| **CWP_ALL**<br><br>0x0000 | Does not skip any child windows |
| **CWP_SKIPDISABLED**<br><br>0x0002 | Skips disabled child windows |
| **CWP_SKIPINVISIBLE**<br><br>0x0001 | Skips invisible child windows |
| **CWP_SKIPTRANSPARENT**<br><br>0x0004 | Skips transparent child windows |

## Return value

Type: **HWND**

The return value is a handle to the first child window that contains
the point and meets the criteria specified by *uFlags*.
If the point is within the parent window but not within any child window that
meets the criteria, the return value is a handle to the parent window. If the
point lies outside the parent window or if the function fails, the return
value is **NULL**.

## Remarks

The system maintains an internal list that contains the handles of the child
windows associated with a parent window. The order of the handles in the list
depends on the Z order of the child windows. If more than one child window
contains the specified point, the system returns a handle to the first window
in the list that contains the point and meets the criteria specified by
*uFlags*.

## See also

**Conceptual**

**Other Resources**

[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)

**Reference**

[WindowFromPoint](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-windowfrompoint)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)