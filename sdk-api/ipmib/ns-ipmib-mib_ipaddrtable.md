# MIB_IPADDRTABLE structure

## Description

The
**MIB_IPADDRTABLE** structure contains a table of IPv4 address entries.

## Members

### `dwNumEntries`

The number of IPv4 address entries in the table.

### `table`

A pointer to a table of IPv4 address entries implemented as an array of
[MIB_IPADDRROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrrow_w2k) structures.

## Remarks

The [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) function retrieves the interface–to–IPv4 address mapping table on a local computer and returns this information in an **MIB_IPADDRTABLE** structure.

The **MIB_IPADDRTABLE** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_IPADDRROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrrow_w2k) array entry in the **table** member. Padding for alignment may also be present between the **MIB_IPADDRROW** array entries in the **table** member. Any access to a **MIB_IPADDRROW** array entry should assume padding may exist.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the [MIB_IPADDRROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrrow_w2k) is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

#### Examples

To view an example that retrieves the **MIB_IPADDRTABLE** structure and then prints out the [MIB_IPADDRROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrrow_w2k) structures in this table, see the [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) function.

## See also

[GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable)

[MIB_IPADDRROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrrow_w2k)