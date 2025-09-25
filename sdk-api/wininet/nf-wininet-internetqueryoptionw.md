# InternetQueryOptionW function

## Description

Queries an Internet option on the specified handle.

## Parameters

### `hInternet` [in]

Handle on which to query information.

### `dwOption` [in]

Internet option to be queried. This can be one of the
[Option Flags](https://learn.microsoft.com/windows/desktop/WinInet/option-flags) values.

### `lpBuffer` [out]

Pointer to a buffer that receives the option setting. Strings returned by
**InternetQueryOption** are globally allocated, so the calling application must free them when it is finished using them.

### `lpdwBufferLength` [in, out]

Pointer to a variable that contains the size of
*lpBuffer*, in bytes. When
**InternetQueryOption** returns,
*lpdwBufferLength* specifies the size of the data placed into
*lpBuffer*. If
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) returns ERROR_INSUFFICIENT_BUFFER, this parameter points to the number of bytes required to hold the requested information.

## Return value

Returns **TRUE** if successful, or **FALSE** otherwise. To get a specific error message, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) will return the **ERROR_INVALID_PARAMETER** if an option flag that is invalid for the specified handle type is passed to the
*dwOption* parameter.

For more information, see
[Setting and Retrieving Internet Options](https://learn.microsoft.com/windows/desktop/WinInet/setting-and-retrieving-internet-options).

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines InternetQueryOption as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[FtpGetFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpgetfilea)

[FtpPutFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpputfilea)

[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta)

[InternetOpen](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopena)

[InternetSetOption](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetsetoptiona)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)