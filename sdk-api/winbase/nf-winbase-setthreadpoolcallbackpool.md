# SetThreadpoolCallbackPool function

## Description

Sets the thread pool to be used when generating callbacks.

## Parameters

### `pcbe` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

### `ptpp` [in]

A **TP_POOL** structure that defines the thread pool. The [CreateThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpool) function returns this structure.

## Remarks

If you do not specify a thread pool, the global thread pool is used.

This function is implemented as an inline function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[DestroyThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-destroythreadpoolenvironment)

[InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment)

[SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)

[SetThreadpoolCallbackLibrary](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbacklibrary)

[SetThreadpoolCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpriority)

[SetThreadpoolCallbackRunsLong](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackrunslong)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)