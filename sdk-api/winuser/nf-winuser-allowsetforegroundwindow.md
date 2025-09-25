# AllowSetForegroundWindow function

## Description

Enables the specified process to set the foreground window using the [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) function. The calling process must already be able to set the foreground window. For more information, see Remarks later in this topic.

## Parameters

### `dwProcessId` [in]

Type: **DWORD**

The identifier of the process that will be enabled to set the foreground window. If this parameter is **ASFW_ANY**, all processes will be enabled to set the foreground window.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. The function will fail if the calling process cannot set the foreground window. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The system restricts which processes can set the foreground window. Normally, a process can set the foreground window by calling the [**SetForegroundWindow**](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setforegroundwindow) function only if:

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

A process that can set the foreground window can enable another process to set the foreground window
by calling **AllowSetForegroundWindow**. The process specified by the *dwProcessId* parameter
loses the ability to set the foreground window the next time that either the user generates input,
unless the input is directed at that process, or the next time a process calls
**AllowSetForegroundWindow**, unless the same process is specified as in the previous call to
**AllowSetForegroundWindow**.

## See also

**Conceptual**

[LockSetForegroundWindow](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-locksetforegroundwindow)

**Reference**

[SetForegroundWindow](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setforegroundwindow)

[Windows](https://learn.microsoft.com/windows/win32/winmsg/windows)