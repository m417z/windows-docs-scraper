# CreateThreadpoolWork function

## Description

Creates a new work object.

## Parameters

### `pfnwk` [in]

The callback function. A worker thread calls this callback each time you call [SubmitThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-submitthreadpoolwork) to post the work object. For details, see [WorkCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms687396(v=vs.85)).

### `pv` [in, out, optional]

Optional application-defined data to pass to the callback function.

### `pcbe` [in, optional]

A pointer to a **TP_CALLBACK_ENVIRON** structure that defines the environment in which to execute the callback. Use the [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function to initialize the structure before calling this function.

If this parameter is NULL, the callback executes in the default callback environment. For more information, see [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment).

## Return value

If the function succeeds, it returns a pointer to a **TP_WORK** structure that defines the work object. Applications do not modify the members of this structure.

If the function fails, it returns NULL. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwork)

[SubmitThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-submitthreadpoolwork)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolWorkCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolworkcallbacks)