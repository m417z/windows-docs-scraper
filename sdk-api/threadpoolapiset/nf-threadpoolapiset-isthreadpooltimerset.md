# IsThreadpoolTimerSet function

## Description

Determines whether the specified timer object is currently set.

## Parameters

### `pti` [in, out]

A pointer to a **TP_TIMER** structure that defines the timer object. The [CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer) function returns this pointer.

## Return value

The return value is TRUE if the timer is set; otherwise, the return value is FALSE.

## Remarks

A timer is considered to be set if the most recent call to [SetThreadpoolTimer](https://learn.microsoft.com/windows/win32/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimer)
or [SetThreadpoolTimerEx function](https://learn.microsoft.com/windows/win32/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimerex) passed a non-null value for *pftDueTime*.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CloseThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpooltimer)

[CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer)

[SetThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimer)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolTimerCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooltimercallbacks)