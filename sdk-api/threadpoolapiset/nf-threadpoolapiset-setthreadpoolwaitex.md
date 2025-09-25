# SetThreadpoolWaitEx function

## Description

Sets the wait object, replacing the previous wait object, if any. A worker thread calls the wait object's callback function after the handle becomes signaled or after the specified timeout expires.

## Parameters

### `pwa` [in, out]

A pointer to a **TP_WAIT** structure that defines the wait object. The [CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait) function returns this pointer.

### `h` [in, optional]

A handle.

If this parameter is NULL, the wait object will cease to queue new callbacks (but callbacks already queued will still occur).

If this parameter is not NULL, it must refer to a valid waitable object.

If this handle is closed while the wait is still pending, the function's behavior is undefined. If the wait is still pending and the handle must be closed, use [CloseThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwait) to cancel the wait and then close the handle.

The wait is considered set if this parameter is non-NULL.

### `pftTimeout` [in, optional]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that specifies the absolute or relative time at which the wait operation should time out. If this parameter points to a positive value, it indicates the absolute time since January 1, 1601 (UTC), in 100-nanosecond intervals. If this parameter points to a negative value, it indicates the amount of time to wait relative to the current time. If this parameter points to zero, then the wait times out immediately. For more information about time values, see [File Times](https://learn.microsoft.com/windows/desktop/SysInfo/file-times).

If this parameter is NULL, then the wait does not time out.

### `Reserved`

Reserved.
Must be NULL.

## Return value

Returns TRUE if the wait was previously set and was canceled.
Otherwise returns FALSE.

If the wait's previous state was "set", and the function returns FALSE, then a callback is in progress or about to commence.
See the remarks for further discussion.

## Remarks

A wait object can wait for only one handle. Setting the handle for a wait object replaces the previous wait handle, if any.

In some cases, callback functions might run after an application closes the threadpool timer. To prevent this behavior, an application should follow the steps described in [CloseThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwait).

If the timeout specified by *pftTimeout* is relative, the time that the system spends in sleep or hibernation does not count toward the expiration of the wait. The wait is signaled when the cumulative amount of elapsed time the system spends in the waking state equals the wait's relative timeout. If the timeout specified by *pftTimeout* is absolute, the time that the system spends in sleep or hibernation does count toward the expiration of the wait. If the wait expires while the system is sleeping, the wait is signaled immediately when the system wakes.

## See also

[CloseThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwait)

[CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolWaitCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolwaitcallbacks)