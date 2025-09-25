# MIB_IF_TABLE2 structure

## Description

The
**MIB_IF_TABLE2** structure contains a table of logical and physical interface entries.

## Members

### `NumEntries`

The number of interface entries in the array.

### `Table`

An array of
[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) structures containing interface entries.

## Remarks

The **MIB_IF_TABLE2** structure is defined in Windows Vista and later.

The [GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2) and [GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex) functions enumerates the logical and physical interfaces on a local system and returns this information in a **MIB_IF_TABLE2** structure.

The **MIB_IF_TABLE2** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_IF_ROW2** array entries in the **Table** member. Any access to a **MIB_IF_ROW2** array entry should assume padding may exist.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)