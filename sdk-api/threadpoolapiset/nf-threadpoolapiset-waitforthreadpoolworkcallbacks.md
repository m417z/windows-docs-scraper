# WaitForThreadpoolWorkCallbacks function

## Description

Waits for outstanding work callbacks to complete and optionally cancels pending callbacks that have not yet started to execute.

## Parameters

### `pwk` [in, out]

A pointer to a **TP_WORK** structure that defines the work object. The [CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork) function returns this pointer.

### `fCancelPendingCallbacks` [in]

Indicates whether to cancel queued callbacks that have not yet started to execute.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CloseThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwork)

[CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork)

[SubmitThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-submitthreadpoolwork)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)