# MIB\_IPPATH\_ROW structure

The MIB\_IPPATH\_ROW structure stores information about an IP path entry.

## Members

- **Source**
The source IP address for this IP path entry.

- **Destination**
The destination IP address for this IP path entry.

- **InterfaceLuid**
The locally unique identifier (LUID) for the network interface that is associated with this IP path entry.

- **InterfaceIndex**
The local index value for the network interface that is associated with this IP path entry. This index value might change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

- **CurrentNextHop**
The current IP address of the next system or gateway that is along the route. This member can change over the lifetime of a path.

- **PathMtu**
The maximum transmission unit (MTU) size, in bytes, to the destination IP address for this IP path entry.

- **RttMean**
The estimated mean round-trip time (RTT), in milliseconds, to the destination IP address for this IP path entry.

- **RttDeviation**
The estimated mean deviation for the round-trip time (RTT), in milliseconds, to the destination IP address for this IP path entry.

- **LastReachable**
The time, in milliseconds, that a node assumes that the destination IP address is reachable after having received a reachability confirmation.

- **LastUnreachable**
The time, in milliseconds, that a node assumes that the destination IP address is unreachable after not having received a reachability confirmation.

- **IsReachable**
A value that indicates if the destination IP address is reachable for this IP path entry.

- **LinkTransmitSpeed**
The estimated speed, in bits per second, of the transmit link to the destination IP address for this IP path entry.

- **LinkReceiveSpeed**
The estimated speed, in bits per second, of the receive link from the destination IP address for this IP path entry.

## Remarks

The [**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable) function enumerates the IP path entries on a local computer and returns this information in a [**MIB\_IPPATH\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-table) structure as an array of MIB\_IPPATH\_ROW entries.

The [**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable) function retrieves a single IP path entry and returns this information in a [**MIB\_IPPATH\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-table) structure.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**FlushIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/flushippathtable)

[**GetIpPathEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathentry)

[**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable)

[**MIB\_IPPATH\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-table)