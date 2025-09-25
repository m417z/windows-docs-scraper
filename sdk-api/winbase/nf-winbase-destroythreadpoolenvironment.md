# DestroyThreadpoolEnvironment function

## Description

Deletes the specified callback environment. Call this function when the callback environment is no longer needed for creating new thread pool objects.

## Parameters

### `pcbe` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

## Remarks

This function is implemented as an inline function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment)

[SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)

[SetThreadpoolCallbackLibrary](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbacklibrary)

[SetThreadpoolCallbackPool](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpool)

[SetThreadpoolCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpriority)

[SetThreadpoolCallbackRunsLong](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackrunslong)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)