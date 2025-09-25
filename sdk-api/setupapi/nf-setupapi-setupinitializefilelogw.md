# SetupInitializeFileLogW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupInitializeFileLog** function initializes a file to record installation operations and outcomes. This can be the system log, where the system tracks the files installed as part of Windows, or any other file.

## Parameters

### `LogFileName` [in]

Optional pointer to the file name of the file to use as the log file. You should use a **null**-terminated string. The *LogFileName* parameter must be specified if *Flags* does not include SPFILELOG_SYSTEMLOG. The *LogFileName* parameter must not be specified if *Flags* includes SPFILELOG_SYSTEMLOG. This parameter can be **NULL**.

### `Flags` [in]

Controls the log file initialization. This parameter can be a combination of the following values.

#### SPFILELOG_SYSTEMLOG

Use the system file log. The user must be an Administrator to specify this option unless SPFILELOG_QUERYONLY is specified and *LogFileName* is not specified. Do not specify SPFILELOG_SYSTEMLOG in combination with SPFILELOG_FORCENEW.

#### SPFILELOG_FORCENEW

If the log file exists, overwrite it. If the log file exists and this flag is not specified, any new files that are installed are added to the list in the existing log file. Do not specify in combination with SPFILELOG_SYSTEMLOG.

#### SPFILELOG_QUERYONLY

Open the log file for querying only.

##### - Flags.SPFILELOG_FORCENEW

If the log file exists, overwrite it. If the log file exists and this flag is not specified, any new files that are installed are added to the list in the existing log file. Do not specify in combination with SPFILELOG_SYSTEMLOG.

##### - Flags.SPFILELOG_QUERYONLY

Open the log file for querying only.

##### - Flags.SPFILELOG_SYSTEMLOG

Use the system file log. The user must be an Administrator to specify this option unless SPFILELOG_QUERYONLY is specified and *LogFileName* is not specified. Do not specify SPFILELOG_SYSTEMLOG in combination with SPFILELOG_FORCENEW.

## Return value

The function returns the handle to the log file if it is successful. Otherwise, the return value is INVALID_HANDLE_VALUE and the logged error can be retrieved by a call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupLogFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuplogfilea)

[SetupTerminateFileLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupterminatefilelog)

## Remarks

> [!NOTE]
> The setupapi.h header defines SetupInitializeFileLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).