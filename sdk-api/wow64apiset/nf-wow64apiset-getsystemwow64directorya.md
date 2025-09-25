# GetSystemWow64DirectoryA function

## Description

Retrieves the path of the system directory used by WOW64. This directory is not present on 32-bit Windows.

## Parameters

### `lpBuffer` [out]

A pointer to the buffer to receive the path. This path does not end with a backslash.

### `uSize` [in]

The maximum size of the buffer, in **TCHARs**.

## Return value

If the function succeeds, the return value is the length, in **TCHARs**, of the string copied to the buffer, not including the terminating null character. If the length is greater than the size of the buffer, the return value is the size of the buffer required to hold the path.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

On 32-bit Windows, the function always fails, and the extended error is set to ERROR_CALL_NOT_IMPLEMENTED.

## Remarks

WOW64 uses the system directory to store shared 32-bit code on 64-bit Windows. Most applications have no need to access this directory explicitly.

For more information on WOW64, see
[Running 32-bit Applications](https://learn.microsoft.com/windows/desktop/WinProg64/running-32-bit-applications).

To compile an application that uses this function, define _WIN32_WINNT as 0x0501 or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The wow64apiset.h header defines GetSystemWow64Directory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[System
Information Functions](https://learn.microsoft.com/windows/desktop/SysInfo/system-information-functions)