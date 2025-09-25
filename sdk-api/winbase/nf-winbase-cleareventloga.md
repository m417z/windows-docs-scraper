# ClearEventLogA function

## Description

Clears the specified event log, and optionally saves the current copy of the log to a backup file.

## Parameters

### `hEventLog` [in]

A handle to the event log to be cleared. The [OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga) function returns this handle.

### `lpBackupFileName` [in]

The absolute or relative path of the backup file. If this file already exists, the function fails.

If the *lpBackupFileName* parameter is **NULL**, the event log is not backed up.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). The
**ClearEventLog** function can fail if the event log is empty or the backup file already exists.

## Remarks

After this function returns, any handles that reference the cleared event log cannot be used to read the log.

> [!NOTE]
> The winbase.h header defines ClearEventLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)

[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga)