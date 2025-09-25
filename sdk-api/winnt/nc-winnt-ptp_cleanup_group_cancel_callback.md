# PTP_CLEANUP_GROUP_CANCEL_CALLBACK callback function

## Description

Applications implement this callback if they call the [SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup) function to specify the callback to use when [CloseThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroup) is called.

The **PTP_CLEANUP_GROUP_CANCEL_CALLBACK** type defines a pointer to this callback function. *CleanupGroupCancelCallback* is a placeholder for the application-defined function name.

## Parameters

### `ObjectContext` [in, out, optional]

Optional application-defined data specified during creation of the object.

### `CleanupContext` [in, out, optional]

Optional application-defined data specified using [CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers).

## See also

[CloseThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroup)

[CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers)

[SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)