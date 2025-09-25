# PulseEvent function

## Description

Sets the specified event object to the signaled state and then resets it to the nonsignaled state after releasing the appropriate number of waiting threads.

**Note** This function is unreliable and should not be used. It exists mainly for backward compatibility. For more information, see Remarks.

## Parameters

### `hEvent` [in]

A handle to the event object. The
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) or
[OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa) function returns this handle.

The handle must have the EVENT_MODIFY_STATE access right. For more information, see
[Synchronization Object Security and Access Rights](https://learn.microsoft.com/windows/desktop/Sync/synchronization-object-security-and-access-rights).

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

A thread waiting on a synchronization object can be momentarily removed from the wait state by a kernel-mode APC, and then returned to the wait state after the APC is complete. If the call to **PulseEvent** occurs during the time when the thread has been removed from the wait state, the thread will not be released because **PulseEvent** releases only those threads that are waiting at the moment it is called. Therefore, **PulseEvent** is unreliable and should not be used by new applications.
Instead, use [condition variables](https://learn.microsoft.com/windows/desktop/Sync/condition-variables).

For a manual-reset event object, all waiting threads that can be released immediately are released. The function then resets the event object's state to nonsignaled and returns.

For an auto-reset event object, the function resets the state to nonsignaled and returns after releasing a single waiting thread, even if multiple threads are waiting.

If no threads are waiting, or if no thread can be released immediately,
**PulseEvent** simply sets the event object's state to nonsignaled and returns.

Note that for a thread using the multiple-object
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions) to wait for all specified objects to be signaled,
**PulseEvent** can set the event object's state to signaled and reset it to nonsignaled without causing the wait function to return. This happens if not all of the specified objects are simultaneously signaled.

Use extreme caution when using [SignalObjectAndWait](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-signalobjectandwait) and **PulseEvent** with Windows 7, since using these APIs among multiple threads can cause an application to deadlock. Threads that are signaled by **SignalObjectAndWait** call **PulseEvent** to signal the waiting object of the **SignalObjectAndWait** call. In some circumstances, the caller of **SignalObjectAndWait** can't receive signal state of the waiting object in time, causing a deadlock.

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects)

[OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa)

[ResetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-resetevent)

[SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)