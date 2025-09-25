# SetupRemoveFileLogEntryA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupRemoveFileLogEntry** function removes an entry or section from a file log.

## Parameters

### `FileLogHandle` [in]

Handle to the file log as returned by
[SetupInitializeFileLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitializefileloga). The caller must not have passed SPFILELOG_QUERYONLY when the log file was initialized.

### `LogSectionName` [in]

Pointer to a **null**-terminated string that specifies the name for a logical grouping of names within the log file. Required for non-system logs. Otherwise, *LogSectionName* may be **NULL**.

### `TargetFilename` [in]

Pointer to a **null**-terminated string that specifies the name of the file as it exists on the target. This name should be in whatever format is meaningful to the caller. If **NULL**, the section specified by *LogSectionName* is removed. The main section cannot be removed.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupLogFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuplogfilea)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupRemoveFileLogEntry as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).