# DeregisterEventSource function

## Description

Closes the specified event log.

## Parameters

### `hEventLog` [in, out]

A handle to the event log. The
[RegisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registereventsourcea) function returns this handle.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[Event Sources](https://learn.microsoft.com/windows/desktop/EventLog/event-sources)

[RegisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registereventsourcea)