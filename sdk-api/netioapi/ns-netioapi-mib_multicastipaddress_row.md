# MIB_MULTICASTIPADDRESS_ROW structure

## Description

The
**MIB_MULTICASTIPADDRESS_ROW** structure stores information about a multicast IP address.

## Members

### `Address`

The multicast IP address. This member can be an IPv6 address or an IPv4 address.

### `InterfaceIndex`

The local index value for the network interface associated with this IP address. This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `InterfaceLuid`

The locally unique identifier (LUID) for the network interface associated with this IP address.

### `ScopeId`

The scope ID of the multicast IP address. This member is applicable only to an IPv6 address. This member cannot be set. It is automatically determined by the interface on which the address was added.

## Remarks

The **MIB_MULTICASTIPADDRESS_ROW** structure is defined on Windows Vista and later.

The [GetMulticastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddresstable) function enumerates the multicast IP addresses on a local system and returns this information in a [MIB_MULTICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_table) structure. The [GetMulticastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddressentry) function retrieves a single multicast IP address and returns this information in a **MIB_MULTICASTIPADDRESS_ROW** structure.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetMulticastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddressentry)

[GetMulticastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddresstable)

[MIB_MULTICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_table)

[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)