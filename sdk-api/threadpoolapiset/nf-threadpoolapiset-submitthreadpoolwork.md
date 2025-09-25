# SubmitThreadpoolWork function

## Description

Posts a work object to the thread pool. A worker thread calls the work object's callback function.

## Parameters

### `pwk` [in, out]

A pointer to a **TP_WORK** structure that defines the work object. The [CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork) function returns this pointer.

## Remarks

You can post a work object one or more times (up to MAXULONG) without waiting for prior callbacks to complete. The callbacks will execute in parallel. To improve efficiency, the thread pool may throttle the threads.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwork)

[CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolWorkCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolworkcallbacks)