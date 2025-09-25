## Description

Sets the state of the [**TCP_FAIL_CONNECT_ON_ICMP_ERROR**](https://learn.microsoft.com/windows/win32/winsock/ipproto-tcp-socket-options) socket option.

## Parameters

### `Socket` [in]

A descriptor that identifies a TCP socket.

### `Enabled` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

A non-zero value if [**TCP_FAIL_CONNECT_ON_ICMP_ERROR**](https://learn.microsoft.com/windows/win32/winsock/ipproto-tcp-socket-options) should be enabled, otherwise zero.

## Return value

On success, the function returns 0. Otherwise, a value of [SOCKET_ERROR](https://learn.microsoft.com/windows/win32/winsock/return-values-on-function-failure-2) is returned, and you can retrieve a specific error code by calling [WSAGetLastError](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

This functionality is supported through the [**TCP_FAIL_CONNECT_ON_ICMP_ERROR**](https://learn.microsoft.com/windows/win32/winsock/ipproto-tcp-socket-options) socket option. **WSASetFailConnectOnIcmpError** is a type-safe wrapper for setting this socket option, and we recommend it over [setsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-setsockopt).

## See also