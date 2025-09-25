# SetThreadpoolCallbackLibrary function

## Description

Ensures that the specified DLL remains loaded as long as there are outstanding callbacks.

## Parameters

### `pcbe` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

### `mod` [in]

A handle to the DLL.

## Remarks

You should call this function if a callback might acquire the loader lock. This prevents a deadlock from occurring when one thread in DllMain is waiting for the callback to end, and another thread that is executing the callback attempts to acquire the loader lock.

If the DLL containing the callback might be unloaded, the cleanup code in DllMain must cancel outstanding callbacks before releasing the object.

Managing callbacks created with a TP_CALLBACK_ENVIRON that specifies a callback library is somewhat processing-intensive. You should consider other options for ensuring that the library is not unloaded while callbacks are executing, or to guarantee that callbacks which may be executing do not acquire the loader lock.

The thread pool assumes ownership of the library reference supplied to this function. The caller should not call [FreeLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-freelibrary) on a module handle after passing it to this function.

This function is implemented as an inline function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[DestroyThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-destroythreadpoolenvironment)

[FreeLibraryWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-freelibrarywhencallbackreturns)

[InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment)

[SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)

[SetThreadpoolCallbackPool](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpool)

[SetThreadpoolCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpriority)

[SetThreadpoolCallbackRunsLong](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackrunslong)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)