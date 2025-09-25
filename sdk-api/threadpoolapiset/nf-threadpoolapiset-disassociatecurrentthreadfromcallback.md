# DisassociateCurrentThreadFromCallback function

## Description

Removes the association between the currently executing callback function and the object that initiated the callback. The current thread will no longer count as executing a callback on behalf of the object.

## Parameters

### `pci` [in, out]

A pointer to a **TP_CALLBACK_INSTANCE** structure that defines the callback instance. The pointer is passed to the callback function.

## Remarks

If this is the last thread executing a callback on behalf of the object, any threads waiting for the object's callbacks to complete will be released.

The thread remains associated with the object's [cleanup group](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup) until the thread returns to the thread pool. This lets DLL shutdown routines safely synchronize with outstanding callbacks and proceed with unloading the DLL's code when all callbacks have completed.

The callback-generating object remains valid for the duration of the callback. The callback object may be reused or released (although synchronization with cleanup group release is still required).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CallbackMayRunLong](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-callbackmayrunlong)

[FreeLibraryWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-freelibrarywhencallbackreturns)

[LeaveCriticalSectionWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-leavecriticalsectionwhencallbackreturns)

[ReleaseMutexWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasemutexwhencallbackreturns)

[ReleaseSemaphoreWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasesemaphorewhencallbackreturns)

[SetEventWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-seteventwhencallbackreturns)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[TrySubmitThreadpoolCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-trysubmitthreadpoolcallback)