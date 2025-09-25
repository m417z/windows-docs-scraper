# SetForegroundWindow function

## Description

Brings the thread that created the specified window into the foreground and activates the window. Keyboard input is directed to the window, and various visual cues are changed for the user. The system assigns a slightly higher priority to the thread that created the foreground window than it does to other threads.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the window that should be activated and brought to the foreground.

## Return value

Type: **BOOL**

If the window was brought to the foreground, the return value is nonzero.

If the window was not brought to the foreground, the return value is zero.

## Remarks

The system restricts which processes can set the foreground window. A process can set the foreground window by calling **SetForegroundWindow** only if:

- All of the following conditions are true:
  - The calling process belongs to a desktop application, not a UWP app or a Windows Store app designed for Windows 8 or 8.1.
  - The foreground process has not disabled calls to **SetForegroundWindow** by a previous call to the [**LockSetForegroundWindow**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-locksetforegroundwindow) function.
  - The foreground lock time-out has expired (see [**SPI_GETFOREGROUNDLOCKTIMEOUT** in **SystemParametersInfo**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-systemparametersinfoa#SPI_GETFOREGROUNDLOCKTIMEOUT)).
  - No menus are active.
- Additionally, at least one of the following conditions is true:
  - The calling process is the foreground process.
  - The calling process was started by the foreground process.
  - There is currently no foreground window, and thus no foreground process.
  - The calling process received the last input event.
  - Either the foreground process or the calling process is being debugged.

It is possible for a process to be denied the right to set the foreground window even if it meets these conditions.

An application cannot force a window to the foreground while the user is working with another window. Instead, Windows flashes the taskbar button of the window to notify the user.

A process that can set the foreground window can enable another process to set the foreground window by calling the [**AllowSetForegroundWindow**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-allowsetforegroundwindow) function. The process specified by the *dwProcessId* parameter to **AllowSetForegroundWindow** loses the ability to set the foreground window the next time that either the user generates input, unless the input is directed at that process, or the next time a process calls **AllowSetForegroundWindow**, unless the same process is specified as in the previous call to **AllowSetForegroundWindow**.

The foreground process can disable calls to **SetForegroundWindow** by calling the [**LockSetForegroundWindow**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-locksetforegroundwindow) function.

## Example

The following code example demonstrates the use of **SetForegroundWindow**

```cpp
// If the window is invisible we will show it and make it topmost without the
// foreground focus. If the window is visible it will also be made the
// topmost window without the foreground focus. If wParam is TRUE then
// for both cases the window will be forced into the foreground focus
if (uMsg == m_ShowStageMessage) {
    BOOL bVisible = IsWindowVisible(hwnd);
    SetWindowPos(hwnd, HWND_TOP, 0, 0, 0, 0,
                    SWP_NOMOVE | SWP_NOSIZE | SWP_SHOWWINDOW |
                    (bVisible ? SWP_NOACTIVATE : 0));
    // Should we bring the window to the foreground
    if (wParam == TRUE) {
        SetForegroundWindow(hwnd);
    }
    return (LRESULT) 1;
}
```

## See also

[AllowSetForegroundWindow](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-allowsetforegroundwindow)

**Conceptual**

[FlashWindowEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-flashwindowex)

[GetForegroundWindow](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getforegroundwindow)

[LockSetForegroundWindow](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-locksetforegroundwindow)

**Reference**

[SetActiveWindow](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setactivewindow)

[Windows](https://learn.microsoft.com/windows/win32/winmsg/windows)