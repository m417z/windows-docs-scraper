# KillTimer function

## Description

Destroys the specified timer.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window associated with the specified timer. This value must be the same as the
*hWnd* value passed to the [SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer) function that created the timer.

### `uIDEvent` [in]

Type: **UINT_PTR**

The timer to be destroyed. If the window handle passed to [SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer) is valid, this parameter must be the same as the
*nIDEvent*

value passed to **SetTimer**. If the application calls **SetTimer** with
*hWnd* set to **NULL**, this parameter must be the timer identifier returned by **SetTimer**.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **KillTimer** function does not remove [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) messages already posted to the message queue.

#### Examples

For an example, see [Destroying a Timer](https://learn.microsoft.com/windows/desktop/winmsg/using-timers).

## See also

**Conceptual**

**Reference**

[SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer)

[Timers](https://learn.microsoft.com/windows/desktop/winmsg/timers)

[WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer)