# SetThreadpoolThreadMinimum function

## Description

Sets the minimum number of threads that the specified thread pool must make available to process callbacks.

## Parameters

### `ptpp` [in, out]

A pointer to a **TP_POOL** structure that defines the thread pool. The [CreateThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpool) function returns this pointer.

### `cthrdMic` [in]

The minimum number of threads.

## Return value

If the function succeeds, it returns TRUE.

If the function fails, it returns FALSE. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To specify the maximum number of threads that the pool may allocate, call [SetThreadpoolThreadMaximum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadmaximum).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpool)

[CreateThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpool)

[SetThreadpoolThreadMaximum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadmaximum)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)