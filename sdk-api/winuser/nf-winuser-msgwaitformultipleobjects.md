# MsgWaitForMultipleObjects function

## Description

Waits until one or all of the specified objects are in the signaled state or the time-out interval elapses. The objects can include input event objects, which you specify using the *dwWakeMask* parameter.

To enter an alertable wait state, use the
[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex) function.

## Parameters

### `nCount` [in]

The number of object handles in the array pointed to by *pHandles*. The maximum number of object handles is **MAXIMUM_WAIT_OBJECTS** minus one. If this parameter has the value zero, then the function waits only for an input event.

### `pHandles` [in]

An array of object handles. For a list of the object types whose handles can be specified, see the following Remarks section. The array can contain handles of objects of different types. It may not contain multiple copies of the same handle.

If one of these handles is closed while the wait is still pending, the function's behavior is undefined.

The handles must have the **SYNCHRONIZE** access right. For more information, see
[Standard Access Rights](https://learn.microsoft.com/windows/desktop/SecAuthZ/standard-access-rights).

### `fWaitAll` [in]

If this parameter is **TRUE**, the function returns when the states of all objects in the *pHandles* array have been set to signaled and an input event has been received. If this parameter is **FALSE**, the function returns when the state of any one of the objects is set to signaled or an input event has been received. In this case, the return value indicates the object whose state caused the function to return.

### `dwMilliseconds` [in]

The time-out interval, in milliseconds. If a nonzero value is specified, the function waits until the specified objects are signaled or the interval elapses. If *dwMilliseconds* is zero, the function does not enter a wait state if the specified objects are not signaled; it always returns immediately. If *dwMilliseconds* is **INFINITE**, the function will return only when the specified objects are signaled.

**Windows XP, Windows Server 2003, Windows Vista, Windows 7, Windows Server 2008, and Windows Server 2008 R2:** The *dwMilliseconds* value does include time spent in low-power states. For example, the timeout does keep counting down while the computer is asleep.

**Windows 8 and newer, Windows Server 2012 and newer:** The *dwMilliseconds* value does not include time spent in low-power states. For example, the timeout does not keep counting down while the computer is asleep.

### `dwWakeMask` [in]

The input types for which an input event object handle will be added to the array of object handles. This parameter can be any combination of the values listed in [GetQueueStatus](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-getqueuestatus) *flags* parameter.

## Return value

If the function succeeds, the return value indicates the event that caused the function to return. It can be one of the following values. (Note that **WAIT_OBJECT_0** is defined as 0 and **WAIT_ABANDONED_0** is defined as 0x00000080L.)

| Return code/value | Description |
| --- | --- |
| **WAIT_OBJECT_0** to (**WAIT_OBJECT_0** + *nCount*– 1) | If *bWaitAll* is **TRUE**, a return value within the specified range indicates that the state of all specified objects is signaled. If *bWaitAll* is **FALSE**, the return value minus **WAIT_OBJECT_0** indicates the *pHandles* array index of the object that satisfied the wait. |
| **WAIT_OBJECT_0** + *nCount* | New input of the type specified in the *dwWakeMask* parameter is available in the thread's input queue. Functions such as [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea), [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb), and [WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage) mark messages in the queue as old messages. Therefore, after you call one of these functions, a subsequent call to [MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects) will not return until new input of the specified type arrives. <br><br>This value is also returned upon the occurrence of a system event that requires the thread's action, such as foreground activation. Therefore, [MsgWaitForMultipleObjects](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjects) can return even though no appropriate input is available and even if *dwWakeMask* is set to 0. If this occurs, call [GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb) or [PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea) to process the system event before trying the call to **MsgWaitForMultipleObjects** again. |
| **WAIT_ABANDONED_0** to (**WAIT_ABANDONED_0** + *nCount*– 1) | If *bWaitAll* is **TRUE**, a return value within the specified range indicates that the state of all specified objects is signaled and at least one of the objects is an abandoned mutex object. If *bWaitAll* is **FALSE**, the return value minus **WAIT_ABANDONED_0** indicates the *pHandles* array index of an abandoned mutex object that satisfied the wait. Ownership of the mutex object is granted to the calling thread, and the mutex is set to nonsignaled.<br><br>If the mutex was protecting persistent state information, you should check it for consistency. |
| **WAIT_TIMEOUT**<br><br>258L | The time-out interval elapsed and the conditions specified by the *bWaitAll* and *dwWakeMask* parameters were not satisfied. |
| **WAIT_FAILED**<br><br>(DWORD)0xFFFFFFFF | The function has failed. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

The
**MsgWaitForMultipleObjects** function determines whether the wait criteria have been met. If the criteria have not been met, the calling thread enters the wait state until the conditions of the wait criteria have been met or the time-out interval elapses.

When *bWaitAll* is **TRUE**, the function does not modify the states of the specified objects until the states of all objects have been set to signaled. For example, a mutex can be signaled, but the thread does not get ownership until the states of the other objects have also been set to signaled. In the meantime, some other thread may get ownership of the mutex, thereby setting its state to nonsignaled.

When *bWaitAll* is **TRUE**, the function's wait is completed only when the states of all objects have been set to signaled and an input event has been received. Therefore, setting *bWaitAll* to **TRUE** prevents input from being processed until the state of all objects in the *pHandles* array have been set to signaled. For this reason, if you set *bWaitAll* to **TRUE**, you should use a short timeout value in *dwMilliseconds*. If you have a thread that creates windows waiting for all objects in the *pHandles* array, including input events specified by *dwWakeMask*, with no timeout interval, the system will deadlock. This is because threads that create windows must process messages. DDE sends message to all windows in the system. Therefore, if a thread creates windows, do not set the *bWaitAll* parameter to **TRUE** in calls to
**MsgWaitForMultipleObjects** made from that thread.

When *bWaitAll* is **FALSE**, this function checks the handles in the array in order starting with index 0, until one of the objects is signaled. If multiple objects become signaled, the function returns the index of the first handle in the array whose object was signaled.

**MsgWaitForMultipleObjects** does not return if there is unread input of the specified type in the message queue after the thread has called a function to check the queue. This is because functions such as
[PeekMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-peekmessagea),
[GetMessage](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxaccountincomingarchive-getmessage-vb),
[GetQueueStatus](https://learn.microsoft.com/windows/desktop/direct3d10/id3dx10threadpump-getqueuestatus), and
[WaitMessage](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-waitmessage) check the queue and then change the state information for the queue so that the input is no longer considered new. A subsequent call to
**MsgWaitForMultipleObjects** will not return until new input of the specified type arrives. The existing unread input (received prior to the last time the thread checked the queue) is ignored.

The function modifies the state of some types of synchronization objects. Modification occurs only for the object or objects whose signaled state caused the function to return. For example, the count of a semaphore object is decreased by one. For more information, see the documentation for the individual synchronization objects.

The
**MsgWaitForMultipleObjects** function can specify handles of any of the following object types in the *pHandles* array:

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

[MsgWaitForMultipleObjectsEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-msgwaitformultipleobjectsex)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)

[Wait Functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions)