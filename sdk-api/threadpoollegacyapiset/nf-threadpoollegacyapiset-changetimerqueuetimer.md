# ChangeTimerQueueTimer function

## Description

Updates a timer-queue timer that was created by the
[CreateTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueuetimer) function.

## Parameters

### `TimerQueue` [in, optional]

A handle to the timer queue. This handle is returned by the
[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue) function.

If this parameter is **NULL**, the timer is associated with the default timer queue.

### `Timer` [in, out]

A handle to the timer-queue timer. This handle is returned by the
[CreateTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueuetimer) function.

### `DueTime` [in]

The time after which the timer should expire, in milliseconds.

### `Period` [in]

The period of the timer, in milliseconds. If this parameter is zero, the timer is signaled once. If this parameter is greater than zero, the timer is periodic. A periodic timer automatically reactivates each time the period elapses, until the timer is canceled using the
[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer) function or reset using
**ChangeTimerQueueTimer**.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

This function cannot be called while the thread is using impersonation. The resulting behavior is undefined.

You can call
**ChangeTimerQueueTimer** in a timer callback.

If you call
**ChangeTimerQueueTimer** on a one-shot timer (its period is zero) that has already expired, the timer is not updated.

Do not call
**ChangeTimerQueueTimer** after calling
[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer) on a handle.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue)

[CreateTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueuetimer)

[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)

[Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/timer-queues)