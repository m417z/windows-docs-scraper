## Description

The **MULTICAST_MODE_TYPE** enumeration specifies the filter mode for multicast group addresses.

## Constants

### `MCAST_INCLUDE:0`

The filter contains a list of IP addresses to include.

### `MCAST_EXCLUDE`

The filter contains a list of IP addresses to exclude.

## Remarks

This enumeration is supported on Windows Vista and later.

The **MULTICAST_MODE_TYPE** enumeration is used in the **gf_fmode** member of the [GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req) structure to determine if a list of IP addresses should included or excluded. The values from this enumeration can also be used in the **imsf_fmode** member of the [ip_msfilter](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_msfilter) structure.

The **MULTICAST_MODE_TYPE** enumeration is defined in the *Ws2ipdef.h* header file which is automatically included in the *Ws2tcpip.h* header file. The *Ws2ipdef.h* header files should never be used directly.

## See also

[GROUP_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_req)

[GROUP_SOURCE_REQ](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-group_source_req)

[Multicast Programming](https://learn.microsoft.com/windows/desktop/WinSock/multicast-programming)

[Socket Options](https://learn.microsoft.com/windows/desktop/WinSock/socket-options)

[ip_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_mreq)

[ip_msfilter](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ip_msfilter)

[ipv6_mreq](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-ipv6_mreq)