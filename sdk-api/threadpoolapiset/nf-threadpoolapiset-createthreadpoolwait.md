# CreateThreadpoolWait function

## Description

Creates a new wait object.

## Parameters

### `pfnwa` [in]

The callback function to call when the wait completes or times out. For details, see [WaitCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms687017(v=vs.85)).

### `pv` [in, out, optional]

Optional application-defined data to pass to the callback function.

### `pcbe` [in, optional]

A **TP_CALLBACK_ENVIRON** structure that defines the environment in which to execute the callback. The [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment) function returns this structure.

If this parameter is NULL, the callback executes in the default callback environment. For more information, see [InitializeThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-initializethreadpoolenvironment).

## Return value

If the function succeeds, it returns a pointer to a **TP_WAIT** structure that defines the wait object. Applications do not modify the members of this structure.

If the function fails, it returns NULL. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To set the wait object, call the [SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait) or [SetThreadpoolWaitEx](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwaitex) function.

The work item and all functions it calls must not rely on the thread after they have returned. Therefore, you cannot call an asynchronous call that requires a persistent thread, such as the
[RegNotifyChangeKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regnotifychangekeyvalue) function without the **REG_NOTIFY_THREAD_AGNOSTIC** flag, from the default callback environment. Instead, use a thread whose lifetime you control.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwait)

[SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolWaitCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolwaitcallbacks)