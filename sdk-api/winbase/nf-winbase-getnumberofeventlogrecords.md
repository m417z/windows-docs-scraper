# GetNumberOfEventLogRecords function

## Description

Retrieves the number of records in the specified event log.

## Parameters

### `hEventLog` [in]

A handle to the open event log. The
[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga) or
[OpenBackupEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openbackupeventloga) function returns this handle.

### `NumberOfRecords` [out]

A pointer to a variable that receives the number of records in the specified event log.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The oldest record in an event log is not necessarily record number 1. To determine the oldest record number in an event log, use the
[GetOldestEventLogRecord](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getoldesteventlogrecord) function.

## See also

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[GetOldestEventLogRecord](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-getoldesteventlogrecord)

[OpenBackupEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openbackupeventloga)

[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga)