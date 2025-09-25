## Description

Sets the user-defined IP layer MTU on a socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a socket.

### `Mtu` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The user-defined IP layer MTU to be set on the socket.

## Return value

On success, the function returns 0. Otherwise, a value of [SOCKET_ERROR](https://learn.microsoft.com/windows/win32/winsock/return-values-on-function-failure-2) is returned, and you can retrieve a specific error code by calling [WSAGetLastError](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

This functionality is supported through the [**IP_USER_MTU**](https://learn.microsoft.com/windows/win32/winsock/ipproto-ip-socket-options) socket option. **WSASetIPUserMtu** is a type-safe wrapper for setting this socket option, and we recommend it over [setsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-setsockopt).

## See also