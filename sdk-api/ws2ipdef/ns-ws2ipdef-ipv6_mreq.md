# IPV6_MREQ structure

## Description

The **ipv6_mreq** structure provides multicast group information for IPv6 addresses.

## Members

### `ipv6mr_multiaddr`

The address of the IPv6 multicast group.

### `ipv6mr_interface`

The interface index of the local interface on which the multicast group should be joined or dropped. If this member specifies an interface index of 0, the default multicast interface is used.

## Remarks

The **ipv6_mreq** structure is used with IPv6 addresses. The **ipv6_mreq** structure is used with the [IPV6_ADD_MEMBERSHIP](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options), **IPV6_DROP_MEMBERSHIP**, **IPV6_JOIN_GROUP**, and **IPV6_LEAVE_GROUP** socket options. The **IPV6_JOIN_GROUP** and **IPV6_ADD_MEMBERSHIP** socket options are defined to be the same. The **IPV6_LEAVE_GROUP** and **IPV6_DROP_MEMBERSHIP** socket options are defined to be the same.

On Windows Vista and later, a set of socket options are available for multicast programming that support IPv6 and IPv4 addresses. These socket options are IP agnostic and can be used on both IPv6 and IPv4. These IP agnostic options use the [GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req) and the [GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req) structures and are the preferred socket options for multicast programming on Windows Vista and later.

The **ipv6_mreq** structure is the IPv6 equivalent of the IPv4-based [ip_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq) structure.

The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function can be used to obtain interface index information required for the *ipv6mr_interface* member.

The **ipv6_mreq** structure and the **IPPROTO_IPV6** level socket options that use this structure are only valid on datagram and raw sockets (the socket type must be **SOCK_DGRAM** or **SOCK_RAW**).

It is recommended that a local IPv6 interface index always be specified in the **ipv6mr_interface** member of the **ipv6_mreq** structure, rather than use the default interface. This is particularly important on computers with multiple network interfaces and multiple public IPv6 addresses.

The default interface used for IPv6 multicast is determined by the networking stack in Windows. On Windows Vista and later, an application can determine the default interface used for IPv6 multicast using the [GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2) function to retrieve the IPv6 routing table. The network interface with the lowest value for the routing metric for a destination IPv6 multicast address (the FF00::/8 IPv6 address block) is the default interface for IPv6 multicast. The routing table can also be displayed from the command prompt with the following command:

**route print**

The [IPV6_MULTICAST_IF](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options) socket option can be used to set the default interface to send IPv6 multicast packets. This socket option does not change the default interface used to receive IPv6 multicast packets.

A typical IPv6 multicast application would use the [IPV6_ADD_MEMBERSHIP](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options) or **IPV6_JOIN_GROUP** socket option with the **ipv6_mreq** structure to join a multicast group and listen for multicast packets on a specific interface. The **IPV6_MULTICAST_IF** socket option would be used to set the interface to send IPv6 multicast packets to the multicast group. The most common scenario would be a multicast application that listens and sends on the same interface for a multicast group. Multiple sockets might be used by a multicast application with one socket for listening and one or more sockets for sending.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **ipv6_mreq** structure is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

**Note** The **PIP6_MREQ** derived structure is only defined on the Windows SDK released with Windows Vista and later. The [GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req) and the [GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req) structures and are the preferred socket options for multicast programming on Windows Vista and later.

## See also

[GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req)

[GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req)

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[GetIpForwardTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipforwardtable2)

[IPPROTO_IPV6 Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ipv6-socket-options)

[Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming)

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[ip_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq)