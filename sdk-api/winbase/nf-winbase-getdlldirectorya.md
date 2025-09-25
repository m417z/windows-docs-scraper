# GetDllDirectoryA function

## Description

Retrieves the application-specific portion of the search path used to locate DLLs for the
application.

## Parameters

### `nBufferLength` [in]

The size of the output buffer, in characters.

### `lpBuffer` [out]

A pointer to a buffer that receives the application-specific portion of the search path.

## Return value

If the function succeeds, the return value is the length of the string copied to
*lpBuffer*, in characters, not including the terminating null character. If the return
value is greater than *nBufferLength*, it specifies the size of the buffer required for
the path.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

To compile an application that uses this function, define **_WIN32_WINNT** as 0x0502
or later. For more information, see
[Using the Windows Headers](https://learn.microsoft.com/windows/desktop/WinProg/using-the-windows-headers).

> [!NOTE]
> The winbase.h header defines GetDllDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Dynamic-Link Library Search Order](https://learn.microsoft.com/windows/desktop/Dlls/dynamic-link-library-search-order)

[SetDllDirectory](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-setdlldirectorya)