## Description

Specifies whether the IP stack should populate the control buffer with a message containing the explicit congestion notification (ECN) codepoint of the Type of Service IPv4 header field (or Traffic Class IPv6 header field) on a received datagram.

When you enable the receipt of ECN codepoints, the [LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg) function returns optional control data containing the ECN codepoint of the received datagram. The returned control message type will be **IP_ECN** (or **IPV6_ECN**) with level **IPPROTO_IP** (or **IPPROTO_IPV6**). The control message data is returned as an **INT**. This option is valid only on datagram sockets (the socket type must be **SOCK_DGRAM**).

For more info, and code examples, see [Winsock explicit congestion notification (ECN)](https://learn.microsoft.com/windows/win32/winsock/winsock-ecn). Also see [WSAGetRecvIPEcn](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-wsagetrecvipecn).

## Parameters

### `Socket`

Type: \_In\_ **SOCKET**

A descriptor that identifies the socket.

### `Enabled`

Type: \_In\_ **[DWORD](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** to enable the receipt of ECN codepoints; **FALSE** to disable.

## Return value

If the function succeeds, then the return value is 0. Otherwise, a value of **SOCKET_ERROR** is returned, and you can retreive a specific error code by calling
[WSAGetLastError](https://learn.microsoft.com/windows/desktop/api/winsock/nf-winsock-wsagetlasterror).

## Remarks

> [!IMPORTANT]
> This API is deprecated. **WSASetRecvIPEcn** does not properly support dual-stack sockets. Use the [**IP_ECN**](https://learn.microsoft.com/windows/win32/winsock/ipproto-ip-socket-options) and [**IPV6_ECN**](https://learn.microsoft.com/windows/win32/winsock/ipproto-ipv6-socket-options) socket options directly with [setsockopt](https://learn.microsoft.com/windows/win32/api/winsock/nf-winsock-setsockopt) instead.

On a dual-stack socket that is unbound or bound to a wildcard address, applications need to set both the **IP_ECN** (level **IPPROTO_IP**) and **IPV6_ECN** (level **IPPROTO_IPV6**) socket options separately. If the socket is bound to a specific IPv6 address, only the **IPV6_ECN** option should be set. If the socket is bound to an IPv4-mapped IPv6 address (for example, `::ffff:192.0.2.1`), only the **IP_ECN** option should be set.

## See also

* [Winsock explicit congestion notification (ECN)](https://learn.microsoft.com/windows/win32/winsock/winsock-ecn)
* [WSAGetRecvIPEcn](https://learn.microsoft.com/windows/win32/api/ws2tcpip/nf-ws2tcpip-wsagetrecvipecn)