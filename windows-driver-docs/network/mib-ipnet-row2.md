# MIB\_IPNET\_ROW2 structure

The MIB\_IPNET\_ROW2 structure stores information about a neighbor IP address.

## Members

- **Address**
The neighbor IP address. This member can be an IPv6 address or an IPv4 address.

- **InterfaceIndex**
The local index value for the network interface that is associated with this IP address. This index value might change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

- **InterfaceLuid**
The locally unique identifier (LUID) for the network interface that is associated with this IP address.

- **PhysicalAddress**
The physical hardware address of the adapter for the network interface that is associated with this IP address.

- **PhysicalAddressLength**
The length, in bytes, of the physical hardware address that the **PhysicalAddress** member specifies. The maximum value that is supported is 32 bytes.

- **State**
An [**NL\_NEIGHBOR\_STATE**](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_neighbor_state) network layer neighbor state type.

- **IsRouter**
A value that indicates if this IP address is a router.

- **IsUnreachable**
A value that indicates if this IP address is unreachable.

- **Flags**
A set of flags that indicate whether the IP address is a router and whether the IP address is unreachable.

- **ReachabilityTime**
The time that the node assumes that the neighbor is reachable or unreachable after the node receives information about the reachability of the neighbor.

 This union contains the following members:

    - **LastReachable**
The time, in milliseconds, that a node assumes that the neighbor will remain reachable after the node receives a reachability confirmation from the neighbor.

    - **LastUnreachable**
The time, in milliseconds, that a node assumes that the neighbor will remain unreachable after the node fails to receive a reachability confirmation from the neighbor.

## Remarks

The [**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2) function enumerates the neighbor IP addresses on a local computer and returns this information in an [**MIB\_IPNET\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-table2) structure. For IPv4, this information includes addresses determined by using the Address Resolution Protocol (ARP). For IPv6, this information includes addresses determined by using the Neighbor Discovery (ND) protocol for IPv6 as specified in RFC 2461. For more information, see [Neighbor Discovery for IP Version 6 (IPv6)](https://go.microsoft.com/fwlink/p/?linkid=84044).

The [**GetIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnetentry2) function retrieves a single neighbor IP address and returns this information in a MIB\_IPNET\_ROW2 structure.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**CreateIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/createipnetentry2)

[**GetIpNetEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnetentry2)

[**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2)

[**MIB\_IPNET\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-table2)

[**NL\_NEIGHBOR\_STATE**](https://learn.microsoft.com/windows/win32/api/nldef/ne-nldef-nl_neighbor_state)