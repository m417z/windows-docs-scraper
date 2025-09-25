# CreateThreadpoolTimer function

## Description

Creates a new timer object.

## Parameters

### `pfnti` [in]

The callback function to call each time the timer object expires. For details, see [TimerCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686790(v=vs.85)).

### `pv` [in, out, optional]

Optional application-defined data to pass to the callback function.

### `pcbe` [in, optional]

A **TP_CALLBACK_ENVIRON** structure that defines the environment in which to execute the callback. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

If this parameter is NULL, the callback executes in the default callback environment. For more information, see [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment).

## Return value

If the function succeeds, it returns a pointer to a **TP_TIMER** structure that defines the timer object. Applications do not modify the members of this structure.

If the function fails, it returns NULL. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To set the timer object, call the [SetThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimer) function.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpooltimer)

[IsThreadpoolTimerSet](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-isthreadpooltimerset)

[SetThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpooltimer)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolTimerCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooltimercallbacks)