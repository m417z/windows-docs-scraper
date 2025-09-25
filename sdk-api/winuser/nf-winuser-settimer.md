# SetTimer function

## Description

Creates a timer with the specified time-out value.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window to be associated with the timer. This window must be owned by the calling thread. If a **NULL** value for *hWnd* is passed in along with an *nIDEvent* of an existing timer, that timer will be replaced in the same way that an existing non-NULL *hWnd* timer will be.

### `nIDEvent` [in]

Type: **UINT_PTR**

A nonzero timer identifier. If the *hWnd* parameter is **NULL**, and the *nIDEvent* does not match an existing timer then it is ignored and a new timer ID is generated. If the *hWnd* parameter is not **NULL** and the window specified by *hWnd* already has a timer with the value *nIDEvent*, then the existing timer is replaced by the new timer. When **SetTimer** replaces a timer, the timer is reset. Therefore, a message will be sent after the current time-out value elapses, but the previously set time-out value is ignored. If the call is not intended to replace an existing timer, *nIDEvent* should be 0 if the *hWnd* is **NULL**.

### `uElapse` [in]

Type: **UINT**

The time-out value, in milliseconds.

 If *uElapse* is less than **USER_TIMER_MINIMUM** (0x0000000A), the timeout is set to **USER_TIMER_MINIMUM**. If *uElapse* is greater than **USER_TIMER_MAXIMUM** (0x7FFFFFFF), the timeout is set to **USER_TIMER_MAXIMUM**.

### `lpTimerFunc` [in, optional]

Type: **TIMERPROC**

A pointer to the function to be notified when the time-out value elapses. For more information about the function, see [TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc). If *lpTimerFunc* is **NULL**, the system posts a [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) message to the application queue. The **hwnd** member of the message's [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure contains the value of the *hWnd* parameter.

## Return value

Type: **UINT_PTR**

If the function succeeds and the *hWnd* parameter is **NULL**, the return value is an integer identifying the new timer. An application can pass this value to the [KillTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-killtimer) function to destroy the timer.

If the function succeeds and the *hWnd* parameter is not **NULL**, then the return value is a nonzero integer. An application can pass the value of the *nIDEvent* parameter to the [KillTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-killtimer) function to destroy the timer.

If the function fails to create a timer, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application can process [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) messages by including a **WM_TIMER** case statement in the window procedure or by specifying a [TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc) callback function when creating the timer. When you specify a **TimerProc** callback function, the DispatchMessage calls the callback function instead of calling the window procedure when it processes **WM_TIMER** with a non-NULL lParam. Therefore, you need to dispatch messages in the calling thread, even when you use **TimerProc** instead of processing **WM_TIMER**.

The *wParam* parameter of the [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) message contains the value of the *nIDEvent* parameter.

The timer identifier, *nIDEvent*, is specific to the associated window. Another window can have its own timer which has the same identifier as a timer owned by another window. The timers are distinct.

**SetTimer** can reuse timer IDs in the case where *hWnd* is **NULL**.
Before using **SetTimer** or other timer-related functions, it is recommended to set the **UOI_TIMERPROC_EXCEPTION_SUPPRESSION** flag to **false** through the **SetUserObjectInformationW** function, otherwise the application could behave unpredictably and could be vulnerable to security exploits. For more info, see [SetUserObjectInformationW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setuserobjectinformationw).

#### Examples

For an example, see [Creating a Timer](https://learn.microsoft.com/windows/desktop/winmsg/using-timers).

## See also

**Conceptual**

[KillTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-killtimer)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

**Reference**

[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer)

[TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc)

[Timers](https://learn.microsoft.com/windows/desktop/winmsg/timers)

[WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer)

[SetCoalescableTimer](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setcoalescabletimer)