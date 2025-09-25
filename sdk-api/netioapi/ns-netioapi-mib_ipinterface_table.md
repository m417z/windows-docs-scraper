# MIB_IPINTERFACE_TABLE structure

## Description

The
**MIB_IPINTERFACE_TABLE** structure contains a table of IP interface entries.

## Members

### `NumEntries`

The number of IP interface entries in the array.

### `Table`

An array of
[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structures that contain IP interface entries.

## Remarks

The **MIB_IPINTERFACE_TABLE** structure is defined on Windows Vista and later.

The [GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable) function enumerates the IP interface entries on a local system and returns this information in a **MIB_IPINTERFACE_TABLE** structure.

The **MIB_IPINTERFACE_TABLE** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_IPINTERFACE_ROW** array entries in the **Table** member. Any access to a **MIB_IPINTERFACE_ROW** array entry should assume padding may exist.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

#### Examples

To view an example that retrieves the **MIB_IPINTERFACE_TABLE** structure and then prints out a few members of the [MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row) structure entries in this table, see the [GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable) function.

## See also

[GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable)

[MIB_IPINTERFACE_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_row)