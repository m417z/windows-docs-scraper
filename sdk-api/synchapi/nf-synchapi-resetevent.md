# ResetEvent function

## Description

Sets the specified event object to the nonsignaled state.

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

The state of an event object remains nonsignaled until it is explicitly set to signaled by the
[SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent) or
[PulseEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-pulseevent) function. This nonsignaled state blocks the execution of any threads that have specified the event object in a call to one of the
[wait functions](https://learn.microsoft.com/windows/desktop/Sync/wait-functions).

The
**ResetEvent** function is used primarily for manual-reset event objects, which must be set explicitly to the nonsignaled state. Auto-reset event objects automatically change from signaled to nonsignaled after a single waiting thread is released.

Resetting an event that is already reset has no effect.

## See also

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[Event Objects](https://learn.microsoft.com/windows/desktop/Sync/event-objects)

[OpenEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-openeventa)

[PulseEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-pulseevent)

[SetEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-setevent)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)