## Description

Deletes a timer queue. Any pending timers in the queue are canceled and deleted.

**Note** This function is obsolete and has been replaced by the
[DeleteTimerQueueEx](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueueex) function.

## Parameters

### `TimerQueue`

A handle to the timer queue. This handle is returned by the
[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue) function.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**DeleteTimerQueue** does not wait for all callback functions associated with the timer to complete.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example that uses
**DeleteTimerQueue**, see
[Using Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/using-timer-queues).

## See also

[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue)

[DeleteTimerQueueEx](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueueex)

[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)

[Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/timer-queues)