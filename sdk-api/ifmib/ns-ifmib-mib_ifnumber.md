# MIB_IFNUMBER structure

## Description

The
**MIB_IFNUMBER** structure stores the number of interfaces on a particular computer.

## Members

### `dwValue`

The number of interfaces on the computer.

## Remarks

The **MIB_IFNUMBER** structure is not currently used. The [MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable) and [MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2) structures contain a **dwNumEntries** member that can be used instead of the **MIB_IFNUMBER** structure.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_IFNUMBER** structure is defined in the *Ifmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ifmib.h* header file is automatically included in *Ipmib.h* header file. This file is automatically included in the *Iprtrmib.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Ifmib.h* header file should never be used directly.

## See also

[MIB_IFTABLE](https://learn.microsoft.com/windows/desktop/api/ifmib/ns-ifmib-mib_iftable)

[MIB_IF_TABLE2](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_if_table2)