# WaitForThreadpoolTimerCallbacks function

## Description

Waits for outstanding timer callbacks to complete and optionally cancels pending callbacks that have not yet started to execute.

## Parameters

### `pti` [in, out]

A pointer to a **TP_TIMER** structure that defines the timer object. The [CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer) function returns this pointer.

### `fCancelPendingCallbacks` [in]

Indicates whether to cancel queued callbacks that have not yet started to execute.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CloseThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpooltimer)

[CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer)

[IsThreadpoolTimerSet](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-isthreadpooltimerset)

[SetThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimer)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)