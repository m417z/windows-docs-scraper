# InternetQueryDataAvailable function

## Description

Queries the server to determine the amount of data available.

## Parameters

### `hFile` [in]

Handle returned by
the [InternetOpenUrl](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetopenurla),
[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea),
[GopherOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopheropenfilea), or
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) function.

### `lpdwNumberOfBytesAvailable` [out]

Pointer to a variable that receives the number of available bytes. May be **NULL**.

### `dwFlags` [in]

This parameter is reserved and must be 0.

### `dwContext` [in]

This parameter is reserved and must be 0.

## Return value

Returns **TRUE** if the function succeeds, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). If the function finds no matching files,
**GetLastError** returns ERROR_NO_MORE_FILES.

## Remarks

This function returns the number of bytes of data that are available to be read immediately by a subsequent call to
[InternetReadFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetreadfile). If there is currently no data available and the end of the file has not been reached, the request waits until data becomes available. The amount of data remaining will not be recalculated until all available data indicated by the call to
**InternetQueryDataAvailable** is read.

For
[HINTERNET](https://learn.microsoft.com/windows/desktop/WinInet/appendix-a-hinternet-handles) handles created by
[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta) and sent by
[HttpSendRequestEx](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpsendrequestexa), a call to
[HttpEndRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpendrequesta) must be made on the handle before
**InternetQueryDataAvailable** can be used.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Common Functions](https://learn.microsoft.com/windows/desktop/WinInet/common-functions)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)