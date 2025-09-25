# DeleteTimerQueueEx function

## Description

Deletes a timer queue. Any pending timers in the queue are canceled and deleted.

## Parameters

### `TimerQueue` [in]

A handle to the timer queue. This handle is returned by the
[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue) function.

### `CompletionEvent` [in, optional]

A handle to the event object to be signaled when the function is successful and all callback functions have completed. This parameter can be **NULL**.

If this parameter is **INVALID_HANDLE_VALUE**, the function waits for all callback functions to complete before returning.

If this parameter is **NULL**, the function marks the timer for deletion and returns immediately. However, most callers should wait for the callback function to complete so they can perform any needed cleanup.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not make blocking calls to
**DeleteTimerQueueEx** from within a timer callback.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue)

[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)

[Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/timer-queues)