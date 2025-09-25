# SignalObjectAndWait function

## Description

Signals one object and waits on another object as a single operation.

## Parameters

### `hObjectToSignal` [in]

A handle to the object to be signaled. This object can be a semaphore, a mutex, or an event.

If the handle is a semaphore, the **SEMAPHORE_MODIFY_STATE** access right is required. If the handle is an event, the **EVENT_MODIFY_STATE** access right is required. If the handle is a mutex and the caller does not own the mutex, the function fails with **ERROR_NOT_OWNER**.

### `hObjectToWaitOn` [in]

A handle to the object to wait on. The **SYNCHRONIZE** access right is required; for more information, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights). For a list of the object types whose handles you can specify, see the Remarks section.

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. The function returns if the interval elapses, even if the object's state is nonsignaled and no completion or asynchronous procedure call (APC) objects are queued. If *dwMilliseconds* is zero, the function tests the object's state, checks for queued completion routines or APCs, and returns immediately. If *dwMilliseconds* is **INFINITE**, the function's time-out interval never elapses.

### `bAlertable` [in]

If this parameter is **TRUE**, the function returns when the system queues an I/O completion routine or APC function, and the thread calls the function. If **FALSE**, the function does not return, and the thread does not call the completion routine or APC function.

A completion routine is queued when the
function call that queued the APC has completed. This function returns and the completion routine is called only if *bAlertable* is **TRUE**, and the calling thread is the thread that queued the APC.

## Return value

If the function succeeds, the return value indicates the event that caused the function to return. It can be one of the following values.

| Return code/value | Description |
| --- | --- |
| **WAIT_ABANDONED**<br><br>0x00000080L | The specified object is a mutex object that was not released by the thread that owned the mutex object before the owning thread terminated. Ownership of the mutex object is granted to the calling thread, and the mutex is set to nonsignaled.<br><br>If the mutex was protecting persistent state information, you should check it for consistency. |
| **WAIT_IO_COMPLETION**<br><br>0x000000C0L | The wait was ended by one or more user-mode [asynchronous procedure calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls) (APC) queued to the thread. |
| **WAIT_OBJECT_0**<br><br>0x00000000L | The state of the specified object is signaled. |
| **WAIT_TIMEOUT**<br><br>0x00000102L | The time-out interval elapsed, and the object's state is nonsignaled. |
| **WAIT_FAILED**<br><br>(**DWORD**)0xFFFFFFFF | The function has failed. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

The **SignalObjectAndWait** function provides a more efficient way to signal one object and then wait on another compared to separate function calls such as [SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent) followed by [WaitForSingleObject](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject).

The
**SignalObjectAndWait** function can wait for the following objects:

* Change notification
* Console input
* Event
* Memory resource notification
* Mutex
* Process
* Semaphore
* Thread
* Waitable timer

For more information, see
[Synchronization Objects](https://learn.microsoft.com/windows/desktop/Sync/synchronization-objects).

A thread can use the **SignalObjectAndWait** function to ensure that a worker thread is in a wait state before signaling an object. For example, a thread and a worker thread may use handles to event objects to synchronize their work. The thread executes code such as the following:

``` syntax
  dwRet = WaitForSingleObject(hEventWorkerDone, INFINITE);
  if( WAIT_OBJECT_0 == dwRet)
    SetEvent(hEventMoreWorkToDo);

```

The worker thread executes code such as the following:

``` syntax
  dwRet = SignalObjectAndWait(hEventWorkerDone,
                              hEventMoreWorkToDo,
                              INFINITE,
                              FALSE);

```

Note that the "signal" and "wait" are not guaranteed to be performed as an atomic operation. Threads executing on other processors can observe the signaled state of the first object before the thread calling **SignalObjectAndWait** begins its wait on the second object.

Use extreme caution when using **SignalObjectAndWait** and [PulseEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-pulseevent) with Windows 7, since using these APIs among multiple threads can cause an application to deadlock. Threads that are signaled by **SignalObjectAndWait** call **PulseEvent** to signal the waiting object of the **SignalObjectAndWait** call. In some circumstances, the caller of **SignalObjectAndWait** can't receive signal state of the waiting object in time, causing a deadlock.

Use caution when using the wait functions and code that directly or indirectly creates windows. If a thread creates any windows, it must process messages. Message broadcasts are sent to all windows in the system. A thread that uses a wait function with no time-out interval may cause the system to become deadlocked. Two examples of code that indirectly creates windows are DDE and COM **CoInitialize**. Therefore, if you have a thread that creates windows, be sure to call **SignalObjectAndWait** from a different thread. If this is not possible, you can use
[MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects) or
[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex), but the functionality is not equivalent.

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0400 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

## See also

[MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects)

[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions)