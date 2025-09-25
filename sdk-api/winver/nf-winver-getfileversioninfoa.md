# GetFileVersionInfoA function

## Description

Retrieves version information for the specified file.

## Parameters

### `lptstrFilename` [in]

Type: **LPCTSTR**

The name of the file. If a full path is not specified, the function uses the search sequence specified by the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function.

### `dwHandle`

Type: **DWORD**

This parameter is ignored.

### `dwLen` [in]

Type: **DWORD**

The size, in bytes, of the buffer pointed to by the
*lpData* parameter.

Call the [GetFileVersionInfoSize](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizea) function first to determine the size, in bytes, of a file's version information. The
*dwLen* member should be equal to or greater than that value.

If the buffer pointed to by
*lpData* is not large enough, the function truncates the file's version information to the size of the buffer.

### `lpData` [out]

Type: **LPVOID**

Pointer to a buffer that receives the file-version information.

You can use this value in a subsequent call to the [VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea) function to retrieve data from the buffer.

## Return value

Type: **BOOL**

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

 File version info has fixed and non-fixed part. The fixed part contains information like version number. The non-fixed part contains things like strings. In the past **GetFileVersionInfo** was taking version information from the binary (exe/dll). Currently, it is querying fixed version from language neutral file (exe/dll) and the non-fixed part from mui file, merges them and returns to the user.
If the given binary does not have a mui file then behavior is as in previous version.

Call the [GetFileVersionInfoSize](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizea) function before calling the **GetFileVersionInfo** function. To retrieve information from the file-version information buffer, use the [VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea) function.

> [!NOTE]
> The winver.h header defines GetFileVersionInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetFileVersionInfoSize](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfosizea)

**Reference**

[VS_VERSIONINFO](https://learn.microsoft.com/windows/desktop/menurc/vs-versioninfo)

[VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea)

[Version Information](https://learn.microsoft.com/windows/desktop/menurc/version-information)