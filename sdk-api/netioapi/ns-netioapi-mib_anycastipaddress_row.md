# MIB_ANYCASTIPADDRESS_ROW structure

## Description

The
**MIB_ANYCASTIPADDRESS_ROW** structure stores information about an anycast IP address.

## Members

### `Address`

The anycast IP address. This member can be an IPv6 address or an IPv4 address.

### `InterfaceLuid`

The locally unique identifier (LUID) for the network interface associated with this IP address.

### `InterfaceIndex`

The local index value for the network interface associated with this IP address. This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `ScopeId`

The scope ID of the anycast IP address. This member is applicable only to an IPv6 address. This member cannot be set. It is automatically determined by the interface on which the address was added.

## Remarks

The **MIB_ANYCASTIPADDRESS_ROW** structure is defined on Windows Vista and later.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[CreateAnycastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createanycastipaddressentry)

[DeleteAnycastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteanycastipaddressentry)

[GetAnycastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddressentry)

[GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable)

[MIB_ANYCASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_table)

[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)