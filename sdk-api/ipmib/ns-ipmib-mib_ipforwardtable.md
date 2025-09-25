# MIB_IPFORWARDTABLE structure

## Description

The
**MIB_IPFORWARDTABLE** structure contains a table of IPv4 route entries.

## Members

### `dwNumEntries`

The number of route entries in the table.

### `table`

A pointer to a table of route entries implemented as an array of
[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structures.

## Remarks

The [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) function enumerates the IPv4 route entries on a local system and returns this information in a **MIB_IPFORWARDTABLE** structure.

The **MIB_IPFORWARDTABLE** structure may contain padding for alignment between the **dwNumEntries** member and the first [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) array entry in the **table** member. Padding for alignment may also be present between the **MIB_IPFORWARDROW** array entries in the **table** member. Any access to a **MIB_IPFORWARDROW** array entry should assume padding may exist.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed. This structure is defined in the *Ipmib.h* header file, not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h*, which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

#### Examples

To view an example that retrieves the **MIB_IPFORWARDTABLE** structure and then prints out the [MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow) structure entries in this table, see the [GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable) function.

## See also

[GetIpForwardTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipforwardtable)

[MIB_IPFORWARDNUMBER](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardnumber)

[MIB_IPFORWARDROW](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipforwardrow)