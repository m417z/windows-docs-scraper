# CloseThreadpoolWork function

## Description

Releases the specified work object.

## Parameters

### `pwk` [in, out]

A pointer to a **TP_WORK** structure that defines the work object. The [CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork) function returns this pointer.

## Remarks

The work object is freed immediately if there are no outstanding callbacks; otherwise, the work object is freed asynchronously after the outstanding callbacks complete.

If there is a cleanup group associated with the work object, it is not necessary to call this function; calling the [CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers) function releases the work, wait, and timer objects associated with the cleanup group.

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

## See also

[CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork)

[SubmitThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-submitthreadpoolwork)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)

[WaitForThreadpoolWorkCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolworkcallbacks)