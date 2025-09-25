# CreateTimerQueue function

## Description

Creates a queue for timers. Timer-queue timers are lightweight objects that enable you to specify a callback function to be called at a specified time.

## Return value

If the function succeeds, the return value is a handle to the timer queue. This handle can be used only in functions that require a handle to a timer queue.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To add a timer to the queue, call the
[CreateTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueuetimer) function. To remove a timer from the queue, call the
[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer) function.

When you are finished with the queue of timers, call the
[DeleteTimerQueueEx](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueueex) function to delete the timer queue. Any pending timers in the queue are canceled and deleted.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example that uses
**CreateTimerQueue**, see
[Using Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/using-timer-queues).

## See also

[CreateTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueuetimer)

[DeleteTimerQueueEx](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueueex)

[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)

[Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/timer-queues)