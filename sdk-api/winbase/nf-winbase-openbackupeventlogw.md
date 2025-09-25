# OpenBackupEventLogW function

## Description

Opens a handle to a backup event log created by the [BackupEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupeventloga) function.

## Parameters

### `lpUNCServerName` [in]

The Universal Naming Convention (UNC) name of the remote server on which this operation is to be performed. If this parameter is **NULL**, the local computer is used.

### `lpFileName` [in]

The full path of the backup file.

## Return value

If the function succeeds, the return value is a handle to the backup event log.

If the function fails, the return value is **NULL**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the backup filename specifies a remote server, the *lpUNCServerName* parameter must be **NULL**.

When this function is used on Windows Vista and later computers, only backup event logs that were saved with the **BackupEventLog** function on Windows Vista and later computers can be opened.

> [!NOTE]
> The winbase.h header defines OpenBackupEventLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[BackupEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-backupeventloga)

[Event Logging Functions](https://learn.microsoft.com/windows/desktop/EventLog/event-logging-functions)