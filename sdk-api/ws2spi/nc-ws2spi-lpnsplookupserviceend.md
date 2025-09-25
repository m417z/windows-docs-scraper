# LPNSPLOOKUPSERVICEEND callback function

## Description

The
**NSPLookupServiceEnd** function is called to free the handle after previous calls to
[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) and
[NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext).

It is possible to receive an
**NSPLookupServiceEnd** call on another thread while processing an
[NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext). This indicates that the client has canceled the request and the provider should close the handle and return from the
**NSPLookupServiceNext** call as well, setting the last error to **WSA_E_CANCELLED**.

## Parameters

### `hLookup` [in]

The handle obtained previously by a call to
[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin).

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (–1) if the routine fails and it must set the appropriate error code using [WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The handle is not valid. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |
| **[WSAEOPNOTSUPP](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2#WSAEOPNOTSUPP)** | The operation is not supported. This error is returned if the namespace provider does not implement this function. |

## Remarks

In Windows Sockets 2, conflicting error codes are defined for **WSAECANCELLED** and [WSA_E_CANCELLED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). The error code **WSAECANCELLED** will be removed in a future version and only WSA_E_CANCELLED will remain. Namespace Providers should use the WSA_E_CANCELLED error code to maintain compatibility with the widest possible range of applications.

## See also

[NSPLookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPLookupServiceNext](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicenext)

[NSP_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nsp_routine)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)