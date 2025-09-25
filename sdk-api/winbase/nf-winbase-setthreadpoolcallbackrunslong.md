# SetThreadpoolCallbackRunsLong function

## Description

Indicates that callbacks associated with this callback environment may not return quickly.

## Parameters

### `pcbe` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

## Remarks

The thread pool may use this information to better determine when a new thread should be created.

This function is implemented as an inline function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CallbackMayRunLong](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-callbackmayrunlong)

[DestroyThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-destroythreadpoolenvironment)

[InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment)

[SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)

[SetThreadpoolCallbackLibrary](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbacklibrary)

[SetThreadpoolCallbackPool](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpool)

[SetThreadpoolCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpriority)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)