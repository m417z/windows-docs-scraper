# GROUP_REQ structure

## Description

The **GROUP_REQ** structure provides multicast group information for IPv6 or IPv4 addresses.

## Members

### `gr_interface`

The interface index of the local interface on which the multicast group should be joined or dropped.

### `gr_group`

The address of the multicast group. This may be either an IPv6 or IPv4 multicast address.

## Remarks

The **GROUP_REQ** structure is used with either IPv6 or IPv4 multicast addresses. The **GROUP_REQ** structure is used with the [MCAST_JOIN_GROUP](https://learn.microsoft.com/windows/desktop/WinSock/socket-options) and MCAST_LEAVE_GROUP socket options.

The **GROUP_REQ** structure and related structures used for multicast programming are based on IETF recommendations in sections 5 and 8.2 of RFC 3768. For more information, see [http://www.ietf.org/rfc/rfc3678.txt](http://tools.ietf.org/html/rfc3678).

On Windows Vista and later, a set of socket options are available for multicast programming that support IPv6 and IPv4 addresses. These socket options are IP agnostic and can be used on both IPv6 and IPv4. These IP agnostic options use the **GROUP_REQ** and the [GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req) structures and are the preferred socket options for multicast programming on Windows Vista and later.

The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function can be used to obtain interface index information required for the *gr_interface* member.

The **GROUP_REQ** structure and the socket options that use this structure are only valid on datagram and raw sockets (the socket type must be **SOCK_DGRAM** or **SOCK_RAW**).

The **GROUP_REQ** structure is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

## See also

[GROUP_FILTER](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_filter)

[GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req)

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming)

[SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85))

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[ip_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq)

[ipv6_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ipv6_mreq)