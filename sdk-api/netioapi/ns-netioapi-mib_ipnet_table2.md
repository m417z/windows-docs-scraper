# MIB_IPNET_TABLE2 structure

## Description

The
**MIB_IPNET_TABLE2** structure contains a table of neighbor IP address entries.

## Members

### `NumEntries`

A value that specifies the number of IP network neighbor address entries in the array.

### `Table`

An array of
[MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) structures containing IP network neighbor address entries.

## Remarks

The **MIB_IPNET_TABLE2** structure is defined on Windows Vista and later.

The [GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2) function enumerates the neighbor IP addresses on a local system and returns this information in an **MIB_IPNET_TABLE2** structure.

For IPv4, this includes addresses determined used the Address Resolution Protocol (ARP). For IPv6, this includes addresses determined using the Neighbor Discovery (ND) protocol for IPv6 as specified in RFC 2461. For more information, see [http://www.ietf.org/rfc/rfc2461.txt](https://www.ietf.org/rfc/rfc2461.txt).

The **MIB_IPNET_TABLE2** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_IPNET_ROW2** array entries in the **Table** member. Any access to a **MIB_IPNET_ROW2** array entry should assume padding may exist.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2)

[MIB_IPNET_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_row2)