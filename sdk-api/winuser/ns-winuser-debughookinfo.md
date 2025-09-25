# DEBUGHOOKINFO structure

## Description

Contains debugging information passed to a **WH_DEBUG** hook procedure, [*DebugProc*](https://learn.microsoft.com/windows/win32/winmsg/debugproc).

## Members

### `idThread`

Type: **DWORD**

A handle to the thread containing the filter function.

### `idThreadInstaller`

Type: **DWORD**

A handle to the thread that installed the debugging filter function.

### `lParam`

Type: **LPARAM**

The value to be passed to the hook in the *lParam* parameter of the [*DebugProc*](https://learn.microsoft.com/windows/win32/winmsg/debugproc) callback function.

### `wParam`

Type: **WPARAM**

The value to be passed to the hook in the *wParam* parameter of the [*DebugProc*](https://learn.microsoft.com/windows/win32/winmsg/debugproc) callback function.

### `code`

Type: **int**

The value to be passed to the hook in the *nCode* parameter of the [*DebugProc*](https://learn.microsoft.com/windows/win32/winmsg/debugproc) callback function.

## See also

[*DebugProc*](https://learn.microsoft.com/windows/win32/winmsg/debugproc)

[Hooks](https://learn.microsoft.com/windows/desktop/winmsg/hooks)

[SetWindowsHookEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setwindowshookexa)