# MIB\_IPNET\_TABLE2 structure

The MIB\_IPNET\_TABLE2 structure contains a table of neighbor IP address entries.

## Members

- **NumEntries**
A value that specifies the number of IP network neighbor address entries in the array.

- **Table**
An array of [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) structures that contain IP network neighbor address entries.

## Remarks

The [**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2) function enumerates the neighbor IP addresses on a local computer and returns this information in an MIB\_IPNET\_TABLE2 structure. For IPv4, this information includes addresses determined by using the Address Resolution Protocol (ARP). For IPv6, this information includes addresses determined by using the Neighbor Discovery (ND) protocol for IPv6 as specified in RFC 2461. For more information, see [Neighbor Discovery for IP Version 6 (IPv6)](https://go.microsoft.com/fwlink/p/?linkid=84044).

The MIB\_IPNET\_TABLE2 structure might contain padding for alignment between the **NumEntries** member and the first [**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2) array entry in the **Table** member. Padding for alignment might also be present between the MIB\_IPNET\_ROW2 array entries in the **Table** member. Any access to a MIB\_IPNET\_ROW2 array entry should assume that padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetIpNetTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipnettable2)

[**MIB\_IPNET\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipnet-row2)