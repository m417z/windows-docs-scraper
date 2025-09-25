# InitializeUnicastIpAddressEntry function

## Description

The
**InitializeUnicastIpAddressEntry** function initializes a **MIB_UNICASTIPADDRESS_ROW** structure with default values for a unicast IP address entry on the local computer.

## Parameters

### `Row` [out]

On entry, a pointer to a
[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure entry for a unicast IP address entry. On return, the **MIB_UNICASTIPADDRESS_ROW** structure pointed to by this parameter is initialized with default values for a unicast IP address.

## Return value

This function does not return a value.

## Remarks

The **InitializeUnicastIpAddressEntry** function is defined on Windows Vista and later.

The **InitializeUnicastIpAddressEntry** function must be used to initialize the members of a
[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure entry with default values for a unicast IP address for later use with the [CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) function.

On input, **InitializeUnicastIpAddressEntry** must be passed a new [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure to initialize.

On output, the **PrefixOrigin** member of the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) structure pointed to by *Row* parameter the will be initialized to **IpPrefixOriginUnchanged**, the **SuffixOrigin** member will be initialized to **IpSuffixOriginUnchanged**, and the **OnLinkPrefixLength** member will be initialized to an illegal value. In addition, the **PreferredLifetime** and **ValidLifetime** members are set to infinite, the **SkipAsSource** member is set to **FALSE**, and other fields are initialized to zero.

After calling **InitializeUnicastIpAddressEntry**, an application can then change the
members in the [MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row) entry it wishes to modify, and then call the [CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry) to add the new unicast IP address to the local computer.

## See also

[CreateUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-createunicastipaddressentry)

[DeleteUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-deleteunicastipaddressentry)

[GetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddressentry)

[GetUnicastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getunicastipaddresstable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

[MIB_UNICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_row)

[MIB_UNICASTIPADDRESS_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_unicastipaddress_table)

[NotifyUnicastIpAddressChange](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-notifyunicastipaddresschange)

[SetUnicastIpAddressEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setunicastipaddressentry)