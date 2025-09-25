# ExitWindows macro

## Syntax

```cpp
BOOL ExitWindows(
    DWORD dwReserved,
    UINT Code
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the call succeeds, the return value is nonzero. If the call fails, the return value is zero. To get extended error information, call **GetLastError**.

## Description

Calls the [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) function to log off the interactive user. Applications should call [ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex) directly.

## Parameters

### `dwReserved`

This parameter must be zero.

### `Code`

This parameter must be zero.

## Remarks

The system sends a [WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) to the main window of each running application.

An application agrees to terminate by returning **TRUE** when it receives this message (or by allowing the
[DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca) function to process the message). If any application returns **FALSE** when it receives the
[WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) message, the logoff is canceled.

After the system processes the results of the
[WM_QUERYENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-queryendsession) message, it sends the
[WM_ENDSESSION](https://learn.microsoft.com/windows/desktop/Shutdown/wm-endsession) message with the *wParam* parameter set to **TRUE** if the system is shutting down and to **FALSE** if it is not.

#### Examples

For an example, see
[How to Log Off the Current User](https://learn.microsoft.com/windows/desktop/Shutdown/how-to-log-off-the-current-user).

## See also

[DefWindowProc](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-defwindowproca)

[ExitWindowsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-exitwindowsex)

[Logging Off](https://learn.microsoft.com/windows/desktop/Shutdown/logging-off)

[System Shutdown
Functions](https://learn.microsoft.com/windows/desktop/Shutdown/system-shutdown-functions)