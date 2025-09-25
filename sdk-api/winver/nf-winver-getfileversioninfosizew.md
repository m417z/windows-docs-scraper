# GetFileVersionInfoSizeW function

## Description

Determines whether the operating system can retrieve version information for a specified file. If version information is available, **GetFileVersionInfoSize** returns the size, in bytes, of that information.

## Parameters

### `lptstrFilename` [in]

Type: **LPCTSTR**

The name of the file of interest. The function uses the search sequence specified by the [LoadLibrary](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-loadlibrarya) function.

### `lpdwHandle` [out, optional]

Type: **LPDWORD**

A pointer to a variable that the function sets to zero.

## Return value

Type: **DWORD**

If the function succeeds, the return value is the size, in bytes, of the file's version information.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Call the
**GetFileVersionInfoSize** function before calling the [GetFileVersionInfo](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoa) function. The size returned by **GetFileVersionInfoSize** indicates the buffer size required for the version information returned by **GetFileVersionInfo**.

> [!NOTE]
> The winver.h header defines GetFileVersionInfoSize as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[GetFileVersionInfo](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-getfileversioninfoa)

**Reference**

[VS_VERSIONINFO](https://learn.microsoft.com/windows/desktop/menurc/vs-versioninfo)

[VerQueryValue](https://learn.microsoft.com/windows/desktop/api/winver/nf-winver-verqueryvaluea)

[Version Information](https://learn.microsoft.com/windows/desktop/menurc/version-information)