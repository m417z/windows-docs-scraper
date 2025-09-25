# SetupLogErrorA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupLogError** function writes an error message to a log file. It is meant to be used during the installation of Windows, but it is always available. It is not intended to be used after the operating system is installed — the event log should be used instead.

## Parameters

### `MessageString` [in]

Pointer to the string that should be saved to Setup's log. The message must end with a return-linefeed combination (\r\n). You should use a null-terminated string. The null-terminated string should not exceed the size of the destination buffer. The message is always saved to the action log, setupact.log. If *Severity* is **LogSevWarning**, **LogSevError**, or **LogSevFatalError**, Setup also saves the message to the error log, setuperr.log. Both logs are stored in the Windows directory.

### `Severity` [in]

Severity of the message, one of the following: **LogSevInformation**, **LogSevWarning**, **LogSevError**, or **LogSevFatalError**.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

* The action log is intended for recording all modifications made to the system during installation of Windows.
* The error log is intended for errors during installation of Windows only.
* The *MessageString* parameter may be formatted further by Setup (though it does no additional processing now).
* The error log will be presented to the user at the end of system setup.

> [!NOTE]
> The setupapi.h header defines SetupLogError as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)