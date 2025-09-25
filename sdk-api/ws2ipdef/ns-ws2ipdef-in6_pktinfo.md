# IN6_PKTINFO structure

## Description

The
**in6_pktinfo** structure is used to store received IPv6 packet address information, and is used by Windows to return information about received packets and also allows specifying the local IPv6 address to use for sending packets.

## Members

### `ipi6_addr`

The destination IPv6 address from the IP header of the received packet when used with the [LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg) function. The local source IPv6 address to set in the IP header when used with the [WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg) function.

### `ipi6_ifindex`

The interface on which the packet was received when used with the [LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg) function. The interface on which the packet should be sent when used with the [WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg) function.

## Remarks

If the [IPV6_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-pktinfo) socket option is set on a socket of type **SOCK_DGRAM** or **SOCK_RAW**, one of the control data objects returned by the [LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg) function will contain an
**in6_pktinfo** structure used to store received packet address information.

On an IPv6 socket of type **SOCK_DGRAM** or **SOCK_RAW**, an application can specific the local IP source address to use for sending with the [WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg) function. One of the control data objects passed in the [WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg) structure to the **WSASendMsg** function may contain an
**in6_pktinfo** structure used to specify the local IPv6 address to use for sending.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **in6_pktinfo** structure is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

## See also

[Dual-Stack Sockets for IPv6 Winsock Applications](https://learn.microsoft.com/windows/desktop/WinSock/dual-stack-sockets)

[IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options)

[IPV6_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ipv6-pktinfo)

[IP_PKTINFO](https://learn.microsoft.com/windows/desktop/WinSock/ip-pktinfo)

[WSAMSG](https://learn.microsoft.com/windows/desktop/api/ws2def/ns-ws2def-wsamsg)

[LPFN_WSARECVMSG (WSARecvMsg)](https://learn.microsoft.com/windows/win32/api/mswsock/nc-mswsock-lpfn_wsarecvmsg)

[WSASendMsg](https://learn.microsoft.com/windows/desktop/api/winsock2/nf-winsock2-wsasendmsg)

[in_pktinfo](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-in_pktinfo)