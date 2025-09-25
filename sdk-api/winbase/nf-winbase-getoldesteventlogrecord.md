# GetOldestEventLogRecord function

## Description

Retrieves the absolute record number of the oldest record in the specified event log.

## Parameters

### `hEventLog` [in]

A handle to the open event log. The
[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga) or
[OpenBackupEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openbackupeventloga) function returns this handle.

### `OldestRecord` [out]

A pointer to a variable that receives the absolute record number of the oldest record in the specified event log.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The oldest record in an event log is not necessarily record number 1. For more information, see
[Event Log Records](https://learn.microsoft.com/windows/desktop/EventLog/event-log-records).

#### Examples

For an example, see
[Querying for Event Information](https://learn.microsoft.com/windows/desktop/EventLog/querying-for-event-source-messages).

## See also

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[GetNumberOfEventLogRecords](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getnumberofeventlogrecords)

[OpenBackupEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openbackupeventloga)

[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga)