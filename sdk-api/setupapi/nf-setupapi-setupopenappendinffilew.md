# SetupOpenAppendInfFileW function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupOpenAppendInfFile** function appends the information in an INF file to an INF file previously opened by
[SetupOpenInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopeninffilea).

## Parameters

### `FileName` [in]

If not **NULL**, *FileName* points to a **null**-terminated string containing the name (and optionally the path) of the INF file to be opened. If the filename does not contain path separator characters, it is searched for, first in the %windir%\inf directory, and then in the %windir%\system32 directory. If the filename contains path separator characters, it is assumed to be a full path specification and no further processing is performed on it. If *FileName* is **NULL**, the INF filename is retrieved from the LayoutFile value of the **Version** section in the existing INF file. The same search logic is applied to the filename retrieved from the LayoutFile key.

### `InfHandle` [in]

Existing INF handle to which this INF file will be appended.

### `ErrorLine` [in, out]

Optional pointer to a variable to which this function returns the (1-based) line number where an error occurred during loading of the INF file. This value is generally reliable only if
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) does not return ERROR_NOT_ENOUGH_MEMORY. If an out-of-memory condition does occur, *ErrorLine* may be 0.

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If *FileName* was not specified and there was no LayoutFile value in the **Version** section of the existing INF File,
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INVALID_DATA.

## Remarks

This function requires a Windows INF file. Some older INF file formats may not be supported. In this case, the function returns **FALSE** and
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return ERROR_INVALID_PARAMETER. The main purpose of this function is to combine an INF file with the source file location information contained in the file specified in the LayoutFile entry of the **Version** section (typically, LAYOUT.INF).

The ERROR_WRONG_INF_STYLE may also be returned by **SetupOpenAppendInfFile** if the INF file uses an older format.

> [!NOTE]
> The setupapi.h header defines SetupOpenAppendInfFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCloseInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcloseinffile)

[SetupOpenInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopeninffilea)