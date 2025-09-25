# CreateTimerQueueTimer function

## Description

Creates a timer-queue timer. This timer expires at the specified due time, then after every specified period. When the timer expires, the callback function is called.

## Parameters

### `phNewTimer` [out]

A pointer to a buffer that receives a handle to the timer-queue timer on return. When this handle has expired and is no longer required, release it by calling [DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer).

### `TimerQueue` [in, optional]

A handle to the timer queue. This handle is returned by the
[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue) function.

If this parameter is **NULL**, the timer is associated with the default timer queue.

### `Callback` [in]

A pointer to the application-defined function of type **WAITORTIMERCALLBACK** to be executed when the timer expires. For more information, see
[WaitOrTimerCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms687066(v=vs.85)).

### `Parameter` [in, optional]

A single parameter value that will be passed to the callback function.

### `DueTime` [in]

The amount of time in milliseconds relative to the current time that must elapse before the timer is signaled for the first time.

### `Period` [in]

The period of the timer, in milliseconds. If this parameter is zero, the timer is signaled once. If this parameter is greater than zero, the timer is periodic. A periodic timer automatically reactivates each time the period elapses, until the timer is canceled.

### `Flags` [in]

This parameter can be one or more of the following values from WinNT.h.

| Value | Meaning |
| --- | --- |
| **WT_EXECUTEDEFAULT**<br><br>0x00000000 | By default, the callback function is queued to a non-I/O worker thread. |
| **WT_EXECUTEINTIMERTHREAD**<br><br>0x00000020 | The callback function is invoked by the timer thread itself. This flag should be used only for short tasks or it could affect other timer operations. <br><br>The callback function is queued as an APC. It should not perform alertable wait operations. |
| **WT_EXECUTEINIOTHREAD**<br><br>0x00000001 | This flag is not used.<br><br>**Windows Server 2003 and Windows XP:** The callback function is queued to an I/O worker thread. This flag should be used if the function should be executed in a thread that waits in an alertable state. <br><br>I/O worker threads were removed starting with Windows Vista and Windows Server 2008. |
| **WT_EXECUTEINPERSISTENTTHREAD**<br><br>0x00000080 | The callback function is queued to a thread that never terminates. It does not guarantee that the same thread is used each time. This flag should be used only for short tasks or it could affect other timer operations. <br><br>This flag must be set if the thread calls functions that use APCs. For more information, see [Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls).<br><br>Note that currently no worker thread is truly persistent, although no worker thread will terminate if there are any pending I/O requests. |
| **WT_EXECUTELONGFUNCTION**<br><br>0x00000010 | The callback function can perform a long wait. This flag helps the system to decide if it should create a new thread. |
| **WT_EXECUTEONLYONCE**<br><br>0x00000008 | The timer will be set to the signaled state only once. If this flag is set, the *Period* parameter must be zero. |
| **WT_TRANSFER_IMPERSONATION**<br><br>0x00000100 | Callback functions will use the current access token, whether it is a process or impersonation token. If this flag is not specified, callback functions execute only with the process token.<br><br>**Windows XP:** This flag is not supported until Windows XP with SP2 and Windows Server 2003. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the *DueTime* and *Period* parameters are both nonzero, the timer will be signaled first at the due time, then periodically. The callback is called every time the period elapses, whether or not the previous callback has finished executing. Callback functions are queued to the thread pool. These threads are subject to scheduling delays, so the timing can vary depending on what else is happening in the application or the system.

The time that the system spends in sleep or hibernation does not count toward the expiration of the timer. The timer is signaled when the cumulative amount of elapsed time the system spends in the waking state matches the timer's due time or period.

**Windows Server 2003 and Windows XP:** The time that the system spends in sleep or hibernation counts toward the expiration of the timer. If the timer expires while the system is sleeping, the timer is signaled immediately when the system wakes.

To cancel a timer, call the
[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer) function. To cancel all timers in a timer queue, call the
[DeleteTimerQueueEx](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueueex) function.

By default, the thread pool has a maximum of 500 threads. To raise this limit, use the **WT_SET_MAX_THREADPOOL_THREAD** macro defined in WinNT.h.

``` syntax
#define WT_SET_MAX_THREADPOOL_THREADS(Flags,Limit) \
    ((Flags)|=(Limit)<<16)
```

Use this macro when specifying the *Flags* parameter. The macro parameters are the desired flags and the new limit (up to (2<<16)-1 threads). However, note that your application can improve its performance by keeping the number of worker threads low.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

#### Examples

For an example that uses
**CreateTimerQueueTimer**, see
[Using Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/using-timer-queues).

## See also

[CreateTimerQueue](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-createtimerqueue)

[DeleteTimerQueueEx](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueueex)

[DeleteTimerQueueTimer](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-deletetimerqueuetimer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)

[Timer Queues](https://learn.microsoft.com/windows/desktop/Sync/timer-queues)