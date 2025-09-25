# CWPSTRUCT structure

## Description

Defines the message parameters passed to a **WH_CALLWNDPROC** hook procedure, [CallWindowProcW function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callwindowprocw)/[CallWindowProcA function](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-callwindowproca).

## Members

### `lParam`

Type: **LPARAM**

Additional information about the message. The exact meaning depends on the **message** value.

### `wParam`

Type: **WPARAM**

Additional information about the message. The exact meaning depends on the **message** value.

### `message`

Type: **UINT**

The message.

### `hwnd`

Type: **HWND**

A handle to the window to receive the message.

## See also

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)