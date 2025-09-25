# ReleaseSemaphoreWhenCallbackReturns function

## Description

Specifies the semaphore that the thread pool will release when the current callback completes.

## Parameters

### `pci` [in, out]

A pointer to a **TP_CALLBACK_INSTANCE** structure that defines the callback instance. The pointer is passed to the callback function.

### `sem` [in]

A handle to the semaphore.

### `crel` [in]

The amount by which to increment the semaphore object's count.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CallbackMayRunLong](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-callbackmayrunlong)

[DisassociateCurrentThreadFromCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-disassociatecurrentthreadfromcallback)

[FreeLibraryWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-freelibrarywhencallbackreturns)

[LeaveCriticalSectionWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-leavecriticalsectionwhencallbackreturns)

[ReleaseMutexWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasemutexwhencallbackreturns)

[SetEventWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-seteventwhencallbackreturns)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[TrySubmitThreadpoolCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-trysubmitthreadpoolcallback)