# CreateThreadpool function

## Description

Allocates a new pool of threads to execute callbacks.

## Parameters

### `reserved`

This parameter is reserved and must be NULL.

## Return value

If the function succeeds, it returns a pointer to a **TP_POOL** structure representing the newly allocated thread pool. Applications do not modify the members of this structure.

If function fails, it returns NULL. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After creating the new thread pool, you should call [SetThreadpoolThreadMaximum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadmaximum) to specify the maximum number of threads that the pool can allocate and [SetThreadpoolThreadMinimum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadminimum) to specify the minimum number of threads available in the pool.

To use the pool, you must associate the pool with a callback environment. To create the callback environment, call [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment). Then, call [SetThreadpoolCallbackPool](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpool) to associate the pool with the callback environment.

To release the thread pool, call [CloseThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpool).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpool](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpool)

[SetThreadpoolThreadMaximum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadmaximum)

[SetThreadpoolThreadMinimum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadminimum)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)