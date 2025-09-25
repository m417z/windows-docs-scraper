# MIB_MFE_STATS_TABLE structure

## Description

The
**MIB_MFE_STATS_TABLE** structure stores statistics for a group of Multicast Forwarding Entries (MFEs).

## Members

### `dwNumEntries`

The number of MFEs in the array.

### `table`

A pointer to a table of MFEs that are implemented as an array of
[MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats) structures.

## Remarks

On the Microsoft Windows Software Development Kit (SDK) released for Windows Server 2008and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[MIB_IPMCAST_MFE_STATS](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipmcast_mfe_stats)