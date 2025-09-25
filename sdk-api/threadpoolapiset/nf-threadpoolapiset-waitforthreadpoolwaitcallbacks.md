# WaitForThreadpoolWaitCallbacks function

## Description

Waits for outstanding wait callbacks to complete and optionally cancels pending callbacks that have not yet started to execute.

## Parameters

### `pwa` [in, out]

A pointer to a **TP_WAIT** structure that defines the wait object. The [CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait) function returns this pointer.

### `fCancelPendingCallbacks` [in]

Indicates whether to cancel queued callbacks that have not yet started to execute.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwait)

[CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait)

[SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)