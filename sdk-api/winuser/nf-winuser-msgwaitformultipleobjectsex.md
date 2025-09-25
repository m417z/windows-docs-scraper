# MsgWaitForMultipleObjectsEx function

## Description

Waits until one or all of the specified objects are in the signaled state, an I/O completion routine or asynchronous procedure call (APC) is queued to the thread, or the time-out interval elapses. The array of objects can include input event objects, which you specify using the *dwWakeMask* parameter.

## Parameters

### `nCount` [in]

The number of object handles in the array pointed to by *pHandles*. The maximum number of object handles is **MAXIMUM_WAIT_OBJECTS** minus one. If this parameter has the value zero, then the function waits only for an input event.

### `pHandles` [in]

An array of object handles. For a list of the object types whose handles you can specify, see the Remarks section later in this topic. The array can contain handles to multiple types of objects. It may not contain multiple copies of the same handle.

If one of these handles is closed while the wait is still pending, the function's behavior is undefined.

The handles must have the **SYNCHRONIZE** access right. For more information, see
[Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights).

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the specified objects are signaled, an I/O completion routine or APC is queued, or the interval elapses. If *dwMilliseconds* is zero, the function does not enter a wait state if the criteria is not met; it always returns immediately. If *dwMilliseconds* is **INFINITE**, the function will return only when the specified objects are signaled or an I/O completion routine or APC is queued.

**Windows XP, Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008, and Windows Server 2008 R2:** The *dwMilliseconds* value does include time spent in low-power states. For example, the timeout does keep counting down while the computer is asleep.

**Windows 8 and newer, Windows Server 2012 and newer:** The *dwMilliseconds* value does not include time spent in low-power states. For example, the timeout does not keep counting down while the computer is asleep.

### `dwWakeMask` [in]

The input types for which an input event object handle will be added to the array of object handles. This parameter can be any combination of the values listed in [GetQueueStatus](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getqueuestatus) *flags* parameter.

### `dwFlags` [in]

The wait type. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| 0 | The function returns when any one of the objects is signaled. The return value indicates the object whose state caused the function to return. |
| **MWMO_ALERTABLE**<br><br>0x0002 | The function also returns if an APC has been queued to the thread with [QueueUserAPC](https://learn.microsoft.com/windows/desktop/api/processthreadsapi/nf-processthreadsapi-queueuserapc) while the thread is in the waiting state. |
| **MWMO_INPUTAVAILABLE**<br><br>0x0004 | The function returns if input exists for the queue, even if the input has been seen (but not removed) using a call to another function, such as [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea). |
| **MWMO_WAITALL**<br><br>0x0001 | The function returns when all objects in the *pHandles* array are signaled and an input event has been received, all at the same time. |

## Return value

If the function succeeds, the return value indicates the event that caused the function to return. It can be one of the following values. (Note that **WAIT_OBJECT_0** is defined as 0 and **WAIT_ABANDONED_0** is defined as 0x00000080L.)

| Return code/value | Description |
| --- | --- |
| **WAIT_OBJECT_0** to (**WAIT_OBJECT_0** + *nCount* - 1) | If the **MWMO_WAITALL** flag is used, a return value within the specified range indicates that the state of all specified objects is signaled. Otherwise, the return value minus **WAIT_OBJECT_0** indicates the *pHandles* array index of the object that caused the function to return. |
| **WAIT_OBJECT_0** + *nCount* | New input of the type specified in the *dwWakeMask* parameter is available in the thread's input queue. Functions such as [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea), [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb), [GetQueueStatus](https://learn.microsoft.com/windows/desktop/direct3d10/id3dx10threadpump-getqueuestatus), and [WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage) mark messages in the queue as old messages. Therefore, after you call one of these functions, a subsequent call to [MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex) will not return until new input of the specified type arrives. <br><br>This value is also returned upon the occurrence of a system event that requires the thread's action, such as foreground activation. Therefore, [MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex) can return even though no appropriate input is available and even if *dwWakeMask* is set to 0. If this occurs, call [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) to process the system event before trying the call to **MsgWaitForMultipleObjectsEx** again. |
| **WAIT_ABANDONED_0** to (**WAIT_ABANDONED_0** + *nCount* - 1) | If the **MWMO_WAITALL** flag is used, a return value within the specified range indicates that the state of all specified objects is signaled and at least one of the objects is an abandoned mutex object. Otherwise, the return value minus **WAIT_ABANDONED_0** indicates the *pHandles* array index of an abandoned mutex object that caused the function to return. Ownership of the mutex object is granted to the calling thread, and the mutex is set to nonsignaled.<br><br>If the mutex was protecting persistent state information, you should check it for consistency. |
| **WAIT_IO_COMPLETION**<br><br>0x000000C0L | The wait was ended by one or more user-mode [asynchronous procedure calls](https://learn.microsoft.com/windows/desktop/Sync/asynchronous-procedure-calls) (APC) queued to the thread. |
| **WAIT_TIMEOUT**<br><br>258L | The time-out interval elapsed, but the conditions specified by the *dwFlags* and *dwWakeMask* parameters were not met. |
| **WAIT_FAILED**<br><br>(DWORD)0xFFFFFFFF | The function has failed. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

The
**MsgWaitForMultipleObjectsEx** function determines whether the conditions specified by *dwWakeMask* and *dwFlags* have been met. If the conditions have not been met, the calling thread enters the wait state until the conditions of the wait criteria have been met or the time-out interval elapses.

When *dwFlags* is zero, this function checks the handles in the array in order starting with index 0, until one of the objects is signaled. If multiple objects become signaled, the function returns the index of the first handle in the array whose object was signaled.

**MsgWaitForMultipleObjectsEx** does not return if there is unread input of the specified type in the message queue after the thread has called a function to check the queue, unless you use the **MWMO_INPUTAVAILABLE** flag. This is because functions such as
[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea),
[GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb),
[GetQueueStatus](https://learn.microsoft.com/windows/desktop/direct3d10/id3dx10threadpump-getqueuestatus), and
[WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage) check the queue and then change the state information for the queue so that the input is no longer considered new. A subsequent call to
**MsgWaitForMultipleObjectsEx** will not return until new input of the specified type arrives, unless you use the **MWMO_INPUTAVAILABLE** flag. If this flag is not used, the existing unread input (received prior to the last time the thread checked the queue) is ignored.

The function modifies the state of some types of synchronization objects. Modification occurs only for the object or objects whose signaled state caused the function to return. For example, the system decreases the count of a semaphore object by one. For more information, see the documentation for the individual synchronization objects.

The
**MsgWaitForMultipleObjectsEx** function can specify handles of any of the following object types in the *pHandles* array:

* Change notification
* Console input
* Event
* Memory resource notification
* Mutex
* Process
* Semaphore
* Thread
* Waitable timer

## See also

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions)