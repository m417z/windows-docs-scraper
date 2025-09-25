# TIMERPROC callback function

## Description

An application-defined callback function that processes [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) messages. The
**TIMERPROC** type defines a pointer to this callback function. *TimerProc* is a placeholder for the application-defined function name.

## Parameters

### `hWnd`

Type: **HWND**

A handle to the window associated with the timer.

### `uMsg`

Type: **UINT**

The [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) message.

### `nIDEvent`

Type: **UINT_PTR**

The timer's identifier.

### `dwTime`

Type: **DWORD**

The number of milliseconds that have elapsed since the system was started. This is the value returned by the [GetTickCount](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount) function.

## See also

**Conceptual**

[KillTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-killtimer)

**Reference**

[SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer)

[Timers](https://learn.microsoft.com/windows/desktop/winmsg/timers)

[WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer)