# SetThreadpoolCallbackCleanupGroup function

## Description

Associates the specified cleanup group with the specified callback environment.

## Parameters

### `pcbe` [in, out]

A **TP_CALLBACK_ENVIRON** structure that defines the callback environment. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

### `ptpcg` [in]

A **TP_CLEANUP_GROUP** structure that defines the cleanup group. The [CreateThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup) function returns this structure.

### `pfng` [in, optional]

The cleanup callback to be called if the cleanup group is canceled before the associated object is released. The function is called when you call [CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers).

## Remarks

This function is implemented as an inline function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[DestroyThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-destroythreadpoolenvironment)

[InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment)

[SetThreadpoolCallbackLibrary](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbacklibrary)

[SetThreadpoolCallbackPool](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpool)

[SetThreadpoolCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpriority)

[SetThreadpoolCallbackRunsLong](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackrunslong)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)