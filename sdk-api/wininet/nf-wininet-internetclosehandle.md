# InternetCloseHandle function

## Description

Closes a single Internet handle.

## Parameters

### `hInternet` [in]

Handle to be closed.

## Return value

Returns **TRUE** if the handle is successfully closed, or **FALSE** otherwise. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The function terminates any pending operations on the handle and discards any outstanding data.

It is safe to call **InternetCloseHandle** as long as no API calls are being made or will be made using the handle. Once an API has returned **ERROR_IO_PENDING**, it is safe to call **InternetCloseHandle** to cancel that I/O, as long as no subsequent API calls will be issued with the handle.

It is safe to call **InternetCloseHandle** in a callback for the handle being closed. If there is a status callback registered for the handle being closed, and the handle was created with a non-NULL context value, an **INTERNET_STATUS_HANDLE_CLOSING** callback will be made. This indication will be the last callback made from a handle and indicates that the handle is being destroyed.

If asynchronous requests are pending for the handle or any of its child handles, the handle cannot be closed immediately, but it will be invalidated. Any new requests attempted using the handle will return with an
[ERROR_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinInet/wininet-errors) notification. The asynchronous requests will complete with **INTERNET_STATUS_REQUEST_COMPLETE**. Applications must be prepared to receive any **INTERNET_STATUS_REQUEST_COMPLETE** indications on the handle before the final **INTERNET_STATUS_HANDLE_CLOSING** indication is made, which indicates that the handle is completely closed.

An application can call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to determine if requests are pending. If
**GetLastError** returns **ERROR_IO_PENDING**, there were outstanding requests when the handle was closed.

Like all other aspects of the WinINet API, this function cannot be safely called from within DllMain or the constructors and destructors of global objects.

**Note** WinINet does not support server implementations. In addition, it should not be used from a service. For server implementations or services use [Microsoft Windows HTTP Services (WinHTTP)](https://learn.microsoft.com/windows/desktop/WinHttp/winhttp-start-page).

## See also

[Enabling Internet Functionality](https://learn.microsoft.com/windows/desktop/WinInet/enabling-internet-functionality)

[FtpFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpfindfirstfilea)

[FtpOpenFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-ftpopenfilea)

[GopherFindFirstFile](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-gopherfindfirstfilea)

[HttpOpenRequest](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-httpopenrequesta)

[InternetConnect](https://learn.microsoft.com/windows/desktop/api/wininet/nf-wininet-internetconnecta)

[WinINet Functions](https://learn.microsoft.com/windows/desktop/WinInet/wininet-functions)