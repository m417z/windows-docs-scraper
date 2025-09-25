# CreateThreadpoolCleanupGroup function

## Description

Creates a cleanup group that applications can use to track one or more thread pool callbacks.

## Return value

If the function succeeds, it returns a pointer to a **TP_CLEANUP_GROUP** structure of the newly allocated cleanup group. Applications do not modify the members of this structure.

If function fails, it returns NULL. To retrieve extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After creating the cleanup group, call [SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup) to associate the cleanup group with a callback environment.

A member is added to the group each time you call one of the following functions:

* [CreateThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolio)
* [CreateThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpooltimer)
* [CreateThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwait)
* [CreateThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolwork)

You use one of the following corresponding close functions to remove a member from the group.

* [CloseThreadpoolIo](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolio)
* [CloseThreadpoolTimer](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpooltimer)
* [CloseThreadpoolWait](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwait)
* [CloseThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwork)

To close all the callbacks, call [CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroup)

[CloseThreadpoolCleanupGroupMembers](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroupmembers)

[SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)