# SetThreadpoolTimer function

## Description

Sets the timer object, replacing the previous timer, if any. A worker thread calls the timer object's callback after the specified timeout expires.

## Parameters

### `pti` [in, out]

A pointer to a **TP_TIMER** structure that defines the timer object to set. The [CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer) function returns this pointer.

### `pftDueTime` [in, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the absolute or relative time at which the timer should expire. If positive or zero, it indicates the absolute time since January 1, 1601 (UTC), measured in 100 nanosecond units. If negative, it indicates the amount of time to wait relative to the current time. For more information about time values, see [File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times).

If this parameter is NULL, the timer object will cease to queue new callbacks (but callbacks already queued will still occur).

The timer is set if the *pftDueTime* parameter is non-NULL.

### `msPeriod` [in]

The timer period, in milliseconds. If this parameter is zero, the timer is signaled once. If this parameter is greater than zero, the timer is periodic. A periodic timer automatically reactivates each time the period elapses, until the timer is canceled.

### `msWindowLength` [in]

The maximum amount of time the system can delay before calling the timer callback. If this parameter is not set to zero, the system can batch calls to conserve power.

## Remarks

Setting the timer cancels the previous timer, if any.

In some cases, callback functions might run after an application closes the threadpool timer. To prevent this behavior, an application should follow the steps described in [CloseThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpooltimer).

If the due time specified by *pftDueTime* is relative, the time that the system spends in sleep or hibernation does not count toward the expiration of the timer. The timer is signaled when the cumulative amount of elapsed time the system spends in the waking state equals the timer's relative due time or period. If the due time specified by *pftDueTime* is absolute, the time that the system spends in sleep or hibernation does count toward the expiration of the timer. If the timer expires while the system is sleeping, the timer is signaled immediately when the system wakes.

If the due time specified by *pftDueTime* is zero, then the timer expires immediately.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpooltimer)

[CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer)

[IsThreadpoolTimerSet](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-isthreadpooltimerset)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolTimerCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooltimercallbacks)