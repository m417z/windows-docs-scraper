# MIB_IPPATH_ROW structure

## Description

The
**MIB_IPPATH_ROW** structure stores information about an IP path entry.

## Members

### `Source`

Type: **[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)**

The source IP address for this IP path entry.

### `Destination`

Type: **[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)**

The destination IP address for this IP path entry.

### `InterfaceLuid`

Type: **NET_LUID**

The locally unique identifier (LUID) for the network interface associated with this IP path entry.

### `InterfaceIndex`

Type: **NET_IFINDEX**

The local index value for the network interface associated with this IP path entry. This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `CurrentNextHop`

Type: **[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)**

The current IP address of the next system or gateway en route. This member can change over the lifetime of a path.

### `PathMtu`

Type: **ULONG**

The maximum transmission unit (MTU) size, in bytes, to the destination IP address for this IP path entry.

### `RttMean`

Type: **ULONG**

The estimated mean round-trip time (RTT), in milliseconds, to the destination IP address for this IP path entry.

### `RttDeviation`

Type: **ULONG**

The estimated mean deviation for the round-trip time (RTT), in milliseconds, to the destination IP address for this IP path entry.

### `LastReachable`

Type: **ULONG**

The time, in
milliseconds, that a node assumes the destination IP address is
reachable after having received a reachability
confirmation.

### `LastUnreachable`

Type: **ULONG**

The time, in
milliseconds, that a node assumes the destination IP address is
unreachable after not having received a reachability
confirmation.

### `IsReachable`

Type: **BOOLEAN**

A value that indicates if the destination IP address is reachable for this IP path entry.

### `LinkTransmitSpeed`

Type: **ULONG64**

The estimated speed in bits per second of the transmit link to the destination IP address for this IP path entry.

### `LinkReceiveSpeed`

Type: **ULONG64**

The estimated speed in bits per second of the receive link from the destination IP address for this IP path entry.

## Remarks

The **MIB_IPPATH_ROW** structure is defined on Windows Vista and later.

The [GetIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathtable) function enumerates the IP path entries on a local system and returns this information in a [MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table) structure as an array of **MIB_IPPATH_ROW** entries.

The [GetIpPathEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathentry) function retrieves a single IP path entry and returns this information in a [MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table) structure.

## See also

[FlushIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-flushippathtable)

[GetIpPathEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathentry)

[GetIpPathTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getippathtable)

[MIB_IPPATH_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ippath_table)

[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)