# CloseThreadpoolCleanupGroup function

## Description

Closes the specified cleanup group.

## Parameters

### `ptpcg` [in, out]

A pointer to a **TP_CLEANUP_GROUP** structure that defines the cleanup group. The [CreateThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup) returns this pointer.

## Remarks

The cleanup group must have no members when you call this function. For information on removing members of the group, see [CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers)

[CreateThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)