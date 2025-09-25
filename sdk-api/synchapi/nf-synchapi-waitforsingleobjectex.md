# WaitForSingleObjectEx function

## Description

Waits until the specified object is in the signaled state, an I/O completion routine or asynchronous procedure call (APC) is queued to the thread, or the time-out interval elapses.

To wait for multiple objects, use the
[WaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjectsex).

## Parameters

### `hHandle` [in]

A handle to the object. For a list of the object types whose handles can be specified, see the following Remarks section.

If this handle is closed while the wait is still pending, the function's behavior is undefined.

The handle must have the **SYNCHRONIZE** access right. For more information, see
[Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights).

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the object is signaled, an I/O completion routine or APC is queued, or the interval elapses. If *dwMilliseconds* is zero, the function does not enter a wait state if the criteria is not met; it always returns immediately. If *dwMilliseconds* is **INFINITE**, the function will return only when the object is signaled or an I/O completion routine or APC is queued.

**Windows XP, Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008, and Windows Server 2008 R2:** The *dwMilliseconds* value does include time spent in low-power states. For example, the timeout does keep counting down while the computer is asleep.

**Windows 8 and newer, Windows Server 2012 and newer:** The *dwMilliseconds* value does not include time spent in low-power states. For example, the timeout does not keep counting down while the computer is asleep.

### `bAlertable` [in]

If this parameter is **TRUE** and the thread is in the waiting state, the function returns when the system queues an I/O completion routine or APC, and the thread runs the routine or function. Otherwise, the function does not return, and the completion routine or APC function is not executed.

A completion routine is queued when the
[ReadFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-readfileex) or
[WriteFileEx](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-writefileex) function in which it was specified has completed. The wait function returns and the completion routine is called only if *bAlertable* is **TRUE**, and the calling thread is the thread that initiated the read or write operation. An APC is queued when you call
[QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc).

## Return value

If the function succeeds, the return value indicates the event that caused the function to return. It can be one of the following values.

| Return code/value | Description |
| --- | --- |
| **WAIT_ABANDONED**<br><br>0x00000080L | The specified object is a mutex object that was not released by the thread that owned the mutex object before the owning thread terminated. Ownership of the mutex object is granted to the calling thread and the mutex is set to nonsignaled.<br><br>If the mutex was protecting persistent state information, you should check it for consistency. |
| **WAIT_IO_COMPLETION**<br><br>0x000000C0L | The wait was ended by one or more user-mode [asynchronous procedure calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls) (APC) queued to the thread. |
| **WAIT_OBJECT_0**<br><br>0x00000000L | The state of the specified object is signaled. |
| **WAIT_TIMEOUT**<br><br>0x00000102L | The time-out interval elapsed, and the object's state is nonsignaled. |
| **WAIT_FAILED**<br><br>(**DWORD**)0xFFFFFFFF | The function has failed. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

The
**WaitForSingleObjectEx** function determines whether the wait criteria have been met. If the criteria have not been met, the calling thread enters the wait state until the conditions of the wait criteria have been met or the time-out interval elapses.

The function modifies the state of some types of synchronization objects. Modification occurs only for the object whose signaled state caused the function to return. For example, the count of a semaphore object is decreased by one.

The
**WaitForSingleObjectEx** function can wait for the following objects:

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
**WaitForSingleObjectEx**.

#### Examples

For an example, see
[Named Pipe Server Using Completion Routines](https://learn.microsoft.com/windows/desktop/ipc/named-pipe-server-using-completion-routines).

## See also

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions)