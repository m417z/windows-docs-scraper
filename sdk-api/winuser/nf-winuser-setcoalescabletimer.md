# SetCoalescableTimer function

## Description

Creates a timer with the specified time-out value and coalescing tolerance delay.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the window to be associated with the timer. This window must be owned by the calling thread. If a **NULL** value for *hWnd* is passed in along with an *nIDEvent* of an existing timer, that timer will be replaced in the same way that an existing non-NULL *hWnd* timer will be.

### `nIDEvent` [in]

Type: **UINT_PTR**

A timer identifier. If the *hWnd* parameter is **NULL**, and the *nIDEvent* does not match an existing timer, then the *nIDEvent* is ignored and a new timer ID is generated. If the *hWnd* parameter is not **NULL** and the window specified by *hWnd* already has a timer with the value *nIDEvent*, then the existing timer is replaced by the new timer. When **SetCoalescableTimer** replaces a timer, the timer is reset. Therefore, a message will be sent after the current time-out value elapses, but the previously set time-out value is ignored. If the call is not intended to replace an existing timer, *nIDEvent* should be 0 if the *hWnd* is **NULL**.

### `uElapse` [in]

Type: **UINT**

The time-out value, in milliseconds.

 If *uElapse* is less than **USER_TIMER_MINIMUM** (0x0000000A), the timeout is set to **USER_TIMER_MINIMUM**. If *uElapse* is greater than **USER_TIMER_MAXIMUM** (0x7FFFFFFF), the timeout is set to **USER_TIMER_MAXIMUM**.

If the sum of *uElapse* and *uToleranceDelay* exceeds **USER_TIMER_MAXIMUM**, an ERROR_INVALID_PARAMETER exception occurs.

### `lpTimerFunc` [in, optional]

Type: **TIMERPROC**

A pointer to the function to be notified when the time-out value elapses. For more information about the function, see [TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc). If *lpTimerFunc* is **NULL**, the system posts a [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) message to the application queue. The **hwnd** member of the message's [MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg) structure contains the value of the *hWnd* parameter.

### `uToleranceDelay` [in]

Type: **ULONG**

It can be one of the following values:

| Value | Meaning |
| --- | --- |
| **TIMERV_DEFAULT_COALESCING**<br><br>0x00000000 | Uses the system default timer coalescing. |
| **TIMERV_NO_COALESCING**<br><br>0xFFFFFFFF | Uses no timer coalescing. When this value is used, the created timer is not coalesced, no matter what the system default timer coalescing is or the application compatibility flags are.<br><br>**Note** Do not use this value unless you are certain that the timer requires no coalescing. |
| 0x1 - 0x7FFFFFF5 | Specifies the coalescing tolerance delay, in milliseconds. <br><br>Applications should set this value to the system default (**TIMERV_DEFAULT_COALESCING**) or the largest value possible. <br><br>If the sum of *uElapse* and *uToleranceDelay* exceeds **USER_TIMER_MAXIMUM** (0x7FFFFFFF), an ERROR_INVALID_PARAMETER exception occurs.<br><br>See [Windows Timer Coalescing](https://download.microsoft.com/download/9/C/5/9C5B2167-8017-4BAE-9FDE-D599BAC8184A/TimerCoal.docx) for more details and best practices. |
| **Any other value** | An invalid value. If *uToleranceDelay* is set to an invalid value, the function fails and returns zero. |

## Return value

Type: **UINT_PTR**

If the function succeeds and the *hWnd* parameter is **NULL**, the return value is an integer identifying the new timer. An application can pass this value to the [KillTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-killtimer) function to destroy the timer.

If the function succeeds and the *hWnd* parameter is not **NULL**, then the return value is a nonzero integer. An application can pass the value of the *nIDEvent* parameter to the [KillTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-killtimer) function to destroy the timer.

If the function fails to create a timer, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

An application can process [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) messages by including a **WM_TIMER** case statement in the window procedure or by specifying a [TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc) callback function when creating the timer. When you specify a **TimerProc** callback function, the default window procedure calls the callback function when it processes **WM_TIMER**. Therefore, you need to dispatch messages in the calling thread, even when you use **TimerProc** instead of processing **WM_TIMER**.

The *wParam* parameter of the [WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer) message contains the value of the *nIDEvent* parameter.

The timer identifier, *nIDEvent*, is specific to the associated window. Another window can have its own timer which has the same identifier as a timer owned by another window. The timers are distinct.

[SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer) can reuse timer IDs in the case where *hWnd* is **NULL**.

When *uToleranceDelay* is set to 0, the system default timer coalescing is used and **SetCoalescableTimer** behaves the same as [SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer).

Before using **SetCoalescableTimer** or other timer-related functions, it is recommended to set the **UOI_TIMERPROC_EXCEPTION_SUPPRESSION** flag to **false** through the **SetUserObjectInformationW** function, otherwise the application could behave unpredictably and could be vulnerable to security exploits. For more info, see [SetUserObjectInformationW](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-setuserobjectinformationw).

## See also

[Coalescing timers sample](https://github.com/microsoftarchive/msdn-code-gallery-microsoft/tree/master/Official%20Windows%20Platform%20Sample/Windows%208.1%20desktop%20samples/99647-Windows%208.1%20desktop%20samples/Coalescing%20timers%20sample/C%2B%2B)

**Conceptual**

[KeSetCoalescableTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-kesetcoalescabletimer)

[KeSetTimer](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/nf-wdm-kesettimerex)

[KillTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-killtimer)

[MSG](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msg)

**Reference**

**Sample**

[SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer)

[TimerProc](https://learn.microsoft.com/windows/desktop/api/winuser/nc-winuser-timerproc)

[Timers](https://learn.microsoft.com/windows/desktop/winmsg/timers)

[Using Timers](https://learn.microsoft.com/windows/desktop/winmsg/using-timers)

[WM_TIMER](https://learn.microsoft.com/windows/desktop/winmsg/wm-timer)