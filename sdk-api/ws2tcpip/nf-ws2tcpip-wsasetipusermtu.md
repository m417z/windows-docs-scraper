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

> [!IMPORTANT]
> This API is deprecated. **WSASetIPUserMtu** does not properly support dual-stack sockets. Use the [**IP_USER_MTU**](https://learn.microsoft.com/windows/win32/winsock/ipproto-ip-socket-options) and [**IPV6_USER_MTU**](https://learn.microsoft.com/windows/win32/winsock/ipproto-ipv6-socket-options) socket options directly with [setsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-setsockopt) instead.

On a dual-stack socket that is unbound or bound to a wildcard address, applications need to set both the **IP_USER_MTU** (level **IPPROTO_IP**) and **IPV6_USER_MTU** (level **IPPROTO_IPV6**) socket options separately. If the socket is bound to a specific IPv6 address, only the **IPV6_USER_MTU** option should be set. If the socket is bound to an IPv4-mapped IPv6 address (for example, `::ffff:192.0.2.1`), only the **IP_USER_MTU** option should be set.

## See also