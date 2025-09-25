# SOCKADDR_IN6_PAIR structure

## Description

The **SOCKADDR_IN6_PAIR** structure contains pointers to a pair of IP addresses that represent a source and destination address pair.

## Members

### `SourceAddress`

A pointer to an IP source address represented as a [SOCKADDR_IN6](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. The address family is in host byte order and the IPv6 address, port, flow information, and zone ID are in network byte order.

### `DestinationAddress`

A pointer to an IP source address represented as a [SOCKADDR_IN6](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2) structure. The address family is in host byte order and the IPv6 address, port, flow information, and zone ID are in network byte order.

## Remarks

The **SOCKADDR_IN6_PAIR** structure is defined on Windows Vista and later.

Any IPv4 addresses in the **SOCKADDR_IN6_PAIR** structure must be represented in the IPv4-mapped IPv6 address format which enables an IPv6 only application to communicate with an IPv4 node. For more information on the IPv4-mapped IPv6 address format, see [Dual-Stack Sockets](https://learn.microsoft.com/windows/desktop/WinSock/dual-stack-sockets).

The **SOCKADDR_IN6_PAIR** structure is used by the [CreateSortedAddressPairs](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createsortedaddresspairs) function.

Note that the *Ws2ipdef.h* header file is automatically included in *Ws2tcpip.h* header file, and should never be used directly.

## See also

[CreateSortedAddressPairs](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createsortedaddresspairs)

[Dual-Stack Sockets](https://learn.microsoft.com/windows/desktop/WinSock/dual-stack-sockets)

[sockaddr](https://learn.microsoft.com/windows/desktop/WinSock/sockaddr-2)