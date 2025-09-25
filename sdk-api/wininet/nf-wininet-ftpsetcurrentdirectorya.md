# FtpSetCurrentDirectoryA function

## Description

Changes to a different working directory on the FTP server.

## Parameters

### `hConnect` [in]

Handle to an FTP session.

### `lpszDirectory` [in]

Pointer to a null-terminated string that contains the name of the directory to become the current working directory. This can be either a fully qualified path or a name relative to the current directory.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the error message indicates that the FTP server denied the request to change a directory, use
[InternetGetLastResponseInfo](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetgetlastresponseinfoa) to determine why.

## Remarks

An application should use
[FtpGetCurrentDirectory](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpgetcurrentdirectorya) to determine the remote site's current working directory, instead of assuming that the remote system uses a hierarchical naming scheme for directories.

The
*lpszDirectory* parameter can be either partially or fully qualified file names relative to the current directory.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FtpSetCurrentDirectory as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/ftp-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)