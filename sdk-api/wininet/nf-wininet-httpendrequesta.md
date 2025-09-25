# HttpEndRequestA function

## Description

Ends an HTTP request that was initiated by
[HttpSendRequestEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa).

## Parameters

### `hRequest` [in]

Handle returned by
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) and sent by
[HttpSendRequestEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa).

### `lpBuffersOut` [out, optional]

This parameter is reserved and must be **NULL**.

### `dwFlags` [in]

This parameter is reserved and must be set to 0.

### `dwContext` [in, optional]

This parameter is reserved and must be set to 0.

## Return value

If the function succeeds, the function returns **TRUE**.

If the function fails, it returns **FALSE**. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If
*lpBuffersOut* is not set to **NULL**,
**HttpEndRequest** will return ERROR_INVALID_PARAMETER.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

> [!NOTE]
> The wininet.h header defines HttpEndRequest as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[HTTP Sessions](https://learn.microsoft.com/windows/desktop/WinInet/http-sessions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)