# GetEventLogInformation function

## Description

Retrieves information about the specified event log.

## Parameters

### `hEventLog` [in]

A handle to the event log. The
[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga) or
[RegisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registereventsourcea) function returns this handle.

### `dwInfoLevel` [in]

The level of event log information to return.

This parameter can be the following value.

| Value | Meaning |
| --- | --- |
| **EVENTLOG_FULL_INFO** | Indicate whether the specified log is full. The *lpBuffer* parameter will contain an [EVENTLOG_FULL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-eventlog_full_information) structure. |

### `lpBuffer` [out]

An application-allocated buffer that receives the event log information. The format of this data depends on the value of the *dwInfoLevel* parameter.

### `cbBufSize` [in]

The size of the *lpBuffer* buffer, in bytes.

### `pcbBytesNeeded` [out]

The function sets this parameter to the required buffer size for the requested information, regardless of whether the function succeeds. Use this value if the function fails with **ERROR_INSUFFICIENT_BUFFER** to allocate a buffer of the correct size.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[EVENTLOG_FULL_INFORMATION](https://learn.microsoft.com/windows/desktop/api/winbase/ns-winbase-eventlog_full_information)

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga)

[RegisterEventSource](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registereventsourcea)