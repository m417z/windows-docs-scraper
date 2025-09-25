# GROUP_SOURCE_REQ structure

## Description

The **GROUP_SOURCE_REQ** structure provides multicast group information for IPv6 or IPv4 addresses that includes the source IP address.

## Members

### `gsr_interface`

The interface index of the local interface on which the multicast group should be joined, dropped, blocked, or unblocked.

### `gsr_group`

The address of the multicast group. This may be either an IPv6 or IPv4 multicast address.

### `gsr_source`

The source address that should be used. This may be either an IPv6 or IPv4 multicast address, but it must be the same address family (IPv6 or IPv4) as the address specified in the **gsr_group** member.

## Remarks

The **GROUP_SOURCE_REQ** structure is used with either IPv6 or IPv4 multicast addresses. The **GROUP_SOURCE_REQ** structure is used with the [MCAST_BLOCK_SOURCE](https://learn.microsoft.com/windows/desktop/WinSock/socket-options), MCAST_JOIN_SOURCE_GROUP, MCAST_LEAVE_SOURCE_GROUP, and MCAST_UNBLOCK_SOURCE socket options.

The **GROUP_SOURCE_REQ** structure and related structures used for multicast programming are based on IETF recommendations in sections 5 and 8.2 of RFC 3768. For more information, see [http://www.ietf.org/rfc/rfc3678.txt](http://tools.ietf.org/html/rfc3678).

On Windows Vista and later, a set of socket options are available for multicast programming that support IPv6 and IPv4 addresses. These socket options are IP agnostic and can be used on both IPv6 and IPv4. These IP agnostic options use the [GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req) and the **GROUP_SOURCE_REQ** structures and are the preferred socket options for multicast programming on Windows Vista and later.

The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function can be used to obtain interface index information required for the *gsr_interface* member.

The **GROUP_SOURCE_REQ** structure and the socket options that use this structure are only valid on datagram and raw sockets (the socket type must be **SOCK_DGRAM** or **SOCK_RAW**).

The **GROUP_SOURCE_REQ** structure is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

## See also

[GROUP_FILTER](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_filter)

[GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req)

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming)

[SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85))

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[ip_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq)

[ipv6_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ipv6_mreq)