# OpenEventLogA function

## Description

Opens a handle to the specified event log.

## Parameters

### `lpUNCServerName` [in]

The Universal Naming Convention (UNC) name of the remote server on which the event log is to be opened. If this parameter is **NULL**, the local computer is used.

### `lpSourceName` [in]

The name of the log.

If you specify a custom log and it cannot be found, the event logging service opens the **Application** log; however, there will be no associated message or category string file.

## Return value

If the function succeeds, the return value is the handle to an event log.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To close the handle to the event log, use the
[CloseEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeeventlog) function.

#### Examples

For an example, see
[Querying for Event Information](https://learn.microsoft.com/windows/desktop/EventLog/querying-for-event-source-messages).

> [!NOTE]
> The winbase.h header defines OpenEventLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ClearEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-cleareventloga)

[CloseEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-closeeventlog)

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[Eventlog Key](https://learn.microsoft.com/windows/desktop/EventLog/eventlog-key)

[ReadEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-readeventloga)

[ReportEvent](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-reporteventa)