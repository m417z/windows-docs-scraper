# FtpCommandW function

## Description

The **FtpCommand** function sends commands directly to an FTP server.

## Parameters

### `hConnect` [in]

A handle returned from a call to
[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta).

### `fExpectResponse` [in]

A Boolean value that indicates whether the application expects a data connection to be established by the FTP server. This must be set to **TRUE** if a data connection is expected, or **FALSE** otherwise.

### `dwFlags` [in]

A parameter that can be set to one of the following values.

| Value | Meaning |
| --- | --- |
| **FTP_TRANSFER_TYPE_ASCII** | Transfers the file using the FTP ASCII (Type A) transfer method. Control and formatting data is converted to local equivalents. |
| **FTP_TRANSFER_TYPE_BINARY** | Transfers the file using the FTP Image (Type I) transfer method. The file is transferred exactly with no changes. This is the default transfer method. |

### `lpszCommand` [in]

A pointer to a string that contains the command to send to the FTP server.

### `dwContext` [in]

A pointer to a variable that contains an application-defined value used to identify the application context in callback operations.

### `phFtpCommand` [out]

A pointer to a handle that is created if a valid data socket is opened. The
*fExpectResponse* parameter must be set to **TRUE** for
*phFtpCommand* to be filled.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can return
[ERROR_INTERNET_NO_DIRECT_ACCESS](https://learn.microsoft.com/windows/desktop/WinInet/wininet-errors) if the client application is offline. If one or more of the parameters are invalid,
**GetLastError** will return **ERROR_INVALID_PARAMETER**.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines FtpCommand as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[FTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/ftp-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)