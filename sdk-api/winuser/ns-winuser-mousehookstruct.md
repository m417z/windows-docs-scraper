# MOUSEHOOKSTRUCT structure

## Description

Contains information about a mouse event passed to a **WH_MOUSE** hook procedure, [MouseProc](https://learn.microsoft.com/windows/win32/winmsg/mouseproc).

## Members

### `pt`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

The x- and y-coordinates of the cursor, in screen coordinates.

### `hwnd`

Type: **HWND**

A handle to the window that will receive the mouse message corresponding to the mouse event.

### `wHitTestCode`

Type: **UINT**

The hit-test value. For a list of hit-test values, see the description of the [WM_NCHITTEST](https://learn.microsoft.com/windows/desktop/inputdev/wm-nchittest) message.

### `dwExtraInfo`

Type: **ULONG_PTR**

Additional information associated with the message.

## See also

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

[MouseProc](https://learn.microsoft.com/windows/win32/winmsg/mouseproc)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)

[WM_NCHITTEST](https://learn.microsoft.com/windows/desktop/inputdev/wm-nchittest)