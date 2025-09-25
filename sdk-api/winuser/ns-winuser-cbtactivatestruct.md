# CBTACTIVATESTRUCT structure

## Description

Contains information passed to a **WH_CBT** hook procedure, [CBTProc](https://learn.microsoft.com/windows/win32/winmsg/cbtproc), before a window is activated.

## Members

### `fMouse`

Type: **BOOL**

This member is **TRUE** if a mouse click is causing the activation or **FALSE** if it is not.

### `hWndActive`

Type: **HWND**

A handle to the active window.

## See also

[CBTProc](https://learn.microsoft.com/windows/win32/winmsg/cbtproc)

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)