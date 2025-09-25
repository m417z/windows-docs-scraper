# MIB_IFSTACK_TABLE structure

## Description

The
**MIB_IFSTACK_TABLE** structure contains a table of network interface stack row entries. This specifies the relationship of the network interfaces on an interface stack.

## Members

### `NumEntries`

The number of interface stack row entries in the array.

### `Table`

An array of
[MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row) structures containing interface stack row entries.

## Remarks

The **MIB_IFSTACK_TABLE** structure is defined in Windows Vista and later.

The relationship between the interfaces in the interface stack is that the interface with index in the **HigherLayerInterfaceIndex** member of the [MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row) structure is immediately above the interface with index in the **LowerLayerInterfaceIndex** member of the **MIB_IFSTACK_ROW** structure.

The [GetIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifstacktable) function enumerates the network interface stack row entries on a local system and returns this information in a **MIB_IFSTACK_TABLE** structure.

The **MIB_IFSTACK_TABLE** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_IFSTACK_ROW** array entries in the **Table** member. Any access to a **MIB_IFSTACK_ROW** array entry should assume padding may exist.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifstacktable)

[GetInvertedIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getinvertedifstacktable)

[MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row)

[MIB_INVERTEDIFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_row)

[MIB_INVERTEDIFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_table)