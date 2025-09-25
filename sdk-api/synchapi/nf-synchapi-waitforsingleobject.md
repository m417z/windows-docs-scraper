# WaitForSingleObject function

## Description

Waits until the specified object is in the signaled state or the time-out interval elapses.

To enter an alertable wait state, use the
[WaitForSingleObjectEx](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobjectex) function. To wait for multiple objects, use
[WaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitformultipleobjects).

## Parameters

### `hHandle` [in]

A handle to the object. For a list of the object types whose handles can be specified, see the following Remarks section.

If this handle is closed while the wait is still pending, the function's behavior is undefined.

The handle must have the **SYNCHRONIZE** access right. For more information, see
[Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights).

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the object is signaled or the interval elapses. If *dwMilliseconds* is zero, the function does not enter a wait state if the object is not signaled; it always returns immediately. If *dwMilliseconds* is **INFINITE**, the function will return only when the object is signaled.

**Windows XP, Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008, and Windows Server 2008 R2:** The *dwMilliseconds* value does include time spent in low-power states. For example, the timeout does keep counting down while the computer is asleep.

**Windows 8 and newer, Windows Server 2012 and newer:** The *dwMilliseconds* value does not include time spent in low-power states. For example, the timeout does not keep counting down while the computer is asleep.

## Return value

If the function succeeds, the return value indicates the event that caused the function to return. It can be one of the following values.

| Return code/value | Description |
| --- | --- |
| **WAIT_ABANDONED**<br><br>0x00000080L | The specified object is a mutex object that was not released by the thread that owned the mutex object before the owning thread terminated. Ownership of the mutex object is granted to the calling thread and the mutex state is set to nonsignaled.<br><br>If the mutex was protecting persistent state information, you should check it for consistency. |
| **WAIT_OBJECT_0**<br><br>0x00000000L | The state of the specified object is signaled. |
| **WAIT_TIMEOUT**<br><br>0x00000102L | The time-out interval elapsed, and the object's state is nonsignaled. |
| **WAIT_FAILED**<br><br>(DWORD)0xFFFFFFFF | The function has failed. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

The
**WaitForSingleObject** function checks the current state of the specified object. If the object's state is nonsignaled, the calling thread enters the wait state until the object is signaled or the time-out interval elapses.

The function modifies the state of some types of synchronization objects. Modification occurs only for the object whose signaled state caused the function to return. For example, the count of a semaphore object is decreased by one.

The
**WaitForSingleObject** function can wait for the following objects:

* Change notification
* Console input
* Event
* Memory resource notification
* Mutex
* Process
* Semaphore
* Thread
* Waitable timer

Use caution when calling the wait functions and code that directly or indirectly creates windows. If a thread creates any windows, it must process messages. Message broadcasts are sent to all windows in the system. A thread that uses a wait function with an **INFINITE** time-out interval may cause the system to become deadlocked. Two examples of code that indirectly creates windows are DDE and the [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) function. Therefore, if you have a thread that creates windows, use
[MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects) or
[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex), rather than
**WaitForSingleObject**.

#### Examples

For an example, see
[Using Mutex Objects](https://learn.microsoft.com/windows/desktop/Sync/using-mutex-objects).

## See also

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions)