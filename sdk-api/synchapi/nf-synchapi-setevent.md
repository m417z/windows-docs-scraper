# SetEvent function

## Description

Sets the specified event object to the signaled state.

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

The state of a **manual-reset** event object remains signaled until it is set explicitly to the nonsignaled state by the
[ResetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-resetevent) function. Any number of waiting threads, or threads that subsequently begin wait operations for the specified event object by calling one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions), can be released while the object's state is signaled.

In contrast, the state of an **auto-reset** event object remains signaled until a single waiting thread is released, at which time the system automatically sets the state to nonsignaled. If no threads are waiting, the event object's state remains signaled.

Setting an event that is already set has no effect.

Windows Store apps can respond to named events and semaphores as described in [How to respond to named events and semaphores](https://learn.microsoft.com/previous-versions/windows/apps/jj248674(v=win.10)).

#### Examples

For an example that uses
**SetEvent**, see
[Using Event Objects](https://learn.microsoft.com/windows/desktop/Sync/using-event-objects).

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects)

[OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa)

[PulseEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-pulseevent)

[ResetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-resetevent)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)