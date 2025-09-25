# GetFileVersionInfoExA function

## Description

Retrieves version information for the specified file.

## Parameters

### `dwFlags` [in]

Type: **DWORD**

Controls the MUI DLLs (if any) from which the version resource is extracted. The value of this flag must match the flags passed to the corresponding [GetFileVersionInfoSizeEx](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizeexa) call, which was used to determine the buffer size that is passed in the *dwLen* parameter. Zero or more of the following flags.

| Value | Meaning |
| --- | --- |
| **FILE_VER_GET_LOCALISED**<br><br>0x01 | Loads the entire version resource (both strings and binary version information) from the corresponding MUI file, if available. |
| **FILE_VER_GET_NEUTRAL**<br><br>0x02 | Loads the version resource strings from the corresponding MUI file, if available, and loads the binary version information (**VS_FIXEDFILEINFO**) from the corresponding language-neutral file, if available. |
| **FILE_VER_GET_PREFETCHED**<br><br>0x04 | Indicates a preference for version.dll to attempt to preload the image outside of the loader lock to avoid contention. This flag does not change the behavior or semantics of the function. |

### `lpwstrFilename` [in]

Type: **LPCTSTR**

The name of the file. If a full path is not specified, the function uses the search sequence specified by the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function.

### `dwHandle`

Type: **DWORD**

This parameter is reserved, and expected to be zero (0).

### `dwLen` [in]

Type: **DWORD**

The size, in bytes, of the buffer pointed to by the *lpData* parameter.

Call the [GetFileVersionInfoSizeEx](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizeexa) function first to determine the size, in bytes, of a file's version information. The *dwLen* parameter should be equal to or greater than that value.

If the buffer pointed to by *lpData* is not large enough, the function truncates the file's version information to the size of the buffer.

### `lpData` [out]

Type: **LPVOID**

When this function returns, contains a pointer to a buffer that contains the file-version information.

You can use this value in a subsequent call to the [VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea) function to retrieve data from the buffer.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call the [GetFileVersionInfoSizeEx](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizeexa) function before calling the **GetFileVersionInfoEx** function. To retrieve information from the file-version information buffer, use the [VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea) function.

> [!NOTE]
> The winver.h header defines GetFileVersionInfoEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetFileVersionInfo](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoa)

[GetFileVersionInfoSizeEx](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizeexa)

**Reference**

[VS_VERSIONINFO](https://learn.microsoft.com/windows/desktop/menurc/vs-versioninfo)

[VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea)

[Version Information](https://learn.microsoft.com/windows/desktop/menurc/version-information)