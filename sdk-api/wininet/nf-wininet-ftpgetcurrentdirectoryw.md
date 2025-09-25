# FtpGetCurrentDirectoryW function

## Description

Retrieves the current directory for the specified FTP session.

## Parameters

### `hConnect` [in]

Handle to an FTP session.

### `lpszCurrentDirectory` [out]

Pointer to a null-terminated string that receives the absolute path of the current directory.

### `lpdwCurrentDirectory` [in, out]

Pointer to a variable that specifies the length of the buffer, in **TCHARs**. The buffer length must include room for a terminating null character. Using a length of **MAX_PATH** is sufficient for all paths. When the function returns, the variable receives the number of characters copied into the buffer.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the
*lpszCurrentDirectory* buffer is not large enough,
*lpdwCurrentDirectory* receives the number of bytes required to retrieve the full, current directory name.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FtpGetCurrentDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/ftp-sessions)

[FtpSetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpsetcurrentdirectorya)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)