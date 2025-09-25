# MIB_IPMCAST_IF_TABLE structure

## Description

The
**MIB_IPMCAST_IF_TABLE** structure contains a table of IP multicast interface entries.

## Members

### `dwNumEntries`

Specifies the number of interface entries in the table.

### `table`

A pointer to a table of interface entries implemented as an array of
**MIB_IPMCAST_IF_TABLE** structures.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_IPMCAST_IF_ENTRY](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_if_entry)