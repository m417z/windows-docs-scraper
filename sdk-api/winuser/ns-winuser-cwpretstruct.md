# CWPRETSTRUCT structure

## Description

Defines the message parameters passed to a **WH_CALLWNDPROCRET** hook procedure, [HOOKPROC callback function](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-hookproc).

## Members

### `lResult`

Type: **LRESULT**

The return value of the window procedure that processed the message specified by the
**message** value.

### `lParam`

Type: **LPARAM**

Additional information about the message. The exact meaning depends on the
**message** value.

### `wParam`

Type: **WPARAM**

Additional information about the message. The exact meaning depends on the
**message** value.

### `message`

Type: **UINT**

The message.

### `hwnd`

Type: **HWND**

A handle to the window that processed the message specified by the
**message** value.

## See also

[HOOKPROC](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-hookproc)

**Conceptual**

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

**Reference**

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)