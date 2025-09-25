# CloseThreadpoolTimer function

## Description

Releases the specified timer object.

## Parameters

### `pti` [in, out]

A pointer to **TP_TIMER** structure that defines the timer object.
The [CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer) function returns this pointer.

## Remarks

The timer object is freed immediately if there are no outstanding callbacks; otherwise, the timer object is freed asynchronously after the outstanding callback functions complete.

In some cases, callback functions might run after **CloseThreadpoolTimer** has been called. To prevent this behavior:

* Call the [SetThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimer) function
or [SetThreadpoolTimerEx](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimerex) function
with the *pftDueTime* parameter set to NULL and the *msPeriod* and *msWindowLength* parameters set to 0.
* Call the [WaitForThreadpoolTimerCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooltimercallbacks) function with the *fCancelPendingCallbacks* parameter set to TRUE.
* Call **CloseThreadpoolTimer**.

If there is a cleanup group associated with the timer object, it is not necessary to call this function; calling the [CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers) function releases the work, wait, and timer objects associated with the cleanup group.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer)

[IsThreadpoolTimerSet](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-isthreadpooltimerset)

[SetThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimer)

[SetThreadpoolTimerEx](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimerex)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolTimerCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooltimercallbacks)