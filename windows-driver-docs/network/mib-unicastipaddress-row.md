# MIB\_UNICASTIPADDRESS\_ROW structure

The MIB\_UNICASTIPADDRESS\_ROW structure stores information about a unicast IP address.

## Members

- **Address**
The unicast IP address. This member can be an IPv6 address or an IPv4 address.

- **InterfaceLuid**
The locally unique identifier (LUID) for the network interface that is associated with this IP address.

- **InterfaceIndex**
The local index value for the network interface that is associated with this IP address. This index value might change when a network adapter is disabled and then enabled, or under other circumstances, and should not be considered persistent.

- **PrefixOrigin**
An [**NL\_PREFIX\_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/network/nl-prefix-origin) type that specifies the origin of the prefix or network part of the IP address.

- **SuffixOrigin**
An [**NL\_SUFFIX\_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/network/nl-suffix-origin) type that specifies the origin of the suffix or host part of the IP address.

- **ValidLifetime**
The maximum time, in seconds, that the IP address is valid. A value of 0xffffffff is considered to be infinite.

- **PreferredLifetime**
The preferred time, in seconds, that the IP address is valid. A value of 0xffffffff is considered to be infinite.

- **OnLinkPrefixLength**
The length, in bits, of the prefix or network part of the IP address. For a unicast IPv4 address, any value that is greater than 32 is an illegal value. For a unicast IPv6 address, any value that is greater than 128 is an illegal value. A value of 255 is typically used to represent an illegal value.

- **SkipAsSource**
A value that specifies if the address can be used as an IP source address.

- **DadState**
A [**NL\_DAD\_STATE**](https://learn.microsoft.com/windows-hardware/drivers/network/nl-dad-state) duplicate address detection (DAD) type.

- **ScopeId**
The scope ID of the IP address. This member is applicable only to an IPv6 address. Your driver cannot set this member. This member is automatically determined by the interface that the address was added on.

- **CreationTimeStamp**
The time stamp when the IP address was created.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**CreateUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/createunicastipaddressentry)

[**DeleteUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteunicastipaddressentry)

[**GetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddressentry)

[**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable)

[**InitializeUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/initializeunicastipaddressentry)

[**MIB\_UNICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-table)

[**NL\_DAD\_STATE**](https://learn.microsoft.com/windows-hardware/drivers/network/nl-dad-state)

[**NL\_PREFIX\_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/network/nl-prefix-origin)

[**NL\_SUFFIX\_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/network/nl-suffix-origin)

[**SetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setunicastipaddressentry)