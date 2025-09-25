# MIB_IFSTACK_ROW structure

## Description

The
**MIB_IFSTACK_ROW** structure represents the relationship between two network interfaces.

## Members

### `HigherLayerInterfaceIndex`

The network interface index for the interface that is higher in the interface stack table.

### `LowerLayerInterfaceIndex`

The network interface index for the interface that is lower in the interface stack table.

## Remarks

The **MIB_IFSTACK_ROW** structure is defined in Windows Vista and later.

The relationship between the interfaces in the interface stack is that the interface with index in the **HigherLayerInterfaceIndex** member is immediately above the interface with index in the **LowerLayerInterfaceIndex** member.

Note that the *Netioapi.h* header file is automatically included in the *Iphlpapi.h* header file. The *Netioapi.h* header file should never be used directly.

## See also

[GetIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getifstacktable)

[GetInvertedIfStackTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getinvertedifstacktable)

[MIB_IFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ifstack_table)

[MIB_INVERTEDIFSTACK_ROW](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_row)

[MIB_INVERTEDIFSTACK_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_invertedifstack_table)