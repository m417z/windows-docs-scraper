# DeleteTimerQueueTimer function

## Description

Removes a timer from the timer queue and optionally waits for currently running timer callback functions to complete before deleting the timer.

## Parameters

### `TimerQueue` [in, optional]

A handle to the timer queue. This handle is returned by the
[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue) function.

If the timer was created using the default timer queue, this parameter should be **NULL**.

### `Timer` [in]

A handle to the timer-queue timer. This handle is returned by the
[CreateTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueuetimer) function.

### `CompletionEvent` [in, optional]

A handle to the event object to be signaled when the system has canceled the timer and all callback functions have completed. This parameter can be **NULL**.

If this parameter is **INVALID_HANDLE_VALUE**, the function waits for any running timer callback functions to complete before returning.

If this parameter is **NULL**, the function marks the timer for deletion and returns immediately. If the timer has already expired, the timer callback function will run to completion. However, there is no notification sent when the timer callback function has completed. Most callers should not use this option, and should wait for running timer callback functions to complete so they can perform any needed cleanup.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the error code is **ERROR_IO_PENDING**, it is not necessary to call this function again. For any other error, you should retry the call.

## Remarks

This function cannot be called while the thread is using impersonation. The resulting behavior is undefined.

You can set *CompletionEvent* to **INVALID_HANDLE_VALUE** when calling this function from within the timer callback of another timer as long as the callback function is not executed in the timer thread. However, a deadlock may occur if two callback functions attempt a blocking
**DeleteTimerQueueTimer** call on each others' timers. Furthermore, you cannot make a blocking deletion call on a timer associated with the callback.

Be careful when making a blocking **DeleteTimerQueueTimer** call on a persistent thread. If the timer being deleted was created with **WT_EXECUTEINPERSISTENTTHREAD**, a deadlock may occur.

If there are outstanding callback functions and *CompletionEvent* is **NULL**, the function will fail and set the error code to **ERROR_IO_PENDING**. This indicates that there are outstanding callback functions. Those callbacks either will execute or are in the middle of executing. The timer is cleaned up when the callback function is finished executing.

To cancel all timers in a timer queue, call the
[DeleteTimerQueueEx](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueueex) function.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue)

[CreateTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueuetimer)

[DeleteTimerQueueEx](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueueex)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/timer-queues)