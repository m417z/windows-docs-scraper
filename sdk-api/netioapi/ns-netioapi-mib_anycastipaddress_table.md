# MIB_ANYCASTIPADDRESS_TABLE structure

## Description

The
**MIB_ANYCASTIPADDRESS_TABLE** structure contains a table of anycast IP address entries.

## Members

### `NumEntries`

A value that specifies the number of anycast IP address entries in the array.

### `Table`

An array of
[MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) structures containing anycast IP address entries.

## Remarks

The **MIB_ANYCASTIPADDRESS_TABLE** structure is defined on Windows Vista and later.

The [GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable) function enumerates the anycast IP addresses on a local system and returns this information in a **MIB_ANYCASTIPADDRESS_TABLE** structure.

The **MIB_ANYCASTIPADDRESS_TABLE** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_ANYCASTIPADDRESS_ROW** array entries in the **Table** member. Any access to a **MIB_ANYCASTIPADDRESS_ROW** array entry should assume padding may exist.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetAnycastIpAddressTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getanycastipaddresstable)

[MIB_ANYCASTIPADDRESS_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_anycastipaddress_row)