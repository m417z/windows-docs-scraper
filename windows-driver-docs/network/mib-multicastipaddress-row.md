# MIB\_MULTICASTIPADDRESS\_ROW structure

The MIB\_MULTICASTIPADDRESS\_ROW structure stores information about a multicast IP address.

## Members

- **Address**
The multicast IP address. This member can be an IPv6 address or an IPv4 address.

- **InterfaceIndex**
The local index value for the network interface that is associated with this IP address. This index value might change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

- **InterfaceLuid**
The locally unique identifier (LUID) for the network interface that is associated with this IP address.

- **ScopeId**
The scope ID of the multicast IP address. This member is applicable only to an IPv6 address. Your driver cannot set this member. This member is automatically determined by the interface that the address was added on.

## Remarks

The [**GetMulticastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getmulticastipaddresstable) function enumerates the multicast IP addresses on a local computer and returns this information in a [**MIB\_MULTICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-table) structure. The **GetMulticastIpAddressEntry** function retrieves a single multicast IP address and returns this information in a MIB\_MULTICASTIPADDRESS\_ROW structure.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**FlushIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/flushippathtable)

[**GetIpPathEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathentry)

[**GetIpPathTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getippathtable)

[**GetMulticastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getmulticastipaddresstable)

[**MIB\_IPPATH\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ippath-row)

[**MIB\_MULTICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-multicastipaddress-table)