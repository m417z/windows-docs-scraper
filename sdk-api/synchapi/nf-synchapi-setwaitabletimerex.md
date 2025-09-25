# SetWaitableTimerEx function

## Description

Activates the specified waitable timer and provides context information for the timer. When the due time arrives, the timer is signaled and the thread that set the timer calls the optional completion routine.

## Parameters

### `hTimer` [in]

A handle to the timer object. The [CreateWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-createwaitabletimerexw) or [OpenWaitableTimer](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-openwaitabletimerw) function returns this handle.

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
**SetWaitableTimerEx**. If *lPeriod* is less than zero, the function fails.

### `pfnCompletionRoutine` [in]

A pointer to an optional completion routine. The completion routine is application-defined function of type **PTIMERAPCROUTINE** to be executed when the timer is signaled. For more information on the timer callback function, see
[TimerAPCProc](https://learn.microsoft.com/windows/desktop/api/synchapi/nc-synchapi-ptimerapcroutine). For more information about APCs and thread pool threads, see Remarks.

### `lpArgToCompletionRoutine` [in]

A pointer to a structure that is passed to the completion routine.

### `WakeContext` [in]

Pointer to a [REASON_CONTEXT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-reason_context) structure that contains context information for the timer.

### `TolerableDelay` [in]

The tolerable delay for expiration time, in milliseconds.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **SetWaitableTimerEx** function is similar to the [SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer) function, except **SetWaitableTimerEx** can be used to specify a context string and a tolerable delay for expiration of the timer.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0601 or later. For more information, see [Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

Timers are initially inactive. To activate a timer, call
**SetWaitableTimerEx**. If the timer is already active when you call
**SetWaitableTimerEx**, the timer is stopped, then it is reactivated. Stopping the timer in this manner does not set the timer state to signaled, so threads blocked in a wait operation on the timer remain blocked. However, it does cancel any pending completion routines.

When the specified due time arrives, the timer becomes inactive,
and the optional APC is queued to the thread that set the timer if there is no outstanding APC already queued.
The state of the timer is set to signaled, the timer is reactivated using the specified period, and the thread that set the timer calls the completion routine when it enters an alertable wait state.
For more information, see
[QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc). Note that APCs do not work as well as other signaling mechanisms for thread pool threads because the system controls the lifetime of thread pool threads, so it is possible for a thread to be terminated before the notification is delivered. Instead of using the *pfnCompletionRoutine* parameter or another APC-based signaling mechanism, use a waitable object such as a timer created with [CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer). For I/O, use an I/O completion object created with [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio) or an *hEvent*-based [OVERLAPPED](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-overlapped) structure where the event can be passed to the [SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait) function.

If the thread that set the timer terminates and there is an associated completion routine, the timer is canceled. However, the state of the timer remains unchanged. If there is no completion routine, then terminating the thread has no effect on the timer.

When a manual-reset timer is set to the signaled state, it remains in this state until
**SetWaitableTimerEx** is called to reset the timer. As a result, a periodic manual-reset timer is set to the signaled state when the initial due time arrives and remains signaled until it is reset. When a synchronization timer is set to the signaled state, it remains in this state until a thread completes a wait operation on the timer object.

If the system time is adjusted, the due time of any outstanding absolute timers is adjusted.

If the thread that called **SetWaitableTimerEx** exits, the timer is canceled. This stops the timer before it can be set to the signaled state and cancels outstanding APCs; it does not change the signaled state of the timer.

To use a timer to schedule an event for a window, use the [SetTimer](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-settimer) function.

## See also

[REASON_CONTEXT](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-reason_context)

[SetWaitableTimer](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setwaitabletimer)