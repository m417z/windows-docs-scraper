# MIB_IPNETROW_W2K structure

## Description

The
**MIB_IPNETROW** structure contains information for an Address Resolution Protocol (ARP) table entry for an IPv4 address.

## Members

### `dwIndex`

Type: **DWORD**

The index of the adapter.

### `dwPhysAddrLen`

Type: **DWORD**

The length, in bytes, of the physical address.

### `bPhysAddr`

Type: **BYTE[MAXLEN_PHYSADDR]**

The physical address.

### `dwAddr`

Type: **DWORD**

The IPv4 address.

### `dwType`

Type: **DWORD**

The type of ARP entry.

This member can be one of the values from the **MIB_IPNET_TYPE** enumeration type defined in the *Ipmib.h* header file included in the Windows SDK released for Windows Vista and later. For use with versions of the earlier Platform SDK, this enumeration is not defined and the constants must be used.

| Value | Meaning |
| --- | --- |
| **MIB_IPNET_TYPE_OTHER**<br><br>1 | Other |
| **MIB_IPNET_TYPE_INVALID**<br><br>2 | An invalid ARP type. This can indicate an unreachable or incomplete ARP entry. |
| **MIB_IPNET_TYPE_DYNAMIC**<br><br>3 | A dynamic ARP type. |
| **MIB_IPNET_TYPE_STATIC**<br><br>4 | A static ARP type. |

## Remarks

On the Windows SDK released for Windows Vista and later, the organization of header files has changed and the **MIB_IPNETROW** structure is defined in the *Ipmib.h* header file not in the *Iprtrmib.h* header file. Note that the *Ipmib.h* header file is automatically included in *Iprtrmib.h* which is automatically included in the *Iphlpapi.h* header file. The *Ipmib.h* and *Iprtrmib.h* header files should never be used directly.

## See also

[CreateIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-createipnetentry)

[DeleteIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-deleteipnetentry)

[MIB_IPNETTABLE](https://learn.microsoft.com/windows/desktop/api/ipmib/ns-ipmib-mib_ipnettable)

[SetIpNetEntry](https://learn.microsoft.com/windows/desktop/api/iphlpapi/nf-iphlpapi-setipnetentry)