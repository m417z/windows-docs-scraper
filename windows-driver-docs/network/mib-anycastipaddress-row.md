# MIB\_ANYCASTIPADDRESS\_ROW structure

The MIB\_ANYCASTIPADDRESS\_ROW structure stores information about an anycast IP address.

## Members

- **Address**
The anycast IP address. This member can be an IPv6 address or an IPv4 address.

- **InterfaceLuid**
The locally unique identifier (LUID) for the network interface that is associated with this IP address.

- **InterfaceIndex**
The local index value for the network interface that is associated with this IP address. This index value might change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

- **ScopeId**
The scope ID of the anycast IP address. This member is applicable only to an IPv6 address. Your driver cannot set this member. This member is automatically determined by the interface that the address was added on.

## Remarks

The [**GetAnycastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getanycastipaddresstable) function enumerates the anycast IP addresses on a local computer and returns this information in a [**MIB\_ANYCASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-table) structure.

The MIB\_ANYCASTIPADDRESS\_TABLE structure might contain padding for alignment between the **NumEntries** member and the first MIB\_ANYCASTIPADDRESS\_ROW array entry in the **Table** member. Padding for alignment might also be present between the MIB\_ANYCASTIPADDRESS\_ROW array entries in the **Table** member. Any access to a MIB\_ANYCASTIPADDRESS\_ROW array entry should assume padding might exist.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**CreateAnycastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/createanycastipaddressentry)

[**DeleteAnycastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteanycastipaddressentry)

[**GetAnycastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getanycastipaddresstable)

[**GetAnycastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getanycastipaddressentry)

[**MIB\_ANYCASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-anycastipaddress-table)