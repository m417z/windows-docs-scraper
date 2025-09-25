# MIB_IPNETTABLE structure

## Description

The
**MIB_IPNETTABLE** structure contains a table of Address Resolution Protocol (ARP) entries for IPv4 addresses.

## Members

### `dwNumEntries`

The number of ARP entries in the table.

### `table`

A pointer to a table of ARP entries implemented as an array of
[MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh) structures.

## Remarks

The [GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable) function retrieves the IPv4-to-physical address mapping table.

on a local system and returns this information in a **MIB_IPNETTABLE** structure.

The **dwNumEntries** member in this structure may be zero if there are no ARP entries in the table.

The **MIB_IPNETTABLE** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh) array entry in the **table** member. Padding for alignment may also be present between the **MIB_IPNETROW** array entries in the **table** member. Any access to a **MIB_IPNETROW** array entry should assume padding may exist.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_IPNETTABLE** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[GetIpNetTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipnettable)

[MIB_IPNETROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnetrow_lh)