# GetFileVersionInfoSizeExA function

## Description

Determines whether the operating system can retrieve version information for a specified file. If version information is available, **GetFileVersionInfoSizeEx** returns the size, in bytes, of that information.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

Controls which MUI DLLs (if any) from which the version resource is extracted. Zero or more of the following flags.

| Value | Meaning |
| --- | --- |
| **FILE_VER_GET_LOCALISED**<br><br>0x01 | Loads the entire version resource (both strings and binary version information) from the corresponding MUI file, if available. |
| **FILE_VER_GET_NEUTRAL**<br><br>0x002 | Loads the version resource strings from the corresponding MUI file, if available, and loads the binary version information (**VS_FIXEDFILEINFO**) from the corresponding language-neutral file, if available. |

### `lpwstrFilename` [in]

Type: **LPCTSTR**

The name of the file of interest. The function uses the search sequence specified by the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function.

### `lpdwHandle` [out, optional]

Type: **LPDWORD**

When this function returns, contains a pointer to a variable that is set to zero because this function sets it to zero. This parameter exists for historical reasons.

## Return value

Type: **DWORD**

If the function succeeds, the return value is the size, in bytes, of the file's version information.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call the **GetFileVersionInfoSizeEx** function before calling the [GetFileVersionInfoEx](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoexa) function. The size returned by **GetFileVersionInfoSizeEx** indicates the buffer size required for the version information returned by **GetFileVersionInfoEx**.

> [!NOTE]
> The winver.h header defines GetFileVersionInfoSizeEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetFileVersionInfoEx](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoexa)

[GetFileVersionInfoSize](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizea)

**Reference**

[VS_VERSIONINFO](https://learn.microsoft.com/windows/desktop/menurc/vs-versioninfo)

[VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea)

[Version Information](https://learn.microsoft.com/windows/desktop/menurc/version-information)