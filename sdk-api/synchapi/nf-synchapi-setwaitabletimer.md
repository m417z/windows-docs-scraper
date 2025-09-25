# SetWaitableTimer function

## Description

Activates the specified waitable timer. When the due time arrives, the timer is signaled and the thread that set the timer calls the optional completion routine.

## Parameters

### `hTimer` [in]

A handle to the timer object. The
[CreateWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createwaitabletimerw) or
[OpenWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openwaitabletimerw) function returns this handle.

The handle must have the **TIMER_MODIFY_STATE** access right. For more information, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

### `lpDueTime` [in]

The time after which the state of the timer is to be set to signaled, in 100 nanosecond intervals. Use the format described by the
[FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure. Positive values indicate absolute time. Be sure to use a UTC-based absolute time, as the system uses UTC-based time internally. Negative values indicate relative time. The actual timer accuracy depends on the capability of your hardware. For more information about UTC-based time, see
[System Time](https://learn.microsoft.com/windows/desktop/SysInfo/system-time).

**Windows XP, Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008 and Windows Server 2008 R2:** If relative time is specified, the timer includes time spent in low-power states. For example, the timer continues counting down while the computer is asleep.

**Windows 8 and newer, Windows Server 2012 and newer:** If relative time is specified, the timer does not include time spent in low-power states. For example, the timer does not continue counting down while the computer is asleep.

### `lPeriod` [in]

The period of the timer, in milliseconds. If *lPeriod* is zero, the timer is signaled once. If *lPeriod* is greater than zero, the timer is periodic. A periodic timer automatically reactivates each time the period elapses, until the timer is canceled using the
[CancelWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-cancelwaitabletimer) function or reset using
**SetWaitableTimer**. If *lPeriod* is less than zero, the function fails.

### `pfnCompletionRoutine` [in, optional]

A pointer to an optional completion routine. The completion routine is application-defined function of type **PTIMERAPCROUTINE** to be executed when the timer is signaled. For more information on the timer callback function, see
[TimerAPCProc](https://learn.microsoft.com/windows/desktop/api/synchapi/nc-synchapi-ptimerapcroutine). For more information about APCs and thread pool threads, see Remarks.

### `lpArgToCompletionRoutine` [in, optional]

A pointer to a structure that is passed to the completion routine.

### `fResume` [in]

If this parameter is **TRUE**, restores a system in suspended power conservation mode when the timer state is set to signaled. Otherwise, the system is not restored. If the system does not support a restore, the call succeeds, but [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_NOT_SUPPORTED**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Timers are initially inactive. To activate a timer, call
**SetWaitableTimer**. If the timer is already active when you call
**SetWaitableTimer**, the timer is stopped, then it is reactivated. Stopping the timer in this manner does not set the timer state to signaled, so threads blocked in a wait operation on the timer remain blocked. However, it does cancel any pending completion routines.

When the specified due time arrives, the timer becomes inactive,
and the optional APC is queued to the thread that set the timer if there is no outstanding APC already queued.
The state of the timer is set to signaled, the timer is reactivated using the specified period, and the thread that set the timer calls the completion routine when it enters an alertable wait state.
For more information, see
[QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc). Note that APCs do not work as well as other signaling mechanisms for thread pool threads because the system controls the lifetime of thread pool threads, so it is possible for a thread to be terminated before the notification is delivered. Instead of using the *pfnCompletionRoutine* parameter or another APC-based signaling mechanism, use a waitable object such as a timer created with [CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer). For I/O, use an I/O completion object created with [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio) or an *hEvent*-based [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure where the event can be passed to the [SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait) function.

If the thread that set the timer terminates and there is an associated completion routine, the timer is canceled. However, the state of the timer remains unchanged. If there is no completion routine, then terminating the thread has no effect on the timer.

When a manual-reset timer is set to the signaled state, it remains in this state until
**SetWaitableTimer** is called to reset the timer. As a result, a periodic manual-reset timer is set to the signaled state when the initial due time arrives and remains signaled until it is reset. When a synchronization timer is set to the signaled state, it remains in this state until a thread completes a wait operation on the timer object.

If the system time is adjusted, the due time of any outstanding absolute timers is adjusted.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

To use a timer to schedule an event for a window, use the [SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer) function.

APIs that deal with timers use various different hardware clocks. These clocks may have resolutions significantly different from what you expect: some may be measured in milliseconds (for those that use an RTC-based timer chip), to those measured in nanoseconds (for those that use ACPI or TSC counters). You can change the resolution of your API with a call to the [timeBeginPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timebeginperiod) and [timeEndPeriod](https://learn.microsoft.com/windows/desktop/api/timeapi/nf-timeapi-timeendperiod) functions. How precise you can change the resolution depends on which hardware clock the particular API uses. For more information, check your hardware documentation.

#### Examples

For an example that uses
**SetWaitableTimer**, see
[Using Waitable Timer Objects](https://learn.microsoft.com/windows/desktop/Sync/using-waitable-timer-objects).

## See also

[CancelWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-cancelwaitabletimer)

[CreateWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerw)

[OpenWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openwaitabletimerw)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[TimerAPCProc](https://learn.microsoft.com/windows/desktop/api/synchapi/nc-synchapi-ptimerapcroutine)

[Waitable Timer Objects](https://learn.microsoft.com/windows/desktop/Sync/waitable-timer-objects)