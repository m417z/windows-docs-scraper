## Description

Queries the current enablement of receiving the **IP_ECN** (or **IPV6_ECN**) control message via [LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg). See [WSASetRecvIPEcn](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-wsasetrecvipecn) for more info.

For more info, and code examples, see [Winsock explicit congestion notification (ECN)](https://learn.microsoft.com/windows/win32/winsock/winsock-ecn).

## Parameters

### `Socket`

Type: \_In\_ **SOCKET**

A descriptor that identifies the socket.

### `Enabled`

Type: \_Out\_ **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)\***

**TRUE** if the receipt of ECN codepoints is enabled; otherwise, **FALSE**.

## Return value

If the function succeeds, then the return value is 0. Otherwise, a value of **SOCKET_ERROR** is returned, and you can retreive a specific error code by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

> [!IMPORTANT]
> This API is deprecated. **WSAGetRecvIPEcn** does not properly support dual-stack sockets. Use the [**IP_ECN**](https://learn.microsoft.com/windows/win32/winsock/ipproto-ip-socket-options) and [**IPV6_ECN**](https://learn.microsoft.com/windows/win32/winsock/ipproto-ipv6-socket-options) socket options directly with [getsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-getsockopt) instead.

On a dual-stack socket that is unbound or bound to a wildcard address, applications need to get both the **IP_ECN** (level **IPPROTO_IP**) and **IPV6_ECN** (level **IPPROTO_IPV6**) socket options separately. If the socket is bound to a specific IPv6 address, only the **IPV6_ECN** option should be get. If the socket is bound to an IPv4-mapped IPv6 address (for example, `::ffff:192.0.2.1`), only the **IP_ECN** option should be get.

## See also

* [Winsock explicit congestion notification (ECN)](https://learn.microsoft.com/windows/win32/winsock/winsock-ecn)
* [WSASetRecvIPEcn](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-wsasetrecvipecn)