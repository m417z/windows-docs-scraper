# LeaveCriticalSectionWhenCallbackReturns function

## Description

Specifies the critical section that the thread pool will release when the current callback completes.

## Parameters

### `pci` [in, out]

A pointer to a **TP_CALLBACK_INSTANCE** structure that defines the callback instance. The pointer is passed to the callback function.

### `pcs` [in, out]

The critical section.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CallbackMayRunLong](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-callbackmayrunlong)

[DisassociateCurrentThreadFromCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-disassociatecurrentthreadfromcallback)

[FreeLibraryWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-freelibrarywhencallbackreturns)

[ReleaseMutexWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasemutexwhencallbackreturns)

[ReleaseSemaphoreWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasesemaphorewhencallbackreturns)

[SetEventWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-seteventwhencallbackreturns)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[TrySubmitThreadpoolCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-trysubmitthreadpoolcallback)