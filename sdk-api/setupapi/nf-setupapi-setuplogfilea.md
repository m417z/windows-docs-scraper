# SetupLogFileA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupLogFile** function adds an entry to the log file.

## Parameters

### `FileLogHandle` [in]

Handle to the file log as returned by
[SetupInitializeFileLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitializefileloga). The caller must not have passed SPFILELOG_QUERYONLY when the log file was initialized.

### `LogSectionName` [in]

Optional pointer to the name for a logical grouping of names within the log file. You should use a **null**-terminated string. Required if SPFILELOG_SYSTEMLOG was not passed when the file log was initialized. Otherwise, this parameter can be **NULL**.

### `SourceFilename` [in]

Name of the file as it exists on the source media from which it was installed. This name should be in whatever format is meaningful to the caller. You should use a **null**-terminated string.

### `TargetFilename` [in]

Name of the file as it exists on the target. This name should be in whatever format is meaningful to the caller. You should use a **null**-terminated string.

### `Checksum` [in]

Optional pointer to a checksum value. Required for the system log.

### `DiskTagfile` [in]

Optional pointer to the tagfile for the media from which the file was installed. You should use a **null**-terminated string. The **null**-terminated string should not exceed the size of the destination buffer. Ignored for the system log if SPFILELOG_OEMFILE is not specified. Required for the system log if SPFILELOG_OEMFILE is specified. Otherwise, this parameter can be **NULL**.

### `DiskDescription` [in]

Optional pointer to the human-readable description of the media from which the file was installed. You should use a **null**-terminated string. Ignored for the system log if SPFILELOG_OEMFILE is not specified in the *Flags* parameter. Required for the system log if SPFILELOG_OEMFILE is specified in the Flags parameter. Otherwise, this parameter can be **NULL**.

### `OtherInfo` [in]

Optional pointer to additional information to be associated with the file. You should use a **null**-terminated string. This parameter can be **NULL**.

### `Flags` [in]

This parameter can be SPFILELOG_OEMFILE, which is meaningful only for the system log and indicates that the file is not supplied by Microsoft. This parameter can be used to convert an existing file's entry, such as when an OEM overwrites a Microsoft-supplied system file.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupRemoveFileLogEntry](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupremovefilelogentrya)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupLogFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).