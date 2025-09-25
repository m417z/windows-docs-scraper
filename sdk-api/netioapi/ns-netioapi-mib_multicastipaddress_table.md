# MIB_MULTICASTIPADDRESS_TABLE structure

## Description

The
**MIB_MULTICASTIPADDRESS_TABLE** structure contains a table of multicast IP address entries.

## Members

### `NumEntries`

A value that specifies the number of multicast IP address entries in the array.

### `Table`

An array of
[MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) structures containing multicast IP address entries.

## Remarks

The **MIB_MULTICASTIPADDRESS_TABLE** structure is defined on Windows Vista and later.

The [GetMulticastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddresstable) function enumerates the multicast IP addresses on a local system and returns this information in an **MIB_MULTICASTIPADDRESS_TABLE** structure.

The **MIB_MULTICASTIPADDRESS_TABLE** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_MULTICASTIPADDRESS_ROW** array entries in the **Table** member. Any access to a **MIB_MULTICASTIPADDRESS_ROW** array entry should assume padding may exist.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetMulticastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getmulticastipaddresstable)

[MIB_MULTICASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_multicastipaddress_row)