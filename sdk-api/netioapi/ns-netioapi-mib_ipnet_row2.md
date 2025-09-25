# MIB_IPNET_ROW2 structure

## Description

The
**MIB_IPNET_ROW2** structure stores information about a neighbor IP address.

## Members

### `Address`

Type: **[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)**

The neighbor IP address. This member can be an IPv6 address or an IPv4 address.

### `InterfaceIndex`

Type: **NET_IFINDEX**

The local index value for the network interface associated with this IP address. This index value may change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

### `InterfaceLuid`

Type: **NET_LUID**

The locally unique identifier (LUID) for the network interface associated with this IP address.

### `PhysicalAddress`

Type:  **UCHAR[IF_MAX_PHYS_ADDRESS_LENGTH]**

The physical hardware address of the adapter for the network interface associated with this IP address.

### `PhysicalAddressLength`

Type: **ULONG**

The length, in bytes, of the physical hardware address specified by the **PhysicalAddress** member. The maximum value supported is 32 bytes.

### `State`

Type: **NL_NEIGHBOR_STATE**

The state of a network neighbor IP address as defined in RFC 2461, section 7.3.2. For more information, see [http://www.ietf.org/rfc/rfc2461.txt](https://www.ietf.org/rfc/rfc2461.txt). This member can be one of the values from the **NL_NEIGHBOR_STATE** enumeration type defined in the *Nldef.h* header file.

| Value | Meaning |
| --- | --- |
| **NlnsUnreachable** | The IP address is unreachable. |
| **NlnsIncomplete** | Address resolution is in progress and the link-layer address of the neighbor has not yet been determined. Specifically for IPv6, a Neighbor Solicitation has been sent to the solicited-node multicast IP address of the target, but the corresponding neighbor advertisement has not yet been received. |
| **NlnsProbe** | The neighbor is no longer known to be reachable, and probes are being sent to verify reachability. For IPv6, a reachability confirmation is actively being sought by retransmitting unicast Neighbor Solicitation probes at regular intervals until a reachability confirmation is received. |
| **NlnsDelay** | The neighbor is no longer known to be reachable, and traffic has recently been sent to the neighbor. Rather than probe the neighbor immediately, however, delay sending probes for a short while in order to give upper layer protocols a chance to provide reachability confirmation. For IPv6, more time has elapsed than is specified in the **ReachabilityTime.ReachableTime** member since the last positive confirmation was received that the forward path was functioning properly and a packet was sent. If no reachability confirmation is received within a period of time (used to delay the first probe) of entering the **NlnsDelay** state, then a neighbor solicitation is sent and the **State** member is changed to **NlnsProbe**. |
| **NlnsStale** | The neighbor is no longer known to be reachable but until traffic is sent to the neighbor, no attempt should be made to verify its reachability. For IPv6, more time has elapsed than is specified in the **ReachabilityTime.ReachableTime** member since the last positive confirmation was received that the forward path was functioning properly. While the **State** is **NlnsStale**, no action takes place until a packet is sent.<br><br>The **NlnsStale** state is entered upon receiving an unsolicited neighbor discovery message that updates the cached IP address. Receipt of such a message does not confirm reachability, and entering the **NlnsStale** state insures reachability is verified quickly if the entry is actually being used. However, reachability is not actually verified until the entry is actually used. |
| **NlnsReachable** | The neighbor is known to have been reachable recently (within tens of seconds ago). For IPv6, a positive confirmation was received within the time specified in the **ReachabilityTime.ReachableTime** member that the forward path to the neighbor was functioning properly. While the **State** is **NlnsReachable**, no special action takes place as packets are sent. |
| **NlnsPermanent** | The IP address is a permanent address. |
| **NlnsMaximum** | The maximum possible value for the **NL_NEIGHBOR_STATE** enumeration type. This is not a legal value for the **State** member. |

### `IsRouter`

Type: **BOOLEAN**

A value that indicates if this IP address is a router.

### `IsUnreachable`

Type: **BOOLEAN**

A value that indicates if this IP address is unreachable.

### `Flags`

Type: **UCHAR**

A set of flags that indicate whether the IP address is a router and whether the IP address is unreachable.

### `ReachabilityTime`

### `ReachabilityTime.LastReachable`

**Type: **ULONG****
The time, in
milliseconds, that a node assumes a neighbor is
reachable after having received a reachability
confirmation.

### `ReachabilityTime.LastUnreachable`

**Type: **ULONG****
The time, in
milliseconds, that a node assumes a neighbor is
unreachable after not having received a reachability
confirmation.

## Remarks

The **MIB_IPNET_ROW2** structure is defined on Windows Vista and later.

The **GetIpNetTable2** function enumerates the neighbor IP addresses on a local system and returns this information in an [MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2) structure.

For IPv4, this includes addresses determined used the Address Resolution Protocol (ARP). For IPv6, this includes addresses determined using the Neighbor Discovery (ND) protocol for IPv6 as specified in RFC 2461. For more information, see [http://www.ietf.org/rfc/rfc2461.txt](https://www.ietf.org/rfc/rfc2461.txt).

The [GetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetentry2) function retrieves a single neighbor IP address and returns this information in a **MIB_IPNET_ROW2** structure.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[CreateIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createipnetentry2)

[GetIpNetEntry2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnetentry2)

[GetIpNetTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipnettable2)

[MIB_IPNET_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipnet_table2)

[SOCKADDR_INET](https://learn.microsoft.com/windows/desktop/api/ws2ipdef/ns-ws2ipdef-sockaddr_inet)