# BackupEventLogW function

## Description

Saves the specified event log to a backup file. The function does not clear the event log.

## Parameters

### `hEventLog` [in]

A handle to the open event log. The [OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga) function returns this handle.

### `lpBackupFileName` [in]

The absolute or relative path of the backup file.

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **BackupEventLog** function fails with the ERROR_PRIVILEGE_NOT_HELD error if the user does not have the SE_BACKUP_NAME privilege.

> [!NOTE]
> The winbase.h header defines BackupEventLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[OpenBackupEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openbackupeventloga)

[OpenEventLog](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-openeventloga)