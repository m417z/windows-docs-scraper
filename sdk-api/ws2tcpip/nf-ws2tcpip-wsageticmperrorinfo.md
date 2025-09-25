## Description

Retrieves information about an ICMP error received on a TCP socket during connection setup.

## Parameters

### `Socket` [in]

A descriptor that identifies a TCP socket.

### `Info` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to an [ICMP_ERROR_INFO](https://learn.microsoft.com/windows/win32/api/ws2ipdef/ns-ws2ipdef-icmp_error_info) structure. On success, the function initializes the structure.

## Return value

On success, the function returns 0. Otherwise, a value of [SOCKET_ERROR](https://learn.microsoft.com/windows/win32/winsock/return-values-on-function-failure-2) is returned, and you can retrieve a specific error code by calling [WSAGetLastError](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

If no ICMP error has been received since the last connect call, then [**WSANO_DATA**](https://learn.microsoft.com/windows/win32/winsock/windows-sockets-error-codes-2) is returned. This functionality is supported through the [**TCP_ICMP_ERROR_INFO**](https://learn.microsoft.com/windows/win32/winsock/ipproto-tcp-socket-options) socket option. **WSAGetIcmpErrorInfo** is a type-safe wrapper for getting this socket option, and we recommend it over [getsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-getsockopt).

## See also