# NotifyChangeEventLog function

## Description

Enables an application to receive notification when an event is written to the specified event log. When the event is written to the log, the specified event object is set to the signaled state.

## Parameters

### `hEventLog` [in]

A handle to an event log. The
[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga) function returns this handle.

### `hEvent` [in]

A handle to a manual-reset or auto-reset event object. Use the
[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa) function to create the event object.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The
**NotifyChangeEventLog** function does not work with remote handles. If the *hEventLog* parameter is the handle to an event log on a remote computer, **NotifyChangeEventLog** returns zero, and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns **ERROR_INVALID_HANDLE**.

If the thread is not waiting on the event when the system calls [PulseEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-pulseevent), the thread will not receive the notification. Therefore, you should create a separate thread to wait for notifications.

The system will continue to notify you of changes until you close the handle to the event log. To close the event log, use the
[CloseEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeeventlog) or
[DeregisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deregistereventsource) function.

#### Examples

For an example, see [Receiving Event Notification](https://learn.microsoft.com/windows/desktop/EventLog/receiving-event-notification).

## See also

[CloseEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeeventlog)

[CreateEvent](https://learn.microsoft.com/windows/desktop/api/synchapi/nf-synchapi-createeventa)

[DeregisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-deregistereventsource)

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga)