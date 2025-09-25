# IsChild function

## Description

Determines whether a window is a child window or descendant window of a specified parent window. A child window is the direct descendant of a specified parent window if that parent window is in the chain of parent windows; the chain of parent windows leads from the original overlapped or pop-up window to the child window.

## Parameters

### `hWndParent` [in]

Type: **HWND**

A handle to the parent window.

### `hWnd` [in]

Type: **HWND**

A handle to the window to be tested.

## Return value

Type: **BOOL**

If the window is a child or descendant window of the specified parent window, the return value is nonzero.

If the window is not a child or descendant window of the specified parent window, the return value is zero.

## See also

**Conceptual**

[IsWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-iswindow)

**Reference**

[SetParent](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setparent)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)