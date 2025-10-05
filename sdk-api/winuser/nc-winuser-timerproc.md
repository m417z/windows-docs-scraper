# TIMERPROC callback function

## Description

An application-defined callback function that processes [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) messages. The **TIMERPROC** type defines a pointer to this callback function. _TimerProc_ is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Type: **HWND**

A handle to the window associated with the timer. This parameter is typically named _hWnd_.

### `unnamedParam2`

Type: **UINT**

The [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) message. This parameter is typically named _uMsg_.

### `unnamedParam3`

Type: **UINT_PTR**

The timer's identifier. This parameter is typically named _idEvent_.

### `unnamedParam4`

Type: **DWORD**

The number of milliseconds that have elapsed since the system was started. This is the value returned by the [GetTickCount](https://learn.microsoft.com/windows/desktop/api/sysinfoapi/nf-sysinfoapi-gettickcount) function. This parameter is typically named _dwTime_.

## Remarks

> [!NOTE]
> The parameters are defined in the header with no names: `typedef VOID (CALLBACK* TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);`. Therefore, the syntax block lists them as `unnamedParam1` - `unnamedParam4`. You can name these parameters anything in your app. However, they are usually named as shown in the parameter descriptions.

## See also

**Conceptual**

[Timers](https://learn.microsoft.com/windows/desktop/winmsg/timers)

**Reference**

[KillTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-killtimer)

[SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer)

[WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer)