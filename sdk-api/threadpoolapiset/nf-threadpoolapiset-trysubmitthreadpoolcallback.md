# TrySubmitThreadpoolCallback function

## Description

Requests that a thread pool worker thread call the specified callback function.

## Parameters

### `pfns` [in]

The callback function. For details, see [SimpleCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms686295(v=vs.85)).

### `pv` [in, out, optional]

Optional application-defined data to pass to the callback function.

### `pcbe` [in, optional]

A pointer to a **TP_CALLBACK_ENVIRON** structure that defines the environment in which to execute the callback function. Use the [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function to initialize the structure before calling this function.

If this parameter is NULL, the callback executes in the default callback environment. For more information, see [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment).

## Return value

If the function succeeds, it returns TRUE.

If the function fails, it returns FALSE. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CallbackMayRunLong](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-callbackmayrunlong)

[DisassociateCurrentThreadFromCallback](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-disassociatecurrentthreadfromcallback)

[FreeLibraryWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-freelibrarywhencallbackreturns)

[InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment)

[LeaveCriticalSectionWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-leavecriticalsectionwhencallbackreturns)

[ReleaseMutexWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasemutexwhencallbackreturns)

[ReleaseSemaphoreWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-releasesemaphorewhencallbackreturns)

[SetEventWhenCallbackReturns](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-seteventwhencallbackreturns)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)