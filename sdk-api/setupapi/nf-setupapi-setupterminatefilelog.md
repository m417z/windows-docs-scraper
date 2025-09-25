# SetupTerminateFileLog function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupTerminateFileLog** function releases resources associated with a file log.

## Parameters

### `FileLogHandle` [in]

Handle to the log file as returned by a call to
[SetupInitializeFileLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitializefileloga).

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupInitializeFileLog](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupinitializefileloga)

[SetupLogFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setuplogfilea)