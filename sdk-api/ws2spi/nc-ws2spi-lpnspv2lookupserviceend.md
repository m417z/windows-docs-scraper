# LPNSPV2LOOKUPSERVICEEND callback function

## Description

The
**NSPv2LookupServiceEnd** function is called to free the handle after previous calls to
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) and
[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex).

## Parameters

### `hLookup` [in]

The handle obtained previously by a call to
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin).

## Return value

The function should return **NO_ERROR** (zero) if the routine succeeds. It should return **SOCKET_ERROR** (that is, 1) if the routine fails and it must set the appropriate error code using [WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror).

| Error code | Meaning |
| --- | --- |
| **[WSA_INVALID_HANDLE](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | The handle is not valid. |
| **[WSA_NOT_ENOUGH_MEMORY](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2)** | There is not enough memory available to perform this operation. |

## Remarks

The
**NSPv2LookupServiceEnd** function is used as part of the namespace service provider version-2 (NSPv2) architecture available on Windows Vista and later.

On Windows Vista and Windows Server 2008, the **NSPv2LookupServiceEnd** function can only be used for operations on NS_EMAIL namespace providers.

It is possible to receive an
[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin) function call on another thread while processing an
[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex). This indicates that the client has canceled the request and the provider should close the handle and return from the
**NSPv2LookupServiceNextEx** function call as well, setting the last error to **WSA_E_CANCELLED**.

In Windows Sockets 2, conflicting error codes are defined for **WSAECANCELLED** and [WSA_E_CANCELLED](https://learn.microsoft.com/windows/desktop/WinSock/windows-sockets-error-codes-2). The error code **WSAECANCELLED** will be removed in a future version and only WSA_E_CANCELLED will remain. Namespace Providers should use the WSA_E_CANCELLED error code to maintain compatibility with the widest possible range of applications.

## See also

[NSPV2_ROUTINE](https://learn.microsoft.com/windows/desktop/api/ws2spi/ns-ws2spi-nspv2_routine)

[NSPv2Cleanup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2cleanup)

[NSPv2ClientSessionRundown](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2clientsessionrundown)

[NSPv2LookupServiceBegin](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnsplookupservicebegin)

[NSPv2LookupServiceNextEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2lookupservicenextex)

[NSPv2SetServiceEx](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2setserviceex)

[NSPv2Startup](https://learn.microsoft.com/windows/desktop/api/ws2spi/nc-ws2spi-lpnspv2startup)

[WSAQUERYSET2](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-wsaqueryset2w)

[WSASetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsasetlasterror)