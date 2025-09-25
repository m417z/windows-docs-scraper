# IsWindowVisible function

## Description

Determines the visibility state of the specified window.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window to be tested.

## Return value

Type: **BOOL**

If the specified window, its parent window, its parent's parent window, and so forth, have the **WS_VISIBLE** style, the return value is nonzero. Otherwise, the return value is zero.

Because the return value specifies whether the window has the **WS_VISIBLE** style, it may be nonzero even if the window is totally obscured by other windows.

## Remarks

The visibility state of a window is indicated by the **WS_VISIBLE** style bit. When **WS_VISIBLE** is set, the window is displayed and subsequent drawing into it is displayed as long as the window has the **WS_VISIBLE** style.

Any drawing to a window with the **WS_VISIBLE** style will not be displayed if the window is obscured by other windows or is clipped by its parent window.

## See also

**Conceptual**

**Reference**

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[Windows](https://learn.microsoft.com/windows/desktop/winmsg/windows)