# MsiEnableLogA function

## Description

The
**MsiEnableLog** function sets the log mode for all subsequent installations that are initiated in the calling process.

## Parameters

### `dwLogMode` [in]

Specifies the log mode. This parameter can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **INSTALLLOGMODE_FATALEXIT** | Logs out of memory or fatal exit information. |
| **INSTALLLOGMODE_ERROR** | Logs the error messages. |
| **INSTALLLOGMODE_EXTRADEBUG** | Sends extra debugging information, such as handle creation information, to the log file. <br><br>**Windows 2000 and Windows XP:** This feature is not supported. |
| **INSTALLLOGMODE_WARNING** | Logs the warning messages. |
| **INSTALLLOGMODE_USER** | Logs the user requests. |
| **INSTALLLOGMODE_INFO** | Logs the status messages that are not displayed. |
| **INSTALLLOGMODE_RESOLVESOURCE** | Request to determine a valid source location. |
| **INSTALLLOGMODE_OUTOFDISKSPACE** | Indicates insufficient disk space. |
| **INSTALLLOGMODE_ACTIONSTART** | Logs the start of new installation actions. |
| **INSTALLLOGMODE_ACTIONDATA** | Logs the data record with the installation action. |
| **INSTALLLOGMODE_COMMONDATA** | Logs the parameters for user-interface initialization. |
| **INSTALLLOGMODE_PROPERTYDUMP** | Logs the property values at termination. |
| **INSTALLLOGMODE_VERBOSE** | Logs the information in all the other log modes, except for **INSTALLLOGMODE_EXTRADEBUG**. This sends large amounts of information to a log file not generally useful to users. May be used for technical support. |
| **INSTALLLOGMODE_LOGONLYONERROR** | Logging information is collected but is less frequently saved to the log file. This can improve the performance of some installations, but may have little benefit for large installations. The log file is removed when the installation succeeds. If the installation fails, all logging information is saved to the log file. <br><br>**Windows Installer 2.0:** This log mode is not available. |

### `szLogFile` [in]

Specifies the string that holds the full path to the log file. Entering a null disables logging, in which case *dwlogmode* is ignored. If a path is supplied, then *dwlogmode* must not be zero.

### `dwLogAttributes` [in]

Specifies how frequently the log buffer is to be flushed.

| Value | Meaning |
| --- | --- |
| **INSTALLLOGATTRIBUTES_APPEND** | If this value is set, the installer appends the existing log specified by *szLogFile*. If not set, any existing log specified by *szLogFile* is overwritten. |
| **INSTALLLOGATTRIBUTES_FLUSHEACHLINE** | Forces the log buffer to be flushed after each line. If this value is not set, the installer flushes the log buffer after 20 lines by calling [FlushFileBuffers](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-flushfilebuffers). |

## Return value

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | An invalid log mode was specified. |
| **ERROR_SUCCESS** | The function succeeded. |

## Remarks

For a description of the Logging policy, see
[System Policy](https://learn.microsoft.com/windows/desktop/Msi/system-policy).

The path to the log file location must already exist when using this function. The Installer does not create the directory structure for the log file.

> [!NOTE]
> The msi.h header defines MsiEnableLog as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Interface and Logging Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)

[Logging](https://learn.microsoft.com/windows/desktop/Msi/logging)