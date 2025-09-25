## Description

The
**MIB_IPADDRROW** specifies information for a particular IPv4 address in the [MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable) structure.

## Members

### `dwAddr`

Type: **DWORD**

The IPv4 address in network byte order.

### `dwIndex`

Type: **DWORD**

The index of the interface associated with this IPv4 address.

### `dwMask`

Type: **DWORD**

The subnet mask for the IPv4 address in network byte order.

### `dwBCastAddr`

Type: **DWORD**

The broadcast address in network byte order. A broadcast address is typically the IPv4 address with the host portion set to either all zeros or all ones.

The proper value for this member is not returned by the [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) function.

### `dwReasmSize`

Type: **DWORD**

The maximum re-assembly size for received datagrams.

### `unused1`

Type: **unsigned short**

This member is reserved.

### `unused2`

Type: **unsigned short**

This member is reserved.
## Remarks

On Windows XP and later, the **dwIndex** member of the **MIB_IPADDRROW** structure has a data type of **IF_INDEX**. The **wType** member is only available on Windows XP and later. On Windows 2000 and earlier, this member is defined as **Unused2**.

The [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) function retrieves the interface–to–IPv4 address mapping table on a local computer and returns this information in an [MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable) structure. The **table** member in the **MIB_IPADDRTABLE** structure contains an array of **MIB_IPADDRROW** entries.

On the Microsoft Windows Software Development Kit (SDK) released for Windows Vista and later, the organization of header files has changed and the **MIB_IPADDRROW** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## Examples

To view an example that retrieves the [MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable) structure and then prints out the **MIB_IPADDRROW** structures in this table, see the [GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable) function.

## See also

[GetIpAddrTable](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-getipaddrtable)

[MIB_IPADDRTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipaddrtable)