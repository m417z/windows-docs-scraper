# WaitForMultipleObjectsEx function

## Description

Waits until one or all of the specified objects are in the signaled state, an I/O completion routine or asynchronous procedure call (APC) is queued to the thread, or the time-out interval elapses.

## Parameters

### `nCount` [in]

The number of object handles to wait for in the array pointed to by *lpHandles*. The maximum number of object handles is **MAXIMUM_WAIT_OBJECTS**. This parameter cannot be zero.

### `lpHandles` [in]

An array of object handles. For a list of the object types whose handles can be specified, see the following Remarks section. The array can contain handles of objects of different types. It may not contain multiple copies of the same handle.

If one of these handles is closed while the wait is still pending, the function's behavior is undefined.

The handles must have the **SYNCHRONIZE** access right. For more information, see
[Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights).

### `bWaitAll` [in]

If this parameter is **TRUE**, the function returns when the state of all objects in the *lpHandles* array is set to signaled. If **FALSE**, the function returns when the state of any one of the objects is set to signaled. In the latter case, the return value indicates the object whose state caused the function to return.

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the specified objects are signaled, an I/O completion routine or APC is queued, or the interval elapses. If *dwMilliseconds* is zero, the function does not enter a wait state if the criteria is not met; it always returns immediately. If *dwMilliseconds* is **INFINITE**, the function will return only when the specified objects are signaled or an I/O completion routine or APC is queued.

**Windows XP, Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008, and Windows Server 2008 R2:** The *dwMilliseconds* value does include time spent in low-power states. For example, the timeout does keep counting down while the computer is asleep.

**Windows 8 and newer, Windows Server 2012 and newer:** The *dwMilliseconds* value does not include time spent in low-power states. For example, the timeout does not keep counting down while the computer is asleep.

### `bAlertable` [in]

If this parameter is **TRUE** and the thread is in the waiting state, the function returns when the system queues an I/O completion routine or APC, and the thread runs the routine or function. Otherwise, the function does not return and the completion routine or APC function is not executed.

A completion routine is queued when the
[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex) or
[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) function in which it was specified has completed. The wait function returns and the completion routine is called only if *bAlertable* is **TRUE** and the calling thread is the thread that initiated the read or write operation. An APC is queued when you call
[QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc).

## Return value

If the function succeeds, the return value indicates the event that caused the function to return. It can be one of the following values. (Note that **WAIT_OBJECT_0** is defined as 0 and **WAIT_ABANDONED_0** is defined as 0x00000080L.)

| Return code/value | Description |
| --- | --- |
| **WAIT_OBJECT_0** to (**WAIT_OBJECT_0** + *nCount*– 1) | If *bWaitAll* is **TRUE**, a return value in this range indicates that the state of all specified objects is signaled. <br><br>If *bWaitAll* is **FALSE**, the return value minus **WAIT_OBJECT_0** indicates the *lpHandles* array index of the object that satisfied the wait. If more than one object became signaled during the call, this is the array index of the signaled object with the smallest index value of all the signaled objects. |
| **WAIT_ABANDONED_0** to (**WAIT_ABANDONED_0** + *nCount*– 1) | If *bWaitAll* is **TRUE**, a return value in this range indicates that the state of all specified objects is signaled, and at least one of the objects is an abandoned mutex object. <br><br>If *bWaitAll* is **FALSE**, the return value minus **WAIT_ABANDONED_0** indicates the *lpHandles* array index of an abandoned mutex object that satisfied the wait. Ownership of the mutex object is granted to the calling thread, and the mutex is set to nonsignaled.<br><br>If a mutex was protecting persistent state information, you should check it for consistency. |
| **WAIT_IO_COMPLETION**<br><br>0x000000C0L | The wait was ended by one or more user-mode [asynchronous procedure calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls) (APC) queued to the thread. |
| **WAIT_TIMEOUT**<br><br>0x00000102L | The time-out interval elapsed, the conditions specified by the *bWaitAll* parameter were not satisfied, and no completion routines are queued. |
| **WAIT_FAILED**<br><br>(**DWORD**)0xFFFFFFFF | The function has failed. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

The
**WaitForMultipleObjectsEx** function determines whether the wait criteria have been met. If the criteria have not been met, the calling thread enters the wait state until the conditions of the wait criteria have been met or the time-out interval elapses.

When *bWaitAll* is **TRUE**, the function's wait operation is completed only when the states of all objects have been set to signaled. The function does not modify the states of the specified objects until the states of all objects have been set to signaled. For example, a mutex can be signaled, but the thread does not get ownership until the states of the other objects are also set to signaled. In the meantime, some other thread may get ownership of the mutex, thereby setting its state to nonsignaled.

When *bWaitAll* is **FALSE**, this function checks the handles in the array in order starting with index 0, until one of the objects is signaled. If multiple objects become signaled, the function returns the index of the first handle in the array whose object was signaled.

The function modifies the state of some types of synchronization objects. Modification occurs only for the object or objects whose signaled state caused the function to return. For example, the count of a semaphore object is decreased by one. For more information, see the documentation for the individual synchronization objects.

To wait on more than **MAXIMUM_WAIT_OBJECTS** handles, use one of the following methods:

* Create a thread to wait on **MAXIMUM_WAIT_OBJECTS** handles, then wait on that thread plus the other handles. Use this technique to break the handles into groups of **MAXIMUM_WAIT_OBJECTS**.
* Call [RegisterWaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerwaitforsingleobject) or
  [SetThreadpoolWait](https://learn.microsoft.com/windows/win32/api/threadpoolapiset/nf-threadpoolapiset-setthreadpoolwait)
  to wait on each handle.
  The thread pool waits efficiently on the handles and assigns a worker thread after the object is signaled or the time-out interval expires.

The
**WaitForMultipleObjectsEx** function can specify handles of any of the following object types in the *lpHandles* array:

* Change notification
* Console input
* Event
* Memory resource notification
* Mutex
* Process
* Semaphore
* Thread
* Waitable timer

Use caution when calling the wait functions and code that directly or indirectly creates windows. If a thread creates any windows, it must process messages. Message broadcasts are sent to all windows in the system. A thread that uses a wait function with no time-out interval may cause the system to become deadlocked. Two examples of code that indirectly creates windows are DDE and the [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) function. Therefore, if you have a thread that creates windows, use
[MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects) or
[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex), rather than
**WaitForMultipleObjectsEx**.

## See also

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions)