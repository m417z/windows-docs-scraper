# MIB_IFTABLE structure

## Description

The
**MIB_IFTABLE** structure contains a table of interface entries.

## Members

### `dwNumEntries`

The number of interface entries in the array.

### `table`

An array of
[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) structures containing interface entries.

## Remarks

The [GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable) function enumerates the interface entries on a local system and returns this information in a **MIB_IFTABLE** structure.

The **MIB_IFTABLE** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow) array entry in the **table** member. Padding for alignment may also be present between the **MIB_IFROW** array entries in the **table** member. Any access to a **MIB_IFROW** array entry should assume padding may exist.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_IFTABLE** structure is defined in the *Ifmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ifmib.h* header file is automatically included in *Ipmib.h* header file. This file is automatically included in the *Iprtrmib.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Ifmib.h* header file should never be used directly.

## See also

[GetIfTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getiftable)

[GetIfTable2](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2)

[GetIfTable2Ex](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getiftable2ex)

[MIB_IFNUMBER](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifnumber)

[MIB_IFROW](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_ifrow)

[MIB_IF_ROW2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_row2)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)