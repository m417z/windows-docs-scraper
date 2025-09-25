# CloseThreadpoolWait function

## Description

Releases the specified wait object.

## Parameters

### `pwa` [in, out]

A pointer to a **TP_WAIT** structure that defines the wait object. The [CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait) function returns this pointer.

## Remarks

The wait object is freed immediately if there are no outstanding callbacks; otherwise, the timer object is freed asynchronously after the outstanding callbacks complete.

In some cases, callback functions might run after **CloseThreadpoolWait** has been called. To prevent this behavior:

* Call the [SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait) function
or [SetThreadpoolWaitEx](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwaitex) function
with the *h* parameter set to NULL.
* Call the [WaitForThreadpoolWaitCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolwaitcallbacks) function with the *fCancelPendingCallbacks* parameter set to TRUE.
* Call **CloseThreadpoolWait**.

If there is a cleanup group associated with the wait object, it is not necessary to call this function; calling the [CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers) function releases the work, wait, and timer objects associated with the cleanup group.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait)

[SetThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait)

[SetThreadpoolWaitEx](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwaitex)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolWaitCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolwaitcallbacks)