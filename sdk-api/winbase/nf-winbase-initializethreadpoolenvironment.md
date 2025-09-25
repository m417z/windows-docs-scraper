# InitializeThreadpoolEnvironment function

## Description

Initializes a callback environment.

## Parameters

### `pcbe` [out]

A **TP_CALLBACK_ENVIRON** structure that defines a callback environment.

## Remarks

By default, a callback executes in the default thread pool for the process. No cleanup group is associated with the callback environment, the caller is responsible for keeping the callback's DLL loaded while there are outstanding callbacks, and the callback is expected to run in a reasonable amount of time for the application.

Create a callback environment if you plan to call one of the following functions to modify the environment:

* [SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)
* [SetThreadpoolCallbackLibrary](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbacklibrary)
* [SetThreadpoolCallbackPool](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpool)
* [SetThreadpoolCallbackPriority](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpriority)
* [SetThreadpoolCallbackRunsLong](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackrunslong)

To use the default callback environment, set the optional callback environment parameter to NULL when calling one of the following functions:

* [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio)
* [CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer)
* [CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait)
* [CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork)
* [TrySubmitThreadpoolCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-trysubmitthreadpoolcallback)

The **InitializeThreadpoolEnvironment** function is implemented as an inline function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[DestroyThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-destroythreadpoolenvironment)

[SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)

[SetThreadpoolCallbackLibrary](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbacklibrary)

[SetThreadpoolCallbackPool](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackpool)

[SetThreadpoolCallbackRunsLong](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackrunslong)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)