# SetEventWhenCallbackReturns function

## Description

Specifies the event that the thread pool will set when the current callback completes.

## Parameters

### `pci` [in, out]

A pointer to a **TP_CALLBACK_INSTANCE** structure that defines the callback instance. The pointer is passed to the callback function.

### `evt` [in]

A handle to the event to be set.

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CallbackMayRunLong](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-callbackmayrunlong)

[DisassociateCurrentThreadFromCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-disassociatecurrentthreadfromcallback)

[FreeLibraryWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-freelibrarywhencallbackreturns)

[LeaveCriticalSectionWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-leavecriticalsectionwhencallbackreturns)

[ReleaseMutexWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasemutexwhencallbackreturns)

[ReleaseSemaphoreWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasesemaphorewhencallbackreturns)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[TrySubmitThreadpoolCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-trysubmitthreadpoolcallback)