## Description

Retrieves the user-defined IP layer MTU for a socket.

## Parameters

### `Socket` [in]

A descriptor that identifies a socket.

### `Mtu` [out]

Type: **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

A pointer to a **DWORD**. On success, the function sets the DWORD to the user-defined IP layer MTU set on the socket.

## Return value

On success, the function returns 0. Otherwise, a value of [SOCKET_ERROR](https://learn.microsoft.com/windows/win32/winsock/return-values-on-function-failure-2) is returned, and you can retrieve a specific error code by calling [WSAGetLastError](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

This functionality is supported through the [**IP_USER_MTU**](https://learn.microsoft.com/windows/win32/winsock/ipproto-ip-socket-options) socket option. **WSAGetIPUserMtu** is a type-safe wrapper for getting this socket option, and we recommend it over [getsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-getsockopt).

## See also