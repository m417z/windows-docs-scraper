# GROUP_FILTER structure

## Description

The **GROUP_FILTER** structure provides multicast filtering parameters for multicast IPv6 or IPv4 addresses.

## Members

### `gf_interface`

The interface index of the local interface for the multicast group to filter.

### `gf_group`

The multicast address group that should be filtered. This may be either an IPv6 or IPv4 multicast address.

### `gf_fmode`

The multicast filter mode.

This member can be one of the values from the [MULTICAST_MODE_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ne-ws2ipdef-multicast_mode_type) enumeration type defined in the *Ws2ipdef.h* header file. This member determines if the list of IP addresses in the **gf_numsrc** member should be included or excluded.

| Value | Meaning |
| --- | --- |
| **MCAST_INCLUDE** | The filter contains a list of IP addresses to include. |
| **MCAST_EXCLUDE** | The filter contains a list of IP addresses to exclude. |

### `gf_numsrc`

The number of multicast filter source address entries in the **gf_slist** member.

### `gf_slist`

An array of [SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85)) structures specifying the multicast source addresses to include or exclude. These IP addresses may be either IPv6 or IPv4 addresses, but they must be the same address family (IPv6 or IPv4) as the address specified in the **gf_group** member..

## Remarks

The **GROUP_FILTER** structure is used with either IPv6 or IPv4 multicast addresses. The **GROUP_FILTER** structure is passed as an argument for the **SIOCGMSFILTER** and **SIOCSMSFILTER** IOCTLs.

The **GROUP_FILTER** structure and related structures used for multicast programming are based on IETF recommendations in sections 5 and 8.2 of RFC 3768. For more information, see [http://www.ietf.org/rfc/rfc3678.txt](http://tools.ietf.org/html/rfc3678).

On Windows Vista and later, a set of socket options are available for multicast programming that support IPv6 and IPv4 addresses. These socket options are IP agnostic and can be used on both IPv6 and IPv4. These IP agnostic options use the [GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req) and the [GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req) structures and are the preferred socket options for multicast programming on Windows Vista and later.

The [GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses) function can be used to obtain interface index information required for the *gf_interface* member.

The **GROUP_FILTER** structure and the Ioctls that use this structure are only valid on datagram and raw sockets (the socket type must be **SOCK_DGRAM** or **SOCK_RAW**).

The **GROUP_FILTER** structure is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

## See also

[GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req)

[GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req)

[GetAdaptersAddresses](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getadaptersaddresses)

[MULTICAST_MODE_TYPE](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ne-ws2ipdef-multicast_mode_type)

[Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming)

[SOCKADDR_STORAGE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms740504(v=vs.85))

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[ip_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq)

[ip_msfilter](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_msfilter)

[ipv6_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ipv6_mreq)