# RegisterWaitForSingleObject function

## Description

Directs a wait thread in the [thread pool](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling) to wait on the object. The wait thread queues the specified callback function to the thread pool when one of the following occurs:

* The specified object is in the signaled state.
* The time-out interval elapses.

## Parameters

### `phNewWaitObject` [out]

A pointer to a variable that receives a wait handle on return. Note that a wait handle cannot be used in functions that require an object handle, such as
[CloseHandle](https://learn.microsoft.com/windows/desktop/api/handleapi/nf-handleapi-closehandle).

### `hObject` [in]

A handle to the object. For a list of the object types whose handles can be specified, see the following Remarks section.

Mutex is not supported. If a handle to a mutex is passed in, the thread pool raises a STATUS_THREADPOOL_HANDLE_EXCEPTION exception and ExceptionRecord.ExceptionInformation[0] will be equal to STATUS_INVALID_PARAMETER_3.

If this handle is closed while the wait is still pending, the function's behavior is undefined.

The handles must have the **SYNCHRONIZE** access right. For more information, see
[Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights).

### `Callback` [in]

A pointer to the application-defined function of type **WAITORTIMERCALLBACK** to be executed when *hObject* is in the signaled state, or *dwMilliseconds* elapses. For more information, see
[WaitOrTimerCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms687066(v=vs.85)).

### `Context` [in, optional]

A single value that is passed to the callback function.

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. The function returns if the interval elapses, even if the object's state is nonsignaled. If *dwMilliseconds* is zero, the function tests the object's state and returns immediately. If *dwMilliseconds* is **INFINITE**, the function's time-out interval never elapses.

### `dwFlags` [in]

This parameter can be one or more of the following values.

For information about using these values with objects that remain signaled, see the Remarks section.

| Value | Meaning |
| --- | --- |
| **WT_EXECUTEDEFAULT**<br><br>0x00000000 | By default, the callback function is queued to a non-I/O worker thread. |
| **WT_EXECUTEINIOTHREAD**<br><br>0x00000001 | This flag is not used.<br><br>**Windows Server 2003 and Windows XP:** The callback function is queued to an I/O worker thread. This flag should be used if the function should be executed in a thread that waits in an alertable state. <br><br>I/O worker threads were removed starting with Windows Vista and Windows Server 2008. |
| **WT_EXECUTEINPERSISTENTTHREAD**<br><br>0x00000080 | The callback function is queued to a thread that never terminates. It does not guarantee that the same thread is used each time. This flag should be used only for short tasks or it could affect other wait operations. <br><br>This flag must be set if the thread calls functions that use APCs. For more information, see [Asynchronous Procedure Calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls).<br><br>Note that currently no worker thread is truly persistent, although no worker thread will terminate if there are any pending I/O requests. |
| **WT_EXECUTEINWAITTHREAD**<br><br>0x00000004 | The callback function is invoked by the wait thread itself. This flag should be used only for short tasks or it could affect other wait operations. <br><br>Deadlocks can occur if some other thread acquires an exclusive lock and calls the [UnregisterWait](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-unregisterwait) or [UnregisterWaitEx](https://learn.microsoft.com/windows/desktop/Sync/unregisterwaitex) function while the callback function is trying to acquire the same lock. |
| **WT_EXECUTELONGFUNCTION**<br><br>0x00000010 | The callback function can perform a long wait. This flag helps the system to decide if it should create a new thread. |
| **WT_EXECUTEONLYONCE**<br><br>0x00000008 | The thread will no longer wait on the handle after the callback function has been called once. Otherwise, the timer is reset every time the wait operation completes until the wait operation is canceled. |
| **WT_TRANSFER_IMPERSONATION**<br><br>0x00000100 | Callback functions will use the current access token, whether it is a process or impersonation token. If this flag is not specified, callback functions execute only with the process token.<br><br>**Windows XP:** This flag is not supported until Windows XP with SP2 and Windows Server 2003. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

New wait threads are created automatically when required. The wait operation is performed by a wait thread from the thread pool. The callback routine is executed by a worker thread when the object's state becomes signaled or the time-out interval elapses. If *dwFlags* is not **WT_EXECUTEONLYONCE**, the timer is reset every time the event is signaled or the time-out interval elapses.

When the wait is completed, you must call the
[UnregisterWait](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-unregisterwait) or
[UnregisterWaitEx](https://learn.microsoft.com/windows/desktop/Sync/unregisterwaitex) function to cancel the wait operation. (Even wait operations that use **WT_EXECUTEONLYONCE** must be canceled.) Do not make a blocking call to either of these functions from within the callback function.

Note that you should not pulse an event object passed to
**RegisterWaitForSingleObject**, because the wait thread might not detect that the event is signaled before it is reset. You should not register an object that remains signaled (such as a manual reset event or terminated process) unless you set the **WT_EXECUTEONLYONCE** or **WT_EXECUTEINWAITTHREAD** flag. For other flags, the callback function might be called too many times before the event is reset.

The function modifies the state of some types of synchronization objects. Modification occurs only for the object whose signaled state caused the wait condition to be satisfied. For example, the count of a semaphore object is decreased by one.

The
**RegisterWaitForSingleObject** function can wait for the following objects:

* Change notification
* Console input
* Event
* Memory resource notification
* Process
* Semaphore
* Thread
* Waitable timer

For more information, see
[Synchronization Objects](https://learn.microsoft.com/windows/desktop/Sync/synchronization-objects).

By default, the thread pool has a maximum of 500 threads. To raise this limit, use the **WT_SET_MAX_THREADPOOL_THREAD** macro defined in WinNT.h.

``` syntax
#define WT_SET_MAX_THREADPOOL_THREADS(Flags,Limit) \
    ((Flags)|=(Limit)<<16)
```

Use this macro when specifying the *dwFlags* parameter. The macro parameters are the desired flags and the new limit (up to (2<<16)-1 threads). However, note that your application can improve its performance by keeping the number of worker threads low.

The work item and all functions it calls must be thread-pool safe. Therefore, you cannot call an asynchronous call that requires a persistent thread, such as the
[RegNotifyChangeKeyValue](https://learn.microsoft.com/windows/desktop/api/winreg/nf-winreg-regnotifychangekeyvalue) function, from the default callback environment. Instead, set the thread pool maximum equal to the thread pool minimum using the [SetThreadpoolThreadMaximum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadmaximum) and [SetThreadpoolThreadMinimum](https://learn.microsoft.com/windows/desktop/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolthreadminimum) functions, or create your own thread using the [CreateThread](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread) function. (For the original thread pool API, specify **WT_EXECUTEINPERSISTENTTHREAD** using the [QueueUserWorkItem](https://learn.microsoft.com/windows/desktop/api/threadpoollegacyapiset/nf-threadpoollegacyapiset-queueuserworkitem) function.)

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0500 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Thread Pooling](https://learn.microsoft.com/windows/desktop/ProcThread/thread-pooling)

[UnregisterWait](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-unregisterwait)

[UnregisterWaitEx](https://learn.microsoft.com/windows/desktop/Sync/unregisterwaitex)

[Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions)

[WaitOrTimerCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms687066(v=vs.85))