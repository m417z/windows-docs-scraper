# SetThreadpoolWait function

## Description

Sets the wait object, replacing the previous wait object, if any. A worker thread calls the wait object's callback function after the handle becomes signaled or after the specified timeout expires.

## Parameters

### `pwa` [in, out]

A pointer to a **TP_WAIT** structure that defines the wait object. The [CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait) function returns this pointer.

### `h` [in, optional]

A handle.

If this parameter is NULL, the wait object will cease to queue new callbacks (but callbacks already queued will still occur).

If this parameter is not NULL, it must refer to a valid waitable object.

Mutex is not supported. If a handle to a mutex is passed in, the thread pool raises a STATUS_THREADPOOL_HANDLE_EXCEPTION exception and ExceptionRecord.ExceptionInformation[0] will be equal to STATUS_INVALID_PARAMETER_3.

If this handle is closed while the wait is still pending, the function's behavior is undefined. If the wait is still pending and the handle must be closed, use [CloseThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwait) to cancel the wait and then close the handle.

The wait is considered set if this parameter is non-NULL.

### `pftTimeout` [in, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the absolute or relative time at which the wait operation should time out. If this parameter points to a positive value, it indicates the absolute time since January 1, 1601 (UTC), in 100-nanosecond intervals. If this parameter points to a negative value, it indicates the amount of time to wait relative to the current time. For more information about time values, see [File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times).

If this parameter points to 0, the wait times out immediately. If this parameter is NULL, the wait will not time out.

## Remarks

A wait object can wait for only one handle. Setting the handle for a wait object replaces the previous handle, if any.

You must re-register the event with the wait object before signaling it each time to trigger the wait callback.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwait)

[CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait)

[SetThreadpoolWaitEx](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwaitex)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolWaitCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolwaitcallbacks)