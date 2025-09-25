# CallbackMayRunLong function

## Description

Indicates that the callback may not return quickly.

## Parameters

### `pci` [in, out]

A pointer to a **TP_CALLBACK_INSTANCE** structure that defines the callback instance. The pointer is passed to the callback function.

## Return value

The function returns TRUE if another thread in the thread pool is available for processing callbacks or the thread pool was able to create a new thread. In this case, the current callback function may use the current thread indefinitely.

The function returns FALSE if another thread in the thread pool is not available to process callbacks and the thread pool was not able to create a new thread. The thread pool will attempt to create a new thread after a delay, but if the current callback function runs long, the thread pool may lose efficiency.

## Remarks

The thread pool may use this information to better determine when a new thread should be created.

The **CallbackMayRunLong** function should be called only by the thread that is processing the callback. Calling this function from another thread may cause a race condition.

The **CallbackMayRunLong** function always marks the callback as long-running, whether or not a thread is available for processing callbacks or the threadpool is able to allocate a new thread. Therefore, this function should be called only once, even if it returns FALSE.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[DisassociateCurrentThreadFromCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-disassociatecurrentthreadfromcallback)

[FreeLibraryWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-freelibrarywhencallbackreturns)

[LeaveCriticalSectionWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-leavecriticalsectionwhencallbackreturns)

[ReleaseMutexWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasemutexwhencallbackreturns)

[ReleaseSemaphoreWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasesemaphorewhencallbackreturns)

[SetEventWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-seteventwhencallbackreturns)

[SetThreadpoolCallbackRunsLong](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackrunslong)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[TrySubmitThreadpoolCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-trysubmitthreadpoolcallback)