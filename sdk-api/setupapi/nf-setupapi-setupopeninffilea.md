# SetupOpenInfFileA function

## Description

[This function is available for use in the operating systems indicated in the Requirements section. It may be altered or unavailable in subsequent versions. SetupAPI should no longer be used for installing applications. Instead, use the Windows Installer for developing application installers. SetupAPI continues to be used for installing device drivers.]

The
**SetupOpenInfFile** function opens an INF file and returns a handle to it.

## Parameters

### `FileName` [in]

Pointer to a null-terminated string containing the name (and optional path) of the INF file to be opened. If the filename does not contain path separator characters, it is searched for, first in the %windir%\inf directory, and then in the %windir%\system32 directory. If the filename contains path separator characters, it is assumed to be a full path specification and no further processing is performed on it.

### `InfClass` [in]

Optional pointer to a null-terminated string containing the class of INF file desired. This string must match the Class value of the **Version** section (for example, Class=Net). If there is no entry in the Class value, but there is an entry for ClassGUID in the **Version** section, the corresponding class name for that GUID is retrieved and used for the comparison.

### `InfStyle` [in]

Style of INF file to open or search for. This parameter can be a combination of the following flags.

#### INF_STYLE_OLDNT

A legacy INF file format.

#### INF_STYLE_WIN4

A Windows INF file format.

### `ErrorLine` [in]

Optional pointer to a variable to which this function returns the (1-based) line number where an error occurred during loading of the INF file. This value is generally reliable only if
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) does not return ERROR_NOT_ENOUGH_MEMORY. If an out-of-memory condition does occur, *ErrorLine* may be 0.

## Return value

The function returns a handle to the opened INF file if it is successful. Otherwise, the return value is INVALID_HANDLE_VALUE. Extended error information can be retrieved by a call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the load fails because the INF file type does not match *InfClass*, the function returns INVALID_HANDLE_VALUE and a call to
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_CLASS_MISMATCH.

If multiple INF file styles are specified, the style of the INF file opened can be determined by calling the
[SetupGetInfInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfinformationa) function.

Because there may be more than one class GUID with the same class name, callers interested in INF files of a particular class (that is, a particular class GUID) should retrieve the ClassGUID value from the INF file by calling
[SetupQueryInfVersionInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupqueryinfversioninformationa).

For legacy INF files, the *InfClass* string must match the type specified in the OptionType value of the **Identification** section in the INF file (for example, OptionType=NetAdapter).

> [!NOTE]
> The setupapi.h header defines SetupOpenInfFile as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/SetupApi/functions)

[Overview](https://learn.microsoft.com/windows/desktop/SetupApi/overview)

[SetupCloseInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupcloseinffile)

[SetupGetInfInformation](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupgetinfinformationa)

[SetupOpenAppendInfFile](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupopenappendinffilea)