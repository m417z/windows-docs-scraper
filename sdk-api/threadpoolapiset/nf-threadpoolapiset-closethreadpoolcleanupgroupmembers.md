# CloseThreadpoolCleanupGroupMembers function

## Description

Releases the members of the specified cleanup group, waits for all callback functions to complete, and optionally cancels any outstanding callback functions.

## Parameters

### `ptpcg` [in, out]

A pointer to a **TP_CLEANUP_GROUP** structure that defines the cleanup group. The [CreateThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup) function returns this pointer.

### `fCancelPendingCallbacks` [in]

If this parameter is TRUE, the function cancels outstanding callbacks that have not yet started. If this parameter is FALSE, the function waits for outstanding callback functions to complete.

### `pvCleanupContext` [in, out, optional]

The application-defined data to pass to the application's cleanup group callback function. You can specify the callback function when you call [SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup).

## Remarks

The **CloseThreadpoolCleanupGroupMembers** function simplifies cleanup of thread pool callback objects by releasing, in a single operation, all work objects, wait objects, and timer objects that are members of the cleanup group. An object becomes a member of a cleanup group when the object is created with the threadpool callback environment that was specified when the cleanup group was created. For more information, see [CreateThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup).

The **CloseThreadpoolCleanupGroupMembers** function blocks until all currently executing callback functions finish. If *fCancelPendingCallbacks* is TRUE, outstanding callbacks are canceled; otherwise, the function blocks until all outstanding callbacks also finish. After the **CloseThreadpoolCleanupGroupMembers** function returns, an application should not use any object that was a member of the cleanup group at the time **CloseThreadpoolCleanupGroupMembers** was called. Also, an application should not release any of the objects individually by calling a function such as [CloseThreadpoolWork](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolwork), because the objects have already been released.

The **CloseThreadpoolCleanupGroupMembers** function does not close the cleanup group itself. Instead, the cleanup group persists until the [CloseThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroup) function is called. Also, closing a cleanup group does not affect the associated threadpool callback environment. The callback environment persists until it is destroyed by calling [DestroyThreadpoolEnvironment](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-destroythreadpoolenvironment).

 As long as a cleanup group persists, new objects created with the cleanup group's associated threadpool callback environment are added to the cleanup group. This allows an application to reuse the cleanup group. However, it can lead to errors if the application does not synchronize code that calls **CloseThreadpoolCleanupGroupMembers** with code that creates new objects. For example, suppose a thread creates two threadpool work objects, Work1 and Work2. Another thread calls **CloseThreadpoolCleanupGroupMembers**. Depending on when the threads run, any of the following might occur:

* Work1 and Work2 are added to the cleanup group after its existing members were released. Code that submits Work1 and Work2 will succeed.
* Work1 is added to the cleanup group before its existing members are released, causing Work1 to be released along with other members. Then Work2 is added. Code that submits Work1 will generate an exception; code that submits Work2 will succeed.
* Work1 and Work2 are added to the cleanup group before its existing members are released, causing both Work1 and Work2 to be released. Code that submits Work1 or Work2 will generate an exception.

To simply wait for or cancel pending work items without releasing them, use one of the threadpool callback functions: [WaitForThreadpoolIoCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooliocallbacks), [WaitForThreadpoolTimerCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpooltimercallbacks), [WaitForThreadpoolWaitCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolwaitcallbacks), or [WaitForThreadpoolWorkCallbacks](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-waitforthreadpoolworkcallbacks).

To compile an application that uses this function, define _WIN32_WINNT as 0x0600 or higher.

#### Examples

For an example, see [Using the Thread Pool Functions](https://learn.microsoft.com/windows/desktop/ProcThread/using-the-thread-pool-functions).

## See also

[CloseThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-closethreadpoolcleanupgroup)

[CreateThreadpoolCleanupGroup](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-createthreadpoolcleanupgroup)

[SetThreadpoolCallbackCleanupGroup](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setthreadpoolcallbackcleanupgroup)

[Thread Pools](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pools)