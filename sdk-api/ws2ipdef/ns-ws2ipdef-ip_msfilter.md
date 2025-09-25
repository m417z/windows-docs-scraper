# IP_MSFILTER structure

## Description

The **ip_msfilter** structure provides multicast filtering parameters for IPv4 addresses.

## Members

### `imsf_multiaddr`

The IPv4 address of the multicast group.

### `imsf_interface`

The local IPv4 address of the interface or the interface index on which the multicast group should be filtered. This value is in network byte order. If this member specifies an IPv4 address of 0.0.0.0, the default IPv4 multicast interface is used.

 To use an interface index of 1 would be the same as an IP address of 0.0.0.1.

### `imsf_fmode`

The multicast filter mode to be used. This parameter can be either MCAST_INCLUDE (value of 0) to include particular multicast sources, or MCAST_EXCLUDE (value of 1) to exclude traffic from specified sources.

On Windows Server 2003 and Windows XP, these values are defined in the *Ws2tcpip.h* header file.

On Windows Vista and later, these values are defined as enumeration values in the [MULTICAST_MODE_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ne-ws2ipdef-multicast_mode_type) enumeration defined in the *Ws2ipdef.h* header file.

### `imsf_numsrc`

The number of sources in the **imsf_slist** member.

### `imsf_slist`

An array of [in_addr](https://learn.microsoft.com/windows/desktop/api/winsock2/ns-winsock2-in_addr) structures that specify the IPv4 multicast source addresses to include or exclude.

## Remarks

The **ip_msfilter** structure is used with IPv4 addresses. The **ip_msfilter** structure is passed as an argument for the **SIO_GET_MULTICAST_FILTER** and **SIO_SET_MULTICAST_FILTER** IOCTLs.

The **ip_msfilter** structure and related structures used for IPv4 multicast programming are based on IETF recommendations in sections 4 and 8.1 of RFC 3768. For more information, see [http://www.ietf.org/rfc/rfc3678.txt](http://tools.ietf.org/html/rfc3678).

On Windows Vista and later, a set of socket options are available for multicast programming that support IPv6 and IPv4 addresses. These socket options are IP agnostic and can be used on both IPv6 and IPv4. These IP agnostic options use the [GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req) and the [GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req) structures and the **SIOCSMSFILTER** and **SIOCGMSFILTER** IOCTLs. These are the preferred socket options and IOCTLs for multicast programming on Windows Vista and later.

The **imsf_interface** member can be an interface index. Any IPv4 address in the 0.x.x.x block (first octet of 0) except for the IPv4 address of 0.0.0.0 is treated as an interface index.
An interface index is a 24-bit number. The 0.0.0.0/8 IPv4 address block is not used (this range is reserved). The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function can be used to obtain interface index information to use for the **imsf_interface** member.

It is recommended that a local IPv4 address or interface index always be specified in the **imsf_interface** member of the **ip_msfilter** structure, rather than use the default interface. This is particularly important on computers with multiple network interfaces and multiple public IPv4 addresses.

The default interface used for IPv4 multicast is determined by the networking stack in Windows. An application can determine the default interface used for IPv4 multicast using the [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) function to retrieve the IPv4 routing table. The network interface with the lowest value for the routing metric for a destination IP address of 224.0.0.0 is the default interface for IPv4 multicast. The routing table can also be displayed from the command prompt with the following command:

**route print**

The [IP_MULTICAST_IF](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options) socket option can be used to set the default interface to send IPv4 multicast packets. This socket option does not change the default interface used to receive IPv4 multicast packets.

A typical IPv4 multicast application would use the [IP_ADD_MEMBERSHIP](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options) socket option with the [ip_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq) structure or the **IP_ADD_SOURCE_MEMBERSHIP** socket option with the [ip_mreq_source](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq_source) structure to join a multicast group and listen for multicast packets on a specific interface. The **IP_MULTICAST_IF** socket option would be used to set the interface to send IPv4 multicast packets to the multicast group. The most common scenario would be a multicast application that listens and sends on the same interface for a multicast group. Multiple sockets might be used by a multicast application with one socket for listening and one or more sockets for sending.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **ip_msfilter** structure is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

**Note** The **IP_MSFILTER** and **PIP_MSFILTER** derived structures are only defined on the Windows SDK released with Windows Vista and later. The **ip_msfilter** structure should be used on earlier versions of the Windows SDK.

## See also

[Final-State-Based Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/final-state-based-multicast-programming)

[GROUP_FILTER](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_filter)

[GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req)

[GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req)

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable)

[IPPROTO_IP Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/ipproto-ip-socket-options)

[MULTICAST_MODE_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ne-ws2ipdef-multicast_mode_type)

[Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming)

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[ip_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq)

[ip_mreq_source](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq_source)