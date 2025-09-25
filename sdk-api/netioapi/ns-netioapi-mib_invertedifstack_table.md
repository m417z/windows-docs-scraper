# MIB_INVERTEDIFSTACK_TABLE structure

## Description

The
**MIB_INVERTEDIFSTACK_TABLE** structure contains a table of inverted network interface stack row entries. This specifies the relationship of the network interfaces on an interface stack in reverse order.

## Members

### `NumEntries`

The number of inverted interface stack row entries in the array.

### `Table`

An array of
[MIB_INVERTEDIFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_row) structures containing inverted interface stack row entries.

## Remarks

The **MIB_INVERTEDIFSTACK_TABLE** structure is defined on Windows Vista and later.

The relationship between the interfaces in the interface stack is that the interface with index in the **HigherLayerInterfaceIndex** member of the [MIB_INVERTEDIFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_row) structure is immediately above the interface with index in the **LowerLayerInterfaceIndex** member of the **MIB_INVERTEDIFSTACK_ROW** structure.

The [GetInvertedIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getinvertedifstacktable) function enumerates the inverted network interface stack row entries on a local system and returns this information in a **MIB_INVERTEDIFSTACK_TABLE** structure.

The **MIB_INVERTEDIFSTACK_TABLE** structure may contain padding for alignment between the **NumEntries** member and the first [MIB_INVERTEDIFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_row) array entry in the **Table** member. Padding for alignment may also be present between the **MIB_INVERTEDIFSTACK_ROW** array entries in the **Table** member. Any access to a **MIB_INVERTEDIFSTACK_ROW** array entry should assume padding may exist.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifstacktable)

[GetInvertedIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getinvertedifstacktable)

[MIB_IFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_row)

[MIB_IFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_table)

[MIB_INVERTEDIFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_row)