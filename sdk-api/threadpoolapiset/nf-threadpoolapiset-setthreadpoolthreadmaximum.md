# SetThreadpoolThreadMaximum function

## Description

Sets the maximum number of threads that the specified thread pool can allocate to process callbacks.

## Parameters

### `ptpp` [in, out]

A pointer to a **TP_POOL** structure that defines the thread pool. The [CreateThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpool) function returns this pointer.

### `cthrdMost` [in]

The maximum number of threads.

## Remarks

To specify the minimum number of threads available in the pool, call [SetThreadpoolThreadMinimum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadminimum).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpool)

[CreateThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpool)

[SetThreadpoolThreadMinimum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadminimum)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)