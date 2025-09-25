# IP_MREQ structure

## Description

The **ip_mreq** structure provides multicast group information for IPv4 addresses.

## Members

### `imr_multiaddr`

The address of the IPv4 multicast group.

### `imr_interface`

The local IPv4 address of the interface or the interface index on which the multicast group should be joined or dropped. This value is in network byte order. If this member specifies an IPv4 address of 0.0.0.0, the default IPv4 multicast interface is used.

 To use an interface index of 1 would be the same as an IP address of 0.0.0.1.

## Remarks

The **ip_mreq** structure is used with IPv4 addresses. The **ip_mreq** structure is used with the [IP_ADD_MEMBERSHIP](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options) and **IP_DROP_MEMBERSHIP** socket options.

The **ip_mreq** structure and related structures used for IPv4 multicast programming are based on IETF recommendations in sections 4 and 8.1 of RFC 3768. For more information, see [http://www.ietf.org/rfc/rfc3678.txt](http://tools.ietf.org/html/rfc3678).

For more configurable multicast capabilities with IPv4, use the [ip_mreq_source](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq_source) structure. See [Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming) for more information.

On Windows Vista and later, a set of socket options are available for multicast programming that support IPv6 and IPv4 addresses. These socket options are IP agnostic and can be used on both IPv6 and IPv4. These IP agnostic options use the [GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req) and the [GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req) structures and are the preferred socket options for multicast programming on Windows Vista and later.

The **ip_mreq** structure is the IPv4 equivalent of the IPv6-based [ipv6_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ipv6_mreq) structure.

The **imr_interface** member can be an interface index. Any IP address in the 0.x.x.x block (first octet of 0) except for the IP address of 0.0.0.0 is treated as an interface index.
An interface index is a 24-bit number. The 0.0.0.0/8 IPv4 address block is not used (this range is reserved). The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function can be used to obtain interface index information to use for the **imr_interface** member.

It is recommended that a local IPv4 address or interface index always be specified in the **imr_interface** member of the **ip_mreq** structure, rather than use the default interface. This is particularly important on computers with multiple network interfaces and multiple public IPv4 addresses.

The default interface used for IPv4 multicast is determined by the networking stack in Windows. An application can determine the default interface used for IPv4 multicast using the [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) function to retrieve the IPv4 routing table. The network interface with the lowest value for the routing metric for a destination IP address of 224.0.0.0 is the default interface for IPv4 multicast. The routing table can also be displayed from the command prompt with the following command:

**route print**

The [IP_MULTICAST_IF](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options) socket option can be used to set the default interface to send IPv4 multicast packets. This socket option does not change the default interface used to receive IPv4 multicast packets.

A typical IPv4 multicast application would use the [IP_ADD_MEMBERSHIP](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options) socket option with the **ip_mreq** structure to join a multicast group and listen for multicast packets on a specific interface. The **IP_MULTICAST_IF** socket option would be used to set the interface to send IPv4 multicast packets to the multicast group. The most common scenario would be a multicast application that listens and sends on the same interface for a multicast group. Multiple sockets might be used by a multicast application with one socket for listening and one or more sockets for sending.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **ip_mreq** structure is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

**Note** The **IP_MREQ** and **PIP_MREQ** derived structures are only defined on the Windows SDK released with Windows Vista and later. The **ip_mreq** structure should be used on earlier versions of the Windows SDK.

## See also

[GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req)

[GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req)

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable)

[IPPROTO_IP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options)

[Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming)

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[ip_mreq_source](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq_source)

[ip_msfilter](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_msfilter)

[ipv6_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ipv6_mreq)